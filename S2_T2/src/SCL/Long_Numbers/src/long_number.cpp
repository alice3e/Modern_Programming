#include "long_number.hpp"


namespace IBusko {
    LongNumber::LongNumber() {
        numbers_ = new int[0];
        length_ = 0;
        sign_ = POSITIVE;
    }

    LongNumber::LongNumber(const char *const str) {
        //std::cout << std::endl <<  " ‼️ Started LongNumber::LongNumber(const char *const str)"  << std::endl;

        length_ = strlen(str);
        sign_ = POSITIVE;

        if (length_ >= 1 && str[0] == '-') {
            sign_ = NEGATIVE;
            length_ -= 1;
        }
        //std::cout << std::endl <<  " ⚠️️ LongNumber::LongNumber(const char *const str) LENGTH_ = " << length_ <<  std::endl << std::endl;

        numbers_ = new int[length_];

        if (sign_ == POSITIVE) {
            for (int i = 0; i < length_; i++) {
                int x = int(str[i]) - 48;
                if (x < 0 || x > 9)
                    throw "Wrong symbol in given string!"; // wil give "libc++abi: terminating due to uncaught exception of type char const*"
                numbers_[i] = x;
            }
        } else {
            for (int i = 1; i < length_ + 1; i++) {
                int x = int(str[i]) - 48;
                if (x < 0 || x > 9) throw "Wrong symbol in given string!";
                numbers_[i - 1] = x;
            }
        }

    }

    LongNumber::LongNumber(const int x) {
        if (x >= 0) sign_ = POSITIVE;
        else sign_ = NEGATIVE;
        int a = x; // for len
        int b = x; // for numbers_
        if (sign_ == NEGATIVE) {
            a *= -1;
            b *= -1;
        }

        length_ = 0;
        while (a > 0) {
            a /= 10;
            length_ += 1;
        }

        numbers_ = new int[length_];
        for (int i = 0; i < length_; i++) {
            int symb = b % 10;
            b /= 10;
            numbers_[length_ - i - 1] = symb;
        }

    }

    LongNumber::LongNumber(const LongNumber &x) {
        length_ = x.length_;
        sign_ = x.sign_;

        numbers_ = new int[length_];
        for (int i = 0; i < length_; i++) {
            numbers_[i] = x.numbers_[i];
        }
    }

    LongNumber::LongNumber(LongNumber &&x) { // What's the difference from previous?
        length_ = x.length_;
        sign_ = x.sign_;

        numbers_ = x.numbers_;
        x.numbers_ = nullptr;
    }

    LongNumber::~LongNumber() {
        delete[] numbers_;
    }

    LongNumber &LongNumber::operator=(const char *const str) {

        length_ = strlen(str);
        if (length_ >= 1 && str[0] == '-') {
            sign_ = NEGATIVE;
            length_ -= 1;
        }
        delete[] numbers_;
        numbers_ = new int[length_];
        if (sign_ == POSITIVE) {
            for (int i = 0; i < length_; i++) {
                int x = int(str[i]) - 48;
                if (x < 0 || x > 9)
                    throw "Wrong symbol in given string!"; // wil give "libc++abi: terminating due to uncaught exception of type char const*"
                numbers_[i] = x;
            }
        } else {
            for (int i = 1; i < length_ + 1; i++) {
                int x = int(str[i]) - 48;
                if (x < 0 || x > 9) throw "Wrong symbol in given string!";
                numbers_[i - 1] = x;
            }
        }
        return *this;
    }

    LongNumber &LongNumber::operator=(const int x) {
        if (x >= 0) sign_ = POSITIVE;
        else sign_ = NEGATIVE;
        int a = x; // for len
        int b = x; // for numbers_
        if (sign_ == NEGATIVE) {
            a *= -1;
            b *= -1;
        }

        length_ = 0;
        while (a > 0) {
            a /= 10;
            length_ += 1;
        }
        delete[] numbers_;
        numbers_ = new int[length_];
        for (int i = 0; i < length_; i++) {
            int symb = b % 10;
            b /= 10;
            numbers_[length_ - i - 1] = symb;
        }
        return *this;
    }

    LongNumber &LongNumber::operator=(const LongNumber &x) {
        this->length_ = x.length_;
        this->sign_ = x.sign_;

        delete[] numbers_;
        numbers_ = new int[length_];
        for (int i = 0; i < length_; i++) {
            numbers_[i] = x.numbers_[i];
        }
        return *this;
    }

    LongNumber &LongNumber::operator=(LongNumber &&x) {
        this->length_ = x.length_;
        this->sign_ = x.sign_;
        this->numbers_ = x.numbers_;
        x.numbers_ = nullptr; // FIXME
        return *this;
    }

    bool LongNumber::operator==(const LongNumber &x) const {
        if (this->sign_ == x.sign_ && this->length_ == x.length_) {
            for (int i = 0; i < this->length_; i++) {
                if (this->numbers_[i] != x.numbers_[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    bool LongNumber::operator!=(const LongNumber &x) const {
        if (this->sign_ == x.sign_ && this->length_ == x.length_) {
            for (int i = 0; i < this->length_; i++) {
                if (this->numbers_[i] != x.numbers_[i]) {
                    return true;
                }
            }
            return false;
        }
        return true;
    }

    bool LongNumber::operator>(const LongNumber &x) const {
        // TODO
        return true;
    }

    bool LongNumber::operator<(const LongNumber &x) const {
        // TODO
        return true;
    }

    LongNumber LongNumber::operator+(const LongNumber &x) {
        // TODO
        LongNumber result;
        return result;
    }

    LongNumber LongNumber::operator-(const LongNumber &x) {
        // TODO
        LongNumber result = x;
        return result;
    }

    LongNumber LongNumber::operator*(const LongNumber &x) {
        // TODO
        LongNumber result;
        return result;
    }

    LongNumber LongNumber::operator/(const LongNumber &x) {
        // TODO
        LongNumber result;
        return result;
    }

    LongNumber LongNumber::operator%(const LongNumber &x) {
        // TODO
        LongNumber result;
        return result;
    }

    int LongNumber::get_digits_number() const {
        return length_;
    }

    bool LongNumber::is_positive() const {
        return sign_ == POSITIVE;
    }

    // ----------------------------------------------------------
    // PRIVATE
    // А в чем задача функции? у нас есть точынй аналог get_digits_number
    // ----------------------------------------------------------
    int LongNumber::get_length(const char *const str) const {
        // TODO. А ЧТО TODO-ТО?
        int length = 0;
        return length;
    }

    // ----------------------------------------------------------
    // FRIENDLY
    // ----------------------------------------------------------
    std::ostream &operator<<(std::ostream &os, const LongNumber &x) {
        if (x.sign_ == -1) os << '-';
        for (int i = 0; i < x.length_; i++) {
            os << x.numbers_[i];
        }
        return os;
    }
}