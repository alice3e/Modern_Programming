//
// Created by alicee on 10.03.2024.
//
#include "long_number.hpp"

namespace IBusko {
    LongNumber::LongNumber() {
        // TODO
    }

    LongNumber::LongNumber(const char* const str) {
        // TODO
    }

    LongNumber::LongNumber(const LongNumber& x) {
        // TODO
    }

    LongNumber::LongNumber(LongNumber&& x) {
        // TODO
    }

    LongNumber::~LongNumber() {
        // TODO
    }

    LongNumber& LongNumber::operator = (const char* const str) {
        // TODO
        return *this;
    }

    LongNumber& LongNumber::operator = (const LongNumber& x) {
        // TODO
        return *this;
    }

    LongNumber& LongNumber::operator = (LongNumber&& x) {
        // TODO
        return *this;
    }

    bool LongNumber::operator == (const LongNumber& x) {
        // TODO
        return true;
    }

    bool LongNumber::operator > (const LongNumber& x) {
        // TODO
        return true;
    }

    bool LongNumber::operator < (const LongNumber& x) {
        // TODO later
        return true;
    }

    LongNumber LongNumber::operator + (const LongNumber& x) {
        // TODO
        LongNumber result;
        return result;
    }

    LongNumber LongNumber::operator - (const LongNumber& x) {
        // TODO
        LongNumber result = x;
        return result;
    }

    LongNumber LongNumber::operator * (const LongNumber& x) {
        // TODO
        LongNumber result;
        return result;
    }

    LongNumber LongNumber::operator / (const LongNumber& x) {
        // TODO
        LongNumber result;
        return result;
    }

    LongNumber LongNumber::operator % (const LongNumber& x) {
        // TODO
        LongNumber result;
        return result;
    }

    int LongNumber::get_digits_number() const {
        return length;
    }

    bool LongNumber::is_positive() const {
        return sign == POSITIVE;
    }

    // ----------------------------------------------------------
    // PRIVATE
    // ----------------------------------------------------------
    int LongNumber::get_length(const char* const str) const {
        // TODO
        int length = 0;
        return length;
    }

    // ----------------------------------------------------------
    // FRIENDLY
    // ----------------------------------------------------------
    std::ostream& operator << (std::ostream &os, const LongNumber& x) {
        // TODO
        return os;
    }
}