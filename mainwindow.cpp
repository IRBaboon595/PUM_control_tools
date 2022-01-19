#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    f_d = new QFileDialog(this);
    f_d->setFileMode(QFileDialog::AnyFile);

    power_ctrl_byte = 0;
    timer_echo = new QTimer();

    prA = new preAmp();
    pwA = new powAmp();

    prA->moveToThread(&thread);
    pwA->moveToThread(&thread);

    thread.start();
    calibrateWin = new QWidget();
    calibrateWin->setWindowTitle("Calibration");
    calInfo = new QLabel("Write FIRST input power:");
    calButton = new QPushButton("Set");
    calLineEdit = new QLineEdit();
    QHBoxLayout *local_layout = new QHBoxLayout();
    local_layout->addWidget(calButton);
    local_layout->addWidget(calLineEdit);
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(calInfo);
    layout->addLayout(local_layout);
    calibrateWin->setLayout(layout);

    ui->input_lcdNumber->setSegmentStyle(QLCDNumber::Flat);
    ui->input_lcdNumber->setDecMode();
    ui->outputINC_lcdNumber->setSegmentStyle(QLCDNumber::Flat);
    ui->outputINC_lcdNumber->setDecMode();
    ui->outputREF_lcdNumber->setSegmentStyle(QLCDNumber::Flat);
    ui->outputREF_lcdNumber->setDecMode();

    ui->att_address_combo->addItem("Address 0x00");
    ui->att_address_combo->addItem("Address 0x01");
    ui->att_address_combo->addItem("Address 0x02");

    strobePulse = 3;
    strobeDuty = 0.1;
    strobePause = (strobePulse / strobeDuty - strobePulse);
    calIterator = 0;
    calTimer = new QTimer();

    COM = new QSerialPort(this);
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
            ui->com_combobox->addItem(info.portName());

    connect(ui->com_button, SIGNAL(clicked(bool)), this, SLOT(connectCOM()));
    connect(ui->echo_button, SIGNAL(clicked(bool)), this, SLOT(getEcho()));
    connect(timer_echo, SIGNAL(timeout()), this, SLOT(timer_echo_timeout()));
    connect(ui->supply_ctrl_send_pushbutton, SIGNAL(clicked(bool)), this, SLOT(power_ctrl_Data()));
    connect(ui->UM78_supply_pushbutton, SIGNAL(clicked(bool)), this, SLOT(UM78_power_ctrl_Data()));
    connect(ui->att_slider, SIGNAL(valueChanged(int)), this, SLOT(selectAtt()));
    connect(ui->att_line_edit, SIGNAL(editingFinished()), this, SLOT(writeAtt()));
    connect(ui->att_ctrl_pushbutton, SIGNAL(clicked(bool)), this, SLOT(setAttenuation()));
    connect(ui->gate_slider, SIGNAL(valueChanged(int)), this, SLOT(selectGateVoltage()));
    connect(ui->gate_line_edit, SIGNAL(editingFinished()), this, SLOT(writeGateVoltage()));
    connect(ui->gate_push_button, SIGNAL(clicked(bool)), this, SLOT(setGateVoltage()));
    connect(ui->setup_gate_voltage, SIGNAL(clicked(bool)), this, SLOT(gate_turn_on()));

    connect(ui->UM78_gate_slider, SIGNAL(valueChanged(int)), this, SLOT(UM78_selectGateVoltage()));
    connect(ui->UM78_gate_line_edit, SIGNAL(editingFinished()), this, SLOT(UM78_writeGateVoltage()));
    connect(ui->UM78_gate_push_button, SIGNAL(clicked(bool)), this, SLOT(UM78_setGateVoltage()));
    connect(ui->UM78_setup_gate_voltage, SIGNAL(clicked(bool)), this, SLOT(UM78_gate_turn_on()));

    connect(ui->Vd_checkbox, SIGNAL(clicked(bool)), this, SLOT(drain_gate_ctrl()));
    connect(ui->UM78_Vd_checkbox, SIGNAL(clicked(bool)), this, SLOT(UM78_drain_gate_ctrl()));
    connect(ui->actionCalibrate, SIGNAL(triggered()), this, SLOT(calibratePower()));
    connect(COM, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(calTimer, SIGNAL(timeout()), this, SLOT(on_getPower_button_clicked()));
    connect(calButton, SIGNAL(clicked()), this, SLOT(setCalParam()));
    connect(ui->stopPowButton, SIGNAL(clicked()), this, SLOT(stopPow()));
    connect(ui->compPR_slider, SIGNAL(valueChanged(int)), this, SLOT(selectCompDACLevelPra()));
    connect(ui->compPR_lineedit, SIGNAL(editingFinished()), this, SLOT(writeCompDACLevelPra()));
    connect(ui->compPR_pushbutton, SIGNAL(clicked()), this, SLOT(setCompDACPra()));
    connect(ui->compPA_slider, SIGNAL(valueChanged(int)), this, SLOT(selectCompDACLevelPwa()));
    connect(ui->compPA_lineedit, SIGNAL(editingFinished()), this, SLOT(writeCompDACLevelPwa()));
    connect(ui->compPA_pushbutton, SIGNAL(clicked()), this, SLOT(setCompDACPwa()));
}

