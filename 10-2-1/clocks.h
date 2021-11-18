#ifndef __clocks__
#define __clocks__

#include "clock_time.h"

class Clock {
protected:
    ClockTime _clockTime;
    double _driftPerSecond;
    double _totalDrift;
public:
    Clock(int hour, int minute, int second, double driftPerSecond);
    void reset();
    void tick();
    virtual void displayTime() = 0;
};

/* ========================================== */

class NaturalClock: public Clock {
public:
    NaturalClock(int hour, int minute, int second, double driftPerSecond);
};

class SundialClock: public NaturalClock {
public:
    SundialClock(int hours, int minutes, int seconds);
    void displayTime();
};


/* ========================================== */

class MechanicalClock: public Clock {
public:
    MechanicalClock(int hour, int minute, int second, double driftPerSecond);
};

class CuckooClock: public MechanicalClock {
public:
    CuckooClock(int hours, int minutes, int seconds);
    void displayTime();    
};

class GrandFatherClock: public MechanicalClock {
public:
    GrandFatherClock(int hours, int minutes, int seconds);
    void displayTime();
};

/* ========================================== */

class DigitalClock: public Clock {
public:
    DigitalClock(int hour, int minute, int second, double driftPerSecond);
};

class WristClock: public DigitalClock {
public:
    WristClock(int hours, int minutes, int seconds);
    void displayTime();
};

/* ========================================== */

class QuantumClock: public Clock {
public:
    QuantumClock(int hour, int minute, int second, double driftPerSecond);
};

class AtomicClock: public QuantumClock {
public:
    AtomicClock(int hours, int minutes, int seconds);
    void displayTime();
};

#endif