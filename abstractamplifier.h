#ifndef ABSTRACTAMPLIFIER_H
#define ABSTRACTAMPLIFIER_H

#include <QObject>

class AbstractAmplifier
{
public:
    explicit AbstractAmplifier();
    AbstractAmplifier(AbstractAmplifier *a);
    virtual ~AbstractAmplifier();

    virtual bool getSup(int sup_id) = 0;
    virtual bool getGate();
    virtual double getGateLevel();
    virtual bool getDrain();
    virtual double getADCpow() = 0;
    virtual double getTemp();
    virtual double getCompDacLevel();

    virtual void setSup(int sup_id, bool state) = 0;
    virtual void setGate(bool state);
    virtual void setGateLevel(double level);
    virtual void setDrain(bool state);
    virtual void setCompDacLevel(double level);

    virtual void flushTemp();

private:

    bool gateState;
    double gateLevel;
    bool drainState;
    double temperature;
    double compDacLevel;

};

#endif // ABSTRACTAMPLIFIER_H