/**************************************** Service Functions ****************************************/

void MainWindow::connectCOM(void)
{
    if(COM->portName() != ui->com_combobox->currentText())
    {
        COM->close();
        COM->setPortName(ui->com_combobox->currentText());
    }

    COM->setBaudRate(QSerialPort::Baud115200, QSerialPort::AllDirections);
    COM->setDataBits(QSerialPort::Data8);
    COM->setParity(QSerialPort::NoParity);
    COM->setStopBits(QSerialPort::OneStop);
    COM->setFlowControl(QSerialPort::NoFlowControl);
    COM->setReadBufferSize(0);
    if(COM->open(QSerialPort::ReadWrite))
    {
        ui->comstate_label->setText("<FONT COLOR=#008000>Opened</FONT>");
        com_mode = 1;
        ui->com_button->setText("Close port");
    }
    else
    {
        COM->close();
        ui->comstate_label->setText("<FONT COLOR=red>Closed</FONT>");
        ui->com_button->setText("Open port");
        com_mode = 0;
    }
}

/***************************************** Control Functions *********************************************/

void MainWindow::getEcho(void)
{
    QByteArray ba_1;
    char len = 0x06;
    char crc = 0;
    char echo = ECHO;
    ba_1.append(SYNCHRO);
    ba_1.append(char(0x00));
    ba_1.append(len);
    ba_1.append(UART_ADDR);
    ba_1.append(echo);
    for(int i = 0; i < ba_1.size(); i++)
    {
        crc ^= ba_1.at(i);
    }
    ba_1.append(crc);
    if(COM->write(ba_1) != -1)
    {
        COM->waitForBytesWritten(200);
        COM->waitForReadyRead(300);
    }
    //timer_echo->start(2000);
}

void MainWindow::timer_echo_timeout()
{
    ui->service_message->setText("Empty");
}

void MainWindow::on_com_refresh_button_clicked()
{
    ui->com_combobox->clear();
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
            ui->com_combobox->addItem(info.portName());
}

