#include "abstractamplifier.h"

AbstractAmplifier::AbstractAmplifier()
{
    gateState = false;
    gateLevel = -5;
    drainState = false;
    temperature = 0;
}

AbstractAmplifier::AbstractAmplifier(AbstractAmplifier *a)
{
    gateState = a->gateState;
    gateLevel = a->gateLevel;
    drainState = a->drainState;
    temperature = a->temperature;
}

bool AbstractAmplifier::getGate()
{
    return gateState;
}

double AbstractAmplifier::getGateLevel()
{
    return gateLevel;
}

bool AbstractAmplifier::getDrain()
{
    return drainState;
}

void AbstractAmplifier::setGate(bool state)
{
    gateState = state;
}

void AbstractAmplifier::setGateLevel(double level)
{
    gateLevel = level;
}

void AbstractAmplifier::setDrain(bool state)
{
    drainState = state;
}

void AbstractAmplifier::setCompDacLevel(double level)
{
    compDacLevel = level;
}

double AbstractAmplifier::getTemp()
{
    return temperature;
}

double AbstractAmplifier::getCompDacLevel()
{
    return compDacLevel;
}

void AbstractAmplifier::flushTemp()
{
    temperature = 0;
}


AbstractAmplifier::~AbstractAmplifier()
{

}
