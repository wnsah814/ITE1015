#include <iostream>
#include "clocks.h"

Clock::Clock(int hour, int minute, int second, double driftPerSecond):
    _driftPerSecond(driftPerSecond) {
    _clockTime = ClockTime(hour, minute, second, 1);
}

void Clock::reset() {
    _clockTime.reset();
}

void Clock::tick() {
    _clockTime.increment();
    _totalDrift += _driftPerSecond;
}

/* ========================================== */

NaturalClock::NaturalClock(int hour, int minute, int second, double driftPerSecond):
    Clock(hour, minute, second, driftPerSecond) {
};

SundialClock::SundialClock(int hours, int minutes, int seconds):
    NaturalClock(hours, minutes, seconds, 0) {};

void SundialClock::displayTime() {
    std::cout << "SundialClock ";
    _clockTime.display();
    std::cout << ", total drift: " << _totalDrift << std::endl;
}

/* ========================================== */

MechanicalClock::MechanicalClock(int hour, int minute, int second, double driftPerSecond):
    Clock(hour, minute, second, driftPerSecond) {}

CuckooClock::CuckooClock(int hours, int minutes, int seconds):
    MechanicalClock(hours, minutes, seconds, 0.000694444) {};

void CuckooClock::displayTime() {
    std::cout << "CuckooClock ";
    _clockTime.display();
    std::cout << ", total drift: " << _totalDrift << std::endl;
}


GrandFatherClock::GrandFatherClock(int hours, int minutes, int seconds):
    MechanicalClock(hours, minutes, seconds, 0.000347222) {};

void GrandFatherClock::displayTime() {
    std::cout << "GrandFatherClock ";
    _clockTime.display();
    std::cout << ", total drift: " << _totalDrift << std::endl;
}

/* ========================================== */

DigitalClock::DigitalClock(int hour, int minute, int second, double driftPerSecond):
    Clock(hour, minute, second, driftPerSecond) {
}

WristClock::WristClock(int hours, int minutes, int seconds):
    DigitalClock(hours, minutes, seconds, 0.000034722) {};

void WristClock::displayTime() {
    std::cout << "WristClock ";
    _clockTime.display();
    std::cout << ", total drift: " << _totalDrift << std::endl;
}

/* ========================================== */

QuantumClock::QuantumClock(int hour, int minute, int second, double driftPerSecond):
    Clock(hour, minute, second, driftPerSecond) {
}

AtomicClock::AtomicClock(int hours, int minutes, int seconds):
    QuantumClock(hours, minutes, seconds, 0) {}

void AtomicClock::displayTime() {
    std::cout << "AtomicClock ";
    _clockTime.display();
    std::cout << ", total drift: " << _totalDrift << std::endl;
}