void MainWindow::readData(void)
{
    char temp = 0;
    bool trigger = true;
    std_union len;
    len.istd = 0;
    double num = 0;
    std_union powTemp;
    powTemp.istd = 0;

    qDebug() << "ReadyRead_Got";
    ba.append(COM->readAll());
    qDebug() << ba.size();
    int idx = ba.indexOf(SYNCHRO, 0);
    if(idx >= 0)
    {
        qDebug() << "Synchro byte found";
        if(idx > 0)
        {
            ba.remove(0,idx);
            idx = 0;
        }
        while((ba.size() >= 6) && (trigger))
        {
            qDebug() << "Potential parcel len achieved";
            len.cstd[1] = uint8_t(ba[1]);
            len.cstd[0] = uint8_t(ba[2]);
            qDebug() << len.istd;
            temp = ba[3];
            if(temp == UART_ADDR)
            {
                qDebug() << "Address achieved";
                for(uint i = 0; i < len.istd; i++)
                {
                    CRC ^= ba[i];
                }
                if(CRC == 0)
                {
                    qDebug() << "XOR approved";
                    temp = ba[4];
                    switch (temp)
                    {
                    case ECHO:
                        ui->service_message->setText("Echo Got");
                        timer_echo->start(1000);
                        uart_command = 0;
                        break;
                    case SUPPLY_CTRL:

                        break;
                    case GET_POWER:
                        powTemp.cstd[1] = uint8_t(ba[5]);
                        powTemp.cstd[0] = uint8_t(ba[6]);
                        num = powTemp.istd * 2.048;
                        num /= 4096;
                        num -= struct_temp_input.b_coef;
                        num /= struct_temp_input.k_coef;
                        ui->input_lcdNumber->display(num);

                        powTemp.cstd[1] = uint8_t(ba[7]);
                        powTemp.cstd[0] = uint8_t(ba[8]);
                        num = powTemp.istd * 2.048;
                        num /= 4096;
                        ui->outputINC_lcdNumber->display(num);
                        powTemp.cstd[1] = uint8_t(ba[9]);
                        powTemp.cstd[0] = uint8_t(ba[10]);
                        num = powTemp.istd * 2.048;
                        num /= 4096;
                        ui->outputREF_lcdNumber->display(num);
                        /*ui->getPower_button->setEnabled(true);
                        ui->getPower_button->setDisabled(false);*/
                        break;
                    case CAL_POWER:
                        powTemp.cstd[1] = uint8_t(ba[5]);
                        powTemp.cstd[0] = uint8_t(ba[6]);
                        num = powTemp.istd * 2.048;
                        num /= 4096;
                        ui->input_lcdNumber->display(num);
                        switch (calIterator) {
                        case 0:
                            struct_temp_input.voltage_1 = num;
                            calIterator++;
                            break;
                        case 1:
                            struct_temp_input.voltage_2 = num;                            
                            struct_temp_input.k_coef = (struct_temp_input.voltage_2 - struct_temp_input.voltage_1) / (struct_temp_input.power_2 - struct_temp_input.power_1);
                            struct_temp_input.b_coef = struct_temp_input.voltage_1 - struct_temp_input.k_coef * struct_temp_input.power_1;

                            calibrateWin->close();
                            calTimer->start(2000);
                            calIterator = 0;
                            calInfo->setText("Write FIRST input power: ");
                            break;
                        default:
                            calInfo->setText("Error - try again");
                            qDebug() << "Iterator error";
                            break;
                        }
                        break;
                    default:

                        uart_command = 255;
                        timer_1->start();
                        break;
                    }
                    trigger = false;
                    ba.clear();
                }
                else
                {
                    qDebug() << "XOR error";
                    idx = ba.indexOf(SYNCHRO, 1);
                    int bad_len = idx;
                    ba.remove(0, bad_len);
                }

            }
            else
            {
                qDebug() << "Address error";
                idx = ba.indexOf(SYNCHRO, 1);
                int bad_len = idx;
                ba.remove(0, bad_len);
            }
        }
    }
    else
    {
        qDebug() << "No Synchro";
        ba.clear();
    }
    CRC = 0;
}

/**************************************** Supply control ***********************************************/

void MainWindow::power_ctrl_Data(void)
{
    QByteArray ba_1;
    char len = 0x08;
    char crc = 0;
    char data = 0;

    prA->setSup(prA->PLUS_5V, ui->plus_5_checkbox->isChecked());
    prA->setSup(prA->PLUS_5VRF, ui->HMC_checkbox->isChecked());
    prA->setSup(prA->MINUS_5V, ui->minus_5_checkbox->isChecked());
    prA->setSup(prA->PLUS_3_3V, ui->plus_3_checkbox->isChecked());
    prA->setSup(prA->PLUS_28V, ui->plus_28_checkbox->isChecked());
    prA->setSup(prA->PLUS_2_5V, ui->plus_2_5_checkbox->isChecked());
    prA->setSup(prA->Vd, ui->Vd_checkbox->isChecked());


    if(prA->getSup(prA->PLUS_5V))
    {
        data |= 0x80;
    }
    else
    {
        data &=~ 0x80;
    }
    if(prA->getSup(prA->PLUS_28V))
    {
        data |= 0x40;
    }
    else
    {
        data &=~ 0x40;
    }
    if(prA->getSup(prA->MINUS_5V))
    {
        data |= 0x20;
    }
    else
    {
        data &=~ 0x20;
    }
    if(prA->getSup(prA->PLUS_3_3V))
    {
        data |= 0x10;
    }
    else
    {
        data &=~ 0x10;
    }
    if(prA->getSup(prA->PLUS_2_5V))
    {
        data |= 0x08;
    }
    else
    {
        data &=~ 0x08;
    }
    if(prA->getSup(prA->PLUS_5VRF))
    {
        data &=~ 0x04;
    }
    else
    {
        data |= 0x04;
    }
    if(prA->getSup(prA->Vd))
    {
        data |= 0x02;
        pwA->setSup(pwA->Vd, true);
    }
    else
    {
        data &=~ 0x02;
        pwA->setSup(pwA->Vd, false);
    }


    ba_1.append(SYNCHRO);
    ba_1.append(char(0x00));
    ba_1.append(len);
    ba_1.append(UART_ADDR);
    ba_1.append(SUPPLY_CTRL);
    ba_1.append(data);
    ba_1.append(UM10_AMP);
    for(int i = 0; i < ba_1.size(); i++)
    {
        crc ^= ba_1.at(i);
    }
    ba_1.append(crc);
    qDebug() << ba_1;
    COM->write(ba_1);
    while(!COM->waitForBytesWritten(-1));           //Если слать в закрытый порт будет зависание
    COM->waitForReadyRead(100);

}

