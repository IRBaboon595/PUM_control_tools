/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCalibrate;
    QWidget *centralwidget;
    QLabel *inputPow_label;
    QGroupBox *com_groupbox;
    QPushButton *com_button;
    QComboBox *com_combobox;
    QLabel *comstate_label;
    QPushButton *echo_button;
    QLabel *service_message;
    QPushButton *com_refresh_button;
    QGroupBox *UM78_supply_group;
    QCheckBox *plus_5_UM78_checkbox;
    QCheckBox *minus_5_UM78_checkbox;
    QCheckBox *plus_3_UM78_checkbox;
    QCheckBox *plus_2_5_UM78_checkbox;
    QPushButton *UM78_supply_pushbutton;
    QCheckBox *UM78_Vd_checkbox;
    QLabel *outputREFpow_label;
    QLCDNumber *input_lcdNumber;
    QGroupBox *preAmp_groupbox;
    QCheckBox *plus_5_checkbox;
    QCheckBox *minus_5_checkbox;
    QCheckBox *plus_3_checkbox;
    QCheckBox *plus_2_5_checkbox;
    QCheckBox *HMC_checkbox;
    QPushButton *supply_ctrl_send_pushbutton;
    QCheckBox *plus_28_checkbox;
    QCheckBox *Vd_checkbox;
    QLCDNumber *outputREF_lcdNumber;
    QGroupBox *UM78_gate_group;
    QSlider *UM78_gate_slider;
    QLineEdit *UM78_gate_line_edit;
    QPushButton *UM78_gate_push_button;
    QPushButton *UM78_setup_gate_voltage;
    QLabel *UM78_drain_current_label;
    QPushButton *UM78_read_drain_current;
    QGroupBox *groupBox_3;
    QSlider *att_slider;
    QLineEdit *att_line_edit;
    QPushButton *att_ctrl_pushbutton;
    QComboBox *att_address_combo;
    QLabel *outputINCpow_label;
    QGroupBox *groupBox_4;
    QSlider *gate_slider;
    QLineEdit *gate_line_edit;
    QPushButton *gate_push_button;
    QPushButton *setup_gate_voltage;
    QLabel *drain_current_label;
    QPushButton *pushButton_6;
    QGroupBox *strobCtrl_groupbox;
    QPushButton *strobPushButton;
    QLineEdit *pulseWid_lineedit;
    QLineEdit *dutyCycle_lineedit;
    QLabel *pulseWid_label;
    QLabel *duty_label;
    QCheckBox *strobe_checkbox;
    QPushButton *stopPowButton;
    QLCDNumber *outputINC_lcdNumber;
    QGroupBox *comparatorGroupBox;
    QSlider *compPR_slider;
    QPushButton *compPR_pushbutton;
    QLineEdit *compPR_lineedit;
    QSlider *compPA_slider;
    QPushButton *compPA_pushbutton;
    QLineEdit *compPA_lineedit;
    QMenuBar *menubar;
    QMenu *menuEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(814, 615);
        actionCalibrate = new QAction(MainWindow);
        actionCalibrate->setObjectName(QString::fromUtf8("actionCalibrate"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        inputPow_label = new QLabel(centralwidget);
        inputPow_label->setObjectName(QString::fromUtf8("inputPow_label"));
        inputPow_label->setGeometry(QRect(570, 390, 141, 16));
        inputPow_label->setAlignment(Qt::AlignCenter);
        com_groupbox = new QGroupBox(centralwidget);
        com_groupbox->setObjectName(QString::fromUtf8("com_groupbox"));
        com_groupbox->setGeometry(QRect(10, 10, 201, 191));
        com_button = new QPushButton(com_groupbox);
        com_button->setObjectName(QString::fromUtf8("com_button"));
        com_button->setGeometry(QRect(100, 30, 91, 21));
        com_combobox = new QComboBox(com_groupbox);
        com_combobox->setObjectName(QString::fromUtf8("com_combobox"));
        com_combobox->setGeometry(QRect(10, 30, 81, 22));
        comstate_label = new QLabel(com_groupbox);
        comstate_label->setObjectName(QString::fromUtf8("comstate_label"));
        comstate_label->setGeometry(QRect(10, 60, 181, 16));
        comstate_label->setAlignment(Qt::AlignCenter);
        echo_button = new QPushButton(com_groupbox);
        echo_button->setObjectName(QString::fromUtf8("echo_button"));
        echo_button->setGeometry(QRect(10, 120, 181, 21));
        service_message = new QLabel(com_groupbox);
        service_message->setObjectName(QString::fromUtf8("service_message"));
        service_message->setGeometry(QRect(10, 150, 181, 16));
        service_message->setAlignment(Qt::AlignCenter);
        com_refresh_button = new QPushButton(com_groupbox);
        com_refresh_button->setObjectName(QString::fromUtf8("com_refresh_button"));
        com_refresh_button->setGeometry(QRect(10, 80, 181, 21));
        UM78_supply_group = new QGroupBox(centralwidget);
        UM78_supply_group->setObjectName(QString::fromUtf8("UM78_supply_group"));
        UM78_supply_group->setGeometry(QRect(560, 240, 201, 111));
        plus_5_UM78_checkbox = new QCheckBox(UM78_supply_group);
        plus_5_UM78_checkbox->setObjectName(QString::fromUtf8("plus_5_UM78_checkbox"));
        plus_5_UM78_checkbox->setGeometry(QRect(10, 30, 51, 19));
        minus_5_UM78_checkbox = new QCheckBox(UM78_supply_group);
        minus_5_UM78_checkbox->setObjectName(QString::fromUtf8("minus_5_UM78_checkbox"));
        minus_5_UM78_checkbox->setGeometry(QRect(60, 30, 51, 19));
        plus_3_UM78_checkbox = new QCheckBox(UM78_supply_group);
        plus_3_UM78_checkbox->setObjectName(QString::fromUtf8("plus_3_UM78_checkbox"));
        plus_3_UM78_checkbox->setGeometry(QRect(100, 30, 51, 19));
        plus_2_5_UM78_checkbox = new QCheckBox(UM78_supply_group);
        plus_2_5_UM78_checkbox->setObjectName(QString::fromUtf8("plus_2_5_UM78_checkbox"));
        plus_2_5_UM78_checkbox->setGeometry(QRect(10, 50, 51, 19));
        UM78_supply_pushbutton = new QPushButton(UM78_supply_group);
        UM78_supply_pushbutton->setObjectName(QString::fromUtf8("UM78_supply_pushbutton"));
        UM78_supply_pushbutton->setGeometry(QRect(10, 80, 181, 21));
        UM78_Vd_checkbox = new QCheckBox(UM78_supply_group);
        UM78_Vd_checkbox->setObjectName(QString::fromUtf8("UM78_Vd_checkbox"));
        UM78_Vd_checkbox->setGeometry(QRect(160, 30, 51, 19));
        outputREFpow_label = new QLabel(centralwidget);
        outputREFpow_label->setObjectName(QString::fromUtf8("outputREFpow_label"));
        outputREFpow_label->setGeometry(QRect(570, 450, 141, 16));
        outputREFpow_label->setAlignment(Qt::AlignCenter);
        input_lcdNumber = new QLCDNumber(centralwidget);
        input_lcdNumber->setObjectName(QString::fromUtf8("input_lcdNumber"));
        input_lcdNumber->setGeometry(QRect(460, 390, 91, 23));
        preAmp_groupbox = new QGroupBox(centralwidget);
        preAmp_groupbox->setObjectName(QString::fromUtf8("preAmp_groupbox"));
        preAmp_groupbox->setGeometry(QRect(220, 240, 201, 111));
        plus_5_checkbox = new QCheckBox(preAmp_groupbox);
        plus_5_checkbox->setObjectName(QString::fromUtf8("plus_5_checkbox"));
        plus_5_checkbox->setGeometry(QRect(10, 30, 51, 19));
        minus_5_checkbox = new QCheckBox(preAmp_groupbox);
        minus_5_checkbox->setObjectName(QString::fromUtf8("minus_5_checkbox"));
        minus_5_checkbox->setGeometry(QRect(60, 30, 51, 19));
        plus_3_checkbox = new QCheckBox(preAmp_groupbox);
        plus_3_checkbox->setObjectName(QString::fromUtf8("plus_3_checkbox"));
        plus_3_checkbox->setGeometry(QRect(100, 30, 51, 19));
        plus_2_5_checkbox = new QCheckBox(preAmp_groupbox);
        plus_2_5_checkbox->setObjectName(QString::fromUtf8("plus_2_5_checkbox"));
        plus_2_5_checkbox->setGeometry(QRect(10, 50, 51, 19));
        HMC_checkbox = new QCheckBox(preAmp_groupbox);
        HMC_checkbox->setObjectName(QString::fromUtf8("HMC_checkbox"));
        HMC_checkbox->setGeometry(QRect(60, 50, 61, 19));
        supply_ctrl_send_pushbutton = new QPushButton(preAmp_groupbox);
        supply_ctrl_send_pushbutton->setObjectName(QString::fromUtf8("supply_ctrl_send_pushbutton"));
        supply_ctrl_send_pushbutton->setGeometry(QRect(10, 80, 141, 21));
        plus_28_checkbox = new QCheckBox(preAmp_groupbox);
        plus_28_checkbox->setObjectName(QString::fromUtf8("plus_28_checkbox"));
        plus_28_checkbox->setGeometry(QRect(120, 50, 61, 19));
        Vd_checkbox = new QCheckBox(preAmp_groupbox);
        Vd_checkbox->setObjectName(QString::fromUtf8("Vd_checkbox"));
        Vd_checkbox->setGeometry(QRect(160, 30, 51, 19));
        outputREF_lcdNumber = new QLCDNumber(centralwidget);
        outputREF_lcdNumber->setObjectName(QString::fromUtf8("outputREF_lcdNumber"));
        outputREF_lcdNumber->setGeometry(QRect(460, 450, 91, 23));
        UM78_gate_group = new QGroupBox(centralwidget);
        UM78_gate_group->setObjectName(QString::fromUtf8("UM78_gate_group"));
        UM78_gate_group->setGeometry(QRect(600, 10, 161, 221));
        UM78_gate_slider = new QSlider(UM78_gate_group);
        UM78_gate_slider->setObjectName(QString::fromUtf8("UM78_gate_slider"));
        UM78_gate_slider->setGeometry(QRect(10, 70, 141, 16));
        UM78_gate_slider->setMinimum(2500);
        UM78_gate_slider->setMaximum(5000);
        UM78_gate_slider->setSliderPosition(2500);
        UM78_gate_slider->setOrientation(Qt::Horizontal);
        UM78_gate_slider->setTickPosition(QSlider::TicksAbove);
        UM78_gate_slider->setTickInterval(1);
        UM78_gate_line_edit = new QLineEdit(UM78_gate_group);
        UM78_gate_line_edit->setObjectName(QString::fromUtf8("UM78_gate_line_edit"));
        UM78_gate_line_edit->setGeometry(QRect(10, 90, 141, 21));
        UM78_gate_push_button = new QPushButton(UM78_gate_group);
        UM78_gate_push_button->setObjectName(QString::fromUtf8("UM78_gate_push_button"));
        UM78_gate_push_button->setGeometry(QRect(10, 120, 141, 21));
        UM78_setup_gate_voltage = new QPushButton(UM78_gate_group);
        UM78_setup_gate_voltage->setObjectName(QString::fromUtf8("UM78_setup_gate_voltage"));
        UM78_setup_gate_voltage->setGeometry(QRect(10, 40, 141, 21));
        UM78_drain_current_label = new QLabel(UM78_gate_group);
        UM78_drain_current_label->setObjectName(QString::fromUtf8("UM78_drain_current_label"));
        UM78_drain_current_label->setGeometry(QRect(10, 150, 141, 20));
        UM78_drain_current_label->setAlignment(Qt::AlignCenter);
        UM78_read_drain_current = new QPushButton(UM78_gate_group);
        UM78_read_drain_current->setObjectName(QString::fromUtf8("UM78_read_drain_current"));
        UM78_read_drain_current->setGeometry(QRect(10, 180, 141, 21));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 220, 201, 151));
        att_slider = new QSlider(groupBox_3);
        att_slider->setObjectName(QString::fromUtf8("att_slider"));
        att_slider->setGeometry(QRect(10, 30, 181, 16));
        att_slider->setMaximum(63);
        att_slider->setOrientation(Qt::Horizontal);
        att_slider->setTickPosition(QSlider::TicksAbove);
        att_slider->setTickInterval(2);
        att_line_edit = new QLineEdit(groupBox_3);
        att_line_edit->setObjectName(QString::fromUtf8("att_line_edit"));
        att_line_edit->setGeometry(QRect(10, 80, 181, 21));
        att_ctrl_pushbutton = new QPushButton(groupBox_3);
        att_ctrl_pushbutton->setObjectName(QString::fromUtf8("att_ctrl_pushbutton"));
        att_ctrl_pushbutton->setGeometry(QRect(10, 110, 181, 21));
        att_address_combo = new QComboBox(groupBox_3);
        att_address_combo->setObjectName(QString::fromUtf8("att_address_combo"));
        att_address_combo->setGeometry(QRect(10, 50, 181, 22));
        outputINCpow_label = new QLabel(centralwidget);
        outputINCpow_label->setObjectName(QString::fromUtf8("outputINCpow_label"));
        outputINCpow_label->setGeometry(QRect(570, 420, 141, 16));
        outputINCpow_label->setAlignment(Qt::AlignCenter);
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(220, 10, 161, 221));
        gate_slider = new QSlider(groupBox_4);
        gate_slider->setObjectName(QString::fromUtf8("gate_slider"));
        gate_slider->setGeometry(QRect(10, 70, 141, 16));
        gate_slider->setMinimum(2500);
        gate_slider->setMaximum(5000);
        gate_slider->setSliderPosition(2500);
        gate_slider->setOrientation(Qt::Horizontal);
        gate_slider->setTickPosition(QSlider::TicksAbove);
        gate_slider->setTickInterval(1);
        gate_line_edit = new QLineEdit(groupBox_4);
        gate_line_edit->setObjectName(QString::fromUtf8("gate_line_edit"));
        gate_line_edit->setGeometry(QRect(10, 90, 141, 21));
        gate_push_button = new QPushButton(groupBox_4);
        gate_push_button->setObjectName(QString::fromUtf8("gate_push_button"));
        gate_push_button->setGeometry(QRect(10, 120, 141, 21));
        setup_gate_voltage = new QPushButton(groupBox_4);
        setup_gate_voltage->setObjectName(QString::fromUtf8("setup_gate_voltage"));
        setup_gate_voltage->setGeometry(QRect(10, 40, 141, 21));
        drain_current_label = new QLabel(groupBox_4);
        drain_current_label->setObjectName(QString::fromUtf8("drain_current_label"));
        drain_current_label->setGeometry(QRect(10, 150, 141, 20));
        drain_current_label->setAlignment(Qt::AlignCenter);
        pushButton_6 = new QPushButton(groupBox_4);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(10, 180, 141, 21));
        strobCtrl_groupbox = new QGroupBox(centralwidget);
        strobCtrl_groupbox->setObjectName(QString::fromUtf8("strobCtrl_groupbox"));
        strobCtrl_groupbox->setGeometry(QRect(10, 380, 411, 111));
        strobPushButton = new QPushButton(strobCtrl_groupbox);
        strobPushButton->setObjectName(QString::fromUtf8("strobPushButton"));
        strobPushButton->setGeometry(QRect(10, 80, 141, 21));
        pulseWid_lineedit = new QLineEdit(strobCtrl_groupbox);
        pulseWid_lineedit->setObjectName(QString::fromUtf8("pulseWid_lineedit"));
        pulseWid_lineedit->setGeometry(QRect(10, 20, 141, 21));
        dutyCycle_lineedit = new QLineEdit(strobCtrl_groupbox);
        dutyCycle_lineedit->setObjectName(QString::fromUtf8("dutyCycle_lineedit"));
        dutyCycle_lineedit->setGeometry(QRect(10, 50, 141, 21));
        pulseWid_label = new QLabel(strobCtrl_groupbox);
        pulseWid_label->setObjectName(QString::fromUtf8("pulseWid_label"));
        pulseWid_label->setGeometry(QRect(170, 20, 111, 16));
        pulseWid_label->setAlignment(Qt::AlignCenter);
        duty_label = new QLabel(strobCtrl_groupbox);
        duty_label->setObjectName(QString::fromUtf8("duty_label"));
        duty_label->setGeometry(QRect(170, 50, 111, 16));
        duty_label->setAlignment(Qt::AlignCenter);
        strobe_checkbox = new QCheckBox(strobCtrl_groupbox);
        strobe_checkbox->setObjectName(QString::fromUtf8("strobe_checkbox"));
        strobe_checkbox->setGeometry(QRect(280, 20, 111, 19));
        stopPowButton = new QPushButton(centralwidget);
        stopPowButton->setObjectName(QString::fromUtf8("stopPowButton"));
        stopPowButton->setGeometry(QRect(550, 510, 75, 23));
        outputINC_lcdNumber = new QLCDNumber(centralwidget);
        outputINC_lcdNumber->setObjectName(QString::fromUtf8("outputINC_lcdNumber"));
        outputINC_lcdNumber->setGeometry(QRect(460, 420, 91, 23));
        comparatorGroupBox = new QGroupBox(centralwidget);
        comparatorGroupBox->setObjectName(QString::fromUtf8("comparatorGroupBox"));
        comparatorGroupBox->setGeometry(QRect(410, 10, 161, 221));
        compPR_slider = new QSlider(comparatorGroupBox);
        compPR_slider->setObjectName(QString::fromUtf8("compPR_slider"));
        compPR_slider->setGeometry(QRect(10, 30, 141, 16));
        compPR_slider->setMinimum(0);
        compPR_slider->setMaximum(2000);
        compPR_slider->setValue(0);
        compPR_slider->setSliderPosition(0);
        compPR_slider->setOrientation(Qt::Horizontal);
        compPR_slider->setTickPosition(QSlider::TicksAbove);
        compPR_slider->setTickInterval(1);
        compPR_pushbutton = new QPushButton(comparatorGroupBox);
        compPR_pushbutton->setObjectName(QString::fromUtf8("compPR_pushbutton"));
        compPR_pushbutton->setGeometry(QRect(10, 80, 141, 21));
        compPR_lineedit = new QLineEdit(comparatorGroupBox);
        compPR_lineedit->setObjectName(QString::fromUtf8("compPR_lineedit"));
        compPR_lineedit->setGeometry(QRect(10, 50, 141, 20));
        compPA_slider = new QSlider(comparatorGroupBox);
        compPA_slider->setObjectName(QString::fromUtf8("compPA_slider"));
        compPA_slider->setGeometry(QRect(10, 140, 141, 16));
        compPA_slider->setMinimum(0);
        compPA_slider->setMaximum(2000);
        compPA_slider->setValue(0);
        compPA_slider->setSliderPosition(0);
        compPA_slider->setOrientation(Qt::Horizontal);
        compPA_slider->setTickPosition(QSlider::TicksAbove);
        compPA_slider->setTickInterval(1);
        compPA_pushbutton = new QPushButton(comparatorGroupBox);
        compPA_pushbutton->setObjectName(QString::fromUtf8("compPA_pushbutton"));
        compPA_pushbutton->setGeometry(QRect(10, 190, 141, 21));
        compPA_lineedit = new QLineEdit(comparatorGroupBox);
        compPA_lineedit->setObjectName(QString::fromUtf8("compPA_lineedit"));
        compPA_lineedit->setGeometry(QRect(10, 160, 141, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 814, 21));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuEdit->menuAction());
        menuEdit->addAction(actionCalibrate);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionCalibrate->setText(QCoreApplication::translate("MainWindow", "Calibrate", nullptr));
        inputPow_label->setText(QCoreApplication::translate("MainWindow", "Input power INC, dBm", nullptr));
        com_groupbox->setTitle(QCoreApplication::translate("MainWindow", "COM Port", nullptr));
        com_button->setText(QCoreApplication::translate("MainWindow", "Open port", nullptr));
        comstate_label->setText(QCoreApplication::translate("MainWindow", "Closed", nullptr));
        echo_button->setText(QCoreApplication::translate("MainWindow", "Echo", nullptr));
        service_message->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
        com_refresh_button->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        UM78_supply_group->setTitle(QCoreApplication::translate("MainWindow", "Power Amplifier Supply Control", nullptr));
        plus_5_UM78_checkbox->setText(QCoreApplication::translate("MainWindow", "+5V", nullptr));
        minus_5_UM78_checkbox->setText(QCoreApplication::translate("MainWindow", "-5V", nullptr));
        plus_3_UM78_checkbox->setText(QCoreApplication::translate("MainWindow", "+3.3V", nullptr));
        plus_2_5_UM78_checkbox->setText(QCoreApplication::translate("MainWindow", "+2.5V", nullptr));
        UM78_supply_pushbutton->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        UM78_Vd_checkbox->setText(QCoreApplication::translate("MainWindow", "Vd", nullptr));
        outputREFpow_label->setText(QCoreApplication::translate("MainWindow", "Output power REF, dBm", nullptr));
        preAmp_groupbox->setTitle(QCoreApplication::translate("MainWindow", "Preamplifier Supply Control", nullptr));
        plus_5_checkbox->setText(QCoreApplication::translate("MainWindow", "+5V", nullptr));
        minus_5_checkbox->setText(QCoreApplication::translate("MainWindow", "-5V", nullptr));
        plus_3_checkbox->setText(QCoreApplication::translate("MainWindow", "+3.3V", nullptr));
        plus_2_5_checkbox->setText(QCoreApplication::translate("MainWindow", "+2.5V", nullptr));
        HMC_checkbox->setText(QCoreApplication::translate("MainWindow", "RF_+5V", nullptr));
        supply_ctrl_send_pushbutton->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        plus_28_checkbox->setText(QCoreApplication::translate("MainWindow", "+28V", nullptr));
        Vd_checkbox->setText(QCoreApplication::translate("MainWindow", "Vd", nullptr));
        UM78_gate_group->setTitle(QCoreApplication::translate("MainWindow", "PowAmp Gate/Drain Control", nullptr));
        UM78_gate_push_button->setText(QCoreApplication::translate("MainWindow", "Setup Gate Voltage", nullptr));
        UM78_setup_gate_voltage->setText(QCoreApplication::translate("MainWindow", "Power ON", nullptr));
        UM78_drain_current_label->setText(QCoreApplication::translate("MainWindow", "Drain Current", nullptr));
        UM78_read_drain_current->setText(QCoreApplication::translate("MainWindow", "Read Drain Current", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Attenuator Control", nullptr));
        att_ctrl_pushbutton->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        outputINCpow_label->setText(QCoreApplication::translate("MainWindow", "Output power INC, dBm", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "PreAmp Gate/Drain Control", nullptr));
        gate_push_button->setText(QCoreApplication::translate("MainWindow", "Setup Gate Voltage", nullptr));
        setup_gate_voltage->setText(QCoreApplication::translate("MainWindow", "Power ON", nullptr));
        drain_current_label->setText(QCoreApplication::translate("MainWindow", "Drain Current", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Read Drain Current", nullptr));
        strobCtrl_groupbox->setTitle(QCoreApplication::translate("MainWindow", "Strobe control", nullptr));
        strobPushButton->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        pulseWid_label->setText(QCoreApplication::translate("MainWindow", "Pulse width, us", nullptr));
        duty_label->setText(QCoreApplication::translate("MainWindow", "Duty cycle, %", nullptr));
        strobe_checkbox->setText(QCoreApplication::translate("MainWindow", "Modulation on/off", nullptr));
        stopPowButton->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        comparatorGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Comparator Control", nullptr));
        compPR_pushbutton->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        compPA_pushbutton->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
