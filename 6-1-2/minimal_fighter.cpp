#include "minimal_fighter.h"

MinimalFighter::MinimalFighter() {
    mHp = 0;
    mPower = 0;
    mStatus = Invalid;
}

MinimalFighter::MinimalFighter(int _hp, int _power) {
    mHp = _hp;
    mPower = _power;
    if(_hp > 0) {
        mStatus = Alive;
    } else {
        mStatus = Dead;
    }
}

const int MinimalFighter::hp() const {
    return mHp;
}
const int MinimalFighter::power() const {
    return mPower;
}

const FighterStatus MinimalFighter::status() const {
    return mStatus;
}

void MinimalFighter::setHp(int _hp) {
    mHp = _hp;
}

void MinimalFighter::hit(MinimalFighter * _enemy) {
    mHp -= _enemy -> mPower;
    _enemy -> mHp -= mPower;
    if (mHp <= 0) {
        mStatus = Dead;
    }
    if (_enemy -> mHp <= 0) {
        _enemy -> mStatus = Dead;
    }
}

void MinimalFighter::attack(MinimalFighter * _enemy) {
    _enemy -> mHp -= mPower;
    mPower = 0;
    if (_enemy -> mHp <= 0) {
        _enemy -> mStatus = Dead;
    } 
}

void MinimalFighter::fight(MinimalFighter * _enemy) {
    while(mHp > 0 && _enemy -> mHp > 0 ) {
        mHp -= _enemy -> mPower;
        _enemy -> mHp -= mPower;
        if (mHp <= 0) {
        mStatus = Dead;
        }
        if (_enemy -> mHp <= 0) {
            _enemy -> mStatus = Dead;
        }
    }
}