void MainWindow::UM78_power_ctrl_Data(void)
{
    QByteArray ba_1;
    char len = 0x08;
    char crc = 0;
    char data = 0;

    pwA->setSup(pwA->PLUS_5VRF, ui->plus_5_UM78_checkbox->isChecked());
    pwA->setSup(pwA->MINUS_5V, ui->minus_5_UM78_checkbox->isChecked());
    pwA->setSup(pwA->PLUS_3_3V, ui->plus_3_UM78_checkbox->isChecked());
    pwA->setSup(pwA->PLUS_2_5V, ui->plus_2_5_checkbox->isChecked());
    pwA->setSup(pwA->Vd, ui->UM78_Vd_checkbox->isChecked());

    if(pwA->getSup(pwA->PLUS_5VRF))
    {
        data |= 0x80;
    }
    else
    {
        data &=~ 0x80;
    }
    if(pwA->getSup(pwA->MINUS_5V))
    {
        data |= 0x40;
    }
    else
    {
        data &=~ 0x40;
    }
    if(pwA->getSup(pwA->PLUS_3_3V))
    {
        data |= 0x20;
    }
    else
    {
        data &=~ 0x20;
    }
    if(pwA->getSup(pwA->PLUS_2_5V))
    {
        data |= 0x10;
    }
    else
    {
        data &=~ 0x10;
    }
    if(pwA->getSup(pwA->Vd))
    {
        data |= 0x02;
        prA->setSup(prA->Vd, true);
    }
    else
    {
        data &=~ 0x02;
        prA->setSup(prA->Vd, false);
    }

    ba_1.append(SYNCHRO);
    ba_1.append(char(0x00));
    ba_1.append(len);
    ba_1.append(UART_ADDR);
    ba_1.append(SUPPLY_CTRL);
    ba_1.append(data);
    ba_1.append(UM78_AMP);
    for(int i = 0; i < ba_1.size(); i++)
    {
        crc ^= ba_1.at(i);
    }
    ba_1.append(crc);
    qDebug() << ba_1;
    COM->write(ba_1);
    while(!COM->waitForBytesWritten(-1));           //Если слать в закрытый порт будет зависание
    COM->waitForReadyRead(100);
}

void MainWindow::drain_gate_ctrl(void)
{
    if(ui->Vd_checkbox->isChecked())
    {
        ui->UM78_Vd_checkbox->setCheckState(Qt::Checked);
    }
    else
    {
        ui->UM78_Vd_checkbox->setCheckState(Qt::Unchecked);
    }
}

void MainWindow::UM78_drain_gate_ctrl(void)
{
    if(ui->UM78_Vd_checkbox->isChecked())
    {
        ui->Vd_checkbox->setCheckState(Qt::Checked);
    }
    else
    {
        ui->Vd_checkbox->setCheckState(Qt::Unchecked);
    }
}

/**************************************** Attenuator control ***********************************************/

