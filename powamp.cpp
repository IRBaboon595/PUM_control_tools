#include "powamp.h"

powAmp::powAmp()
{
    plus_5vrf = false;
    minus_5v = false;
    plus_3_3v = false;
    plus_2_5v = false;
    vd = false;
    vg = false;
    setGate(false);
    setDrain(false);
    setGateLevel(-5);

}

bool powAmp::getSup(int sup_id)
{
    bool result = false;
    switch (sup_id) {
    case PLUS_5VRF:
        result = plus_5vrf;
        break;
    case MINUS_5V:
        result = minus_5v;
        break;
    case PLUS_3_3V:
        result = plus_3_3v;
        break;
    case PLUS_2_5V:
        result = plus_2_5v;
        break;
    case Vd:
        result = vd;
        break;
    case Vg:
        result = vg;
        break;
    default:
        result = false;
        break;
    }
    return result;
}

double powAmp::getADCpow()
{
    return incPow;
}

void powAmp::setSup(int sup_id, bool state)
{
    switch (sup_id) {
    case PLUS_5VRF:
        plus_5vrf = state;
        break;
    case MINUS_5V:
        minus_5v = state;
        break;
    case PLUS_3_3V:
        plus_3_3v = state;
        break;
    case PLUS_2_5V:
        plus_2_5v = state;
        break;
    case Vd:
        vd = state;
        break;
    case Vg:
        vg = state;
        break;
    default:
        break;
    }
}

void powAmp::setADCpow(double pow, int type)
{
    switch (type) {
    case INCEDENT:
        incPow = pow;
        break;
    case REFLECTED:
        refPow = pow;
        break;
    default:
        break;
    }
}

void powAmp::flushADCpow()
{
    incPow = 0;
    refPow = 0;
}


powAmp::~powAmp()
{

}
