#include "preamp.h"

preAmp::preAmp()
{

}

bool preAmp::getSup(int sup_id)
{
    bool result = false;
    switch (sup_id) {
    case PLUS_5V:
        result = plus_5v;
        break;
    case PLUS_5VRF:
        result = plus_5vrf;
        break;
    case MINUS_5V:
        result = minus_5v;
        break;
    case PLUS_3_3V:
        result = plus_3_3v;
        break;
    case PLUS_28V:
        result = plus_28v;
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

double preAmp::getADCpow()
{
    return inPow;
}

float preAmp::getAtt()
{
    return attenuation;
}

void preAmp::setSup(int sup_id, bool state)
{
    switch (sup_id) {
    case PLUS_5V:
        plus_5v = state;
        break;
    case PLUS_5VRF:
        plus_5vrf = state;
        break;
    case MINUS_5V:
        minus_5v = state;
        break;
    case PLUS_3_3V:
        plus_3_3v = state;
        break;
    case PLUS_28V:
        plus_28v = state;
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

void preAmp::setADCpow(double pow)
{
    inPow = pow;
}

void preAmp::setAtt(float att)
{
    attenuation = att;
}

void preAmp::flushADCpow()
{
    inPow = 0;
}

preAmp::~preAmp()
{

}