void MainWindow::setAttenuation(void)
{
    QByteArray ba_1;
    char len = 0x08;
    char crc = 0x00;
    char data_1 = 0x00;                         //ADDRESS
    char data_2 = 0x00;                         //DATA

    data_2 = char(prA->getAtt() * 2);
    ba_1.append(SYNCHRO);
    ba_1.append(char(0x00));
    ba_1.append(len);
    ba_1.append(UART_ADDR);
    ba_1.append(ATT_CTRL);
    ba_1.append(data_1);
    ba_1.append(data_2);
    for(int i = 0; i < ba_1.size(); i++)
    {
        crc ^= ba_1.at(i);
    }
    ba_1.append(crc);
    qDebug() << ba_1;
    COM->write(ba_1);
    while(!COM->waitForBytesWritten(-1));
    COM->waitForReadyRead(100);
}

void MainWindow::selectAtt(void)
{
    float temp = ui->att_slider->value();
    temp /= 2;
    prA->setAtt(temp);
    ui->att_line_edit->setText(QString::number(double(temp)));
}

void MainWindow::writeAtt(void)
{
    QString string(ui->att_line_edit->text());
    prA->setAtt(string.toFloat());
}

/**************************************** Comparator DAC control *********************************************/

void MainWindow::setCompDACPra()
{
    QByteArray ba_1;
    char len = 0x09;
    char crc = 0;
    std_union gate_temp;

    gate_temp.istd = uint16_t(prA->getCompDacLevel() * 1000);
    ba_1.append(SYNCHRO);
    ba_1.append(char(0x00));
    ba_1.append(len);
    ba_1.append(UART_ADDR);
    ba_1.append(COMP_DAC);
    ba_1.append(char(gate_temp.cstd[1]));
    ba_1.append(char(gate_temp.cstd[0]));
    ba_1.append(char(CHANNEL_PRA));
    for(int i = 0; i < ba_1.size(); i++)
    {
        crc ^= ba_1.at(i);
    }
    ba_1.append(crc);
    COM->write(ba_1);
    while(!COM->waitForBytesWritten(-1));
    COM->waitForReadyRead(100);
}

void MainWindow::selectCompDACLevelPra()
{
    double temp = ui->compPR_slider->value();
    prA->setCompDacLevel(temp / 1000);
    ui->compPR_lineedit->setText(QString::number(prA->getCompDacLevel()));
}

void MainWindow::writeCompDACLevelPra()
{
    QString string(ui->compPR_lineedit->text());
    prA->setCompDacLevel(string.toDouble());
}

void MainWindow::setCompDACPwa()
{
    QByteArray ba_1;
    char len = 0x09;
    char crc = 0;
    std_union gate_temp;

    gate_temp.istd = uint16_t(pwA->getCompDacLevel() * 1000);
    ba_1.append(SYNCHRO);
    ba_1.append(char(0x00));
    ba_1.append(len);
    ba_1.append(UART_ADDR);
    ba_1.append(COMP_DAC);
    ba_1.append(char(gate_temp.cstd[1]));
    ba_1.append(char(gate_temp.cstd[0]));
    ba_1.append(char(CHANNEL_PWA));
    for(int i = 0; i < ba_1.size(); i++)
    {
        crc ^= ba_1.at(i);
    }
    ba_1.append(crc);
    COM->write(ba_1);
    while(!COM->waitForBytesWritten(-1));
    COM->waitForReadyRead(100);
}

void MainWindow::selectCompDACLevelPwa()
{
    double temp = ui->compPA_slider->value();
    pwA->setCompDacLevel(temp / 1000);
    ui->compPA_lineedit->setText(QString::number(pwA->getCompDacLevel()));
}

void MainWindow::writeCompDACLevelPwa()
{
    QString string(ui->compPA_lineedit->text());
    pwA->setCompDacLevel(string.toDouble());
}

/**************************************** PreAmp Gate control *********************************************/

void MainWindow::setGateVoltage(void)
{
    QByteArray ba_1;
    char len = 0x09;
    char crc = 0;
    std_union gate_temp;

    gate_temp.istd = uint16_t(prA->getGateLevel() * 1000 + 7500);
    ba_1.append(SYNCHRO);
    ba_1.append(char(0x00));
    ba_1.append(len);
    ba_1.append(UART_ADDR);
    ba_1.append(DAC_CTRL);
    ba_1.append(char(gate_temp.cstd[1]));
    ba_1.append(char(gate_temp.cstd[0]));
    ba_1.append(UM10_DAC);
    for(int i = 0; i < ba_1.size(); i++)
    {
        crc ^= ba_1.at(i);
    }
    ba_1.append(crc);
    qDebug() << ba_1;
    COM->write(ba_1);
    while(!COM->waitForBytesWritten(-1));
    COM->waitForReadyRead(100);
}

