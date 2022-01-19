#ifndef POWAMP_H
#define POWAMP_H

#include <QObject>
#include "abstractamplifier.h"
#include "hardwaredevice.h"

class powAmp : virtual public AbstractAmplifier, public HardwareDevice
{
    friend class QObject;
public:
    powAmp();
    ~powAmp() override;

    bool getSup(int sup_id) override;
    double getADCpow() override;

    void setSup(int sup_id, bool state) override;
    void setADCpow(double pow, int type);

    void flushADCpow();

    typedef enum
    {
        PLUS_5VRF = 0,
        MINUS_5V,
        PLUS_3_3V,
        PLUS_2_5V,
        Vd,
        Vg
    }SUPPLIES;

    typedef enum
    {
        INCEDENT = 0,
        REFLECTED
    }RF_POW_DET;

private:
    bool plus_5vrf;
    bool minus_5v;
    bool plus_3_3v;
    bool plus_2_5v;
    bool vd;
    bool vg;

    double incPow;
    double refPow;
    double temperature;

};

#endif // POWAMP_H
