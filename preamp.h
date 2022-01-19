#ifndef PREAMP_H
#define PREAMP_H

#include <QObject>
#include "abstractamplifier.h"
#include "hardwaredevice.h"

class preAmp : virtual public AbstractAmplifier, public HardwareDevice
{

public:
    explicit preAmp();
    ~preAmp() override;

    bool getSup(int sup_id) override;
    double getADCpow() override;
    float getAtt();

    void setSup(int sup_id, bool state) override;
    void setADCpow(double pow);
    void setAtt(float att);

    void flushADCpow();

    typedef enum
    {
        PLUS_5V = 0,
        PLUS_5VRF,
        MINUS_5V,
        PLUS_3_3V,
        PLUS_28V,
        PLUS_2_5V,
        Vd,
        Vg
    }SUPPLIES;

private:
    bool plus_5v;
    bool plus_5vrf;
    bool minus_5v;
    bool plus_3_3v;
    bool plus_28v;
    bool plus_2_5v;
    bool vd;
    bool vg;

    double inPow;
    double temperature;
    float attenuation;
};

#endif // PREAMP_H