void MainWindow::selectGateVoltage(void)
{
    double temp = ui->gate_slider->value();
    prA->setGateLevel((-7500 + temp)/1000);
    ui->gate_line_edit->setText(QString::number(prA->getGateLevel()));
}

void MainWindow::writeGateVoltage(void)
{
    QString string(ui->gate_line_edit->text());
    prA->setGateLevel(string.toDouble());
}

void MainWindow::gate_turn_on(void)
{
    QByteArray ba_1;
    char len = 0x08;
    char crc = 0;
    char data = 0;
    if(ui->setup_gate_voltage->text() == "Power ON")
    {
        power_ctrl_byte |= 0x01;
        ui->setup_gate_voltage->setText("Power OFF");
    }
    else if(ui->setup_gate_voltage->text() == "Power OFF")
    {
        power_ctrl_byte &=~ 0x01;
        ui->setup_gate_voltage->setText("Power ON");
    }

    data = char(power_ctrl_byte);
    ba_1.append(SYNCHRO);
    ba_1.append(char(0x00));
    ba_1.append(len);
    ba_1.append(UART_ADDR);
    ba_1.append(SUPPLY_CTRL);
    ba_1.append(data);
    ba_1.append(UM10_AMP);
    for(int i = 0; i < ba_1.size(); i++)
    {
        crc ^= ba_1.at(i);
    }
    ba_1.append(crc);
    qDebug() << ba_1;
    COM->write(ba_1);
    while(!COM->waitForBytesWritten(-1));           //Если слать в закрытый порт будет зависание
    COM->waitForReadyRead(100);
}

/*************************************** PowAmp Gate control **********************************************/

void MainWindow::UM78_setGateVoltage(void)
{
    QByteArray ba_1;
    char len = 0x09;
    char crc = 0;
    std_union gate_temp;

    gate_temp.istd = uint16_t(pwA->getGateLevel() * 1000 + 7500);
    ba_1.append(SYNCHRO);
    ba_1.append(char(0x00));
    ba_1.append(len);
    ba_1.append(UART_ADDR);
    ba_1.append(DAC_CTRL);
    ba_1.append(char(gate_temp.cstd[1]));
    ba_1.append(char(gate_temp.cstd[0]));
    ba_1.append(UM78_DAC);
    for(int i = 0; i < ba_1.size(); i++)
    {
        crc ^= ba_1.at(i);
    }
    ba_1.append(crc);
    qDebug() << ba_1;
    COM->write(ba_1);
    while(!COM->waitForBytesWritten(-1));
    COM->waitForReadyRead(100);
}

void MainWindow::UM78_selectGateVoltage(void)
{
    double temp = ui->UM78_gate_slider->value();
    pwA->setGateLevel((-7500 + temp)/1000);
    ui->UM78_gate_line_edit->setText(QString::number(pwA->getGateLevel()));
}

void MainWindow::UM78_writeGateVoltage(void)
{
    QString string(ui->UM78_gate_line_edit->text());
    pwA->setGateLevel(string.toDouble());
}

void MainWindow::UM78_gate_turn_on(void)
{
    QByteArray ba_1;
    char len = 0x08;
    char crc = 0;
    char data = 0;
    if(ui->UM78_setup_gate_voltage->text() == "Power ON")
    {
        power_ctrl_byte_UM78 |= 0x04;
        ui->UM78_setup_gate_voltage->setText("Power OFF");
    }
    else if(ui->UM78_setup_gate_voltage->text() == "Power OFF")
    {
        power_ctrl_byte_UM78 &=~ 0x04;
        ui->UM78_setup_gate_voltage->setText("Power ON");
    }

    data = char(power_ctrl_byte_UM78);
    ba_1.append(SYNCHRO);
    ba_1.append(char(0x00));
    ba_1.append(len);
    ba_1.append(UART_ADDR);
    ba_1.append(SUPPLY_CTRL);
    ba_1.append(data);
    ba_1.append(UM78_AMP);
    for(int i = 0; i < ba_1.size(); i++)
    {
        crc ^= ba_1.at(i);
    }
    ba_1.append(crc);
    qDebug() << ba_1;
    COM->write(ba_1);
    while(!COM->waitForBytesWritten(-1));           //Если слать в закрытый порт будет зависание
    COM->waitForReadyRead(100);
}

void MainWindow::on_pulseWid_lineedit_editingFinished()
{
    strobePulse = ui->pulseWid_lineedit->text().toDouble();
}

void MainWindow::on_dutyCycle_lineedit_editingFinished()
{
    strobeDuty = (ui->dutyCycle_lineedit->text().toDouble() / 100);
}

void MainWindow::on_strobPushButton_clicked()
{
    QByteArray ba_1;
    char len = 0x0C;
    char crc = 0;
    char data_1 = 0;
    char data_2 = 0;
    char data_3 = 0;
    char data_4 = 0;
    char data_5 = 0;
    char data_6 = 0;
    std_union temp;
    temp.istd = 0;

    uint16_t pulse = uint16_t(strobePulse * 100);
    uint16_t pause = uint16_t((strobePulse / strobeDuty - strobePulse) * 100);


    if(ui->strobe_checkbox->isChecked())
    {
        data_2 = ON;
    }
    else
    {
        data_2 = OFF;
    }
    temp.istd = pulse;
    data_3 = char(temp.cstd[1]);
    data_4 = char(temp.cstd[0]);
    temp.istd = pause;
    data_5 = char(temp.cstd[1]);
    data_6 = char(temp.cstd[0]);


    ba_1.append(SYNCHRO);
    ba_1.append(char(0x00));
    ba_1.append(len);
    ba_1.append(UART_ADDR);
    ba_1.append(STROBE_CTRL);
    ba_1.append(data_1);
    ba_1.append(data_2);
    ba_1.append(data_3);
    ba_1.append(data_4);
    ba_1.append(data_5);
    ba_1.append(data_6);
    for(int i = 0; i < ba_1.size(); i++)
    {
        crc ^= ba_1.at(i);
    }
    ba_1.append(crc);
    if(COM->write(ba_1) != -1)
    {
        COM->waitForBytesWritten(200);
        COM->waitForReadyRead(300);
    }
}

void MainWindow::on_getPower_button_clicked()
{
    QByteArray ba_1;
    char len = 0x06;
    char crc = 0;

    //ui->getPower_button->setEnabled(false);
    ba_1.append(SYNCHRO);
    ba_1.append(char(0x00));
    ba_1.append(len);
    ba_1.append(UART_ADDR);
    ba_1.append(GET_POWER);
    for(int i = 0; i < ba_1.size(); i++)
    {
        crc ^= ba_1.at(i);
    }
    ba_1.append(crc);
    if(COM->write(ba_1) != -1)
    {
        COM->waitForBytesWritten(200);
        COM->waitForReadyRead(300);
    }
}

void MainWindow::calibrationGetData()
{
    QByteArray ba_1;
    char len = 0x06;
    char crc = 0;

    //ui->getPower_button->setEnabled(false);
    ba_1.append(SYNCHRO);
    ba_1.append(char(0x00));
    ba_1.append(len);
    ba_1.append(UART_ADDR);
    ba_1.append(CAL_POWER);
    for(int i = 0; i < ba_1.size(); i++)
    {
        crc ^= ba_1.at(i);
    }
    ba_1.append(crc);
    if(COM->write(ba_1) != -1)
    {
        COM->waitForBytesWritten(200);
        COM->waitForReadyRead(300);
    }
}

void MainWindow::calibratePower()
{
    calibrateWin->show();
}

void MainWindow::setCalParam()
{
    switch (calIterator) {
    case 0:
        struct_temp_input.power_1 = calLineEdit->text().toDouble();
        calInfo->setText("Write SECOND input power: ");
        calibrationGetData();
        break;
    case 1:
        struct_temp_input.power_2 = calLineEdit->text().toDouble();
        calibrationGetData();
        break;
    default:
        calInfo->setText("Error - try again");
        qDebug() << "Iterator error";
        break;
    }
}

void MainWindow::stopPow()
{
    calTimer->stop();
}

MainWindow::~MainWindow()
{
    thread.terminate();
    //calibrateWin->close();
    delete ui;
}
