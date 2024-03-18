#include "long_number.hpp"


namespace IBusko {
    LongNumber::LongNumber() {
        numbers_ = nullptr;
        length_ = 0;
        sign_ = POSITIVE;
    }

    LongNumber::LongNumber(const char *const str) {
        if (str[0] == '0') {
            length_ = 1;
            sign_ = POSITIVE;
            numbers_ = new int[1];
        } else {

            //std::cout << std::endl <<  " ‼️ Started LongNumber::LongNumber(const char *const str)"  << std::endl;

            length_ = strlen(str); // str MUST HAVE \0 at the end
            sign_ = POSITIVE;

            if (length_ >= 1 && str[0] == '-') {
                sign_ = NEGATIVE;
                length_ -= 1;
            }


            numbers_ = new int[length_];

            if (sign_ == POSITIVE) {
                for (int i = 0; i < length_; i++) {
                    int x = int(str[i]) - 48;
                    if (x < 0 || x > 9) {
                        std::cout << std::endl << "Wrong symbol in given string! - " << x << " | string - " << str
                                  << std::endl;
                        throw "Wrong symbol in given string!"; // wil give "libc++abi: terminating due to uncaught exception of type char const*"
                    }
                    numbers_[i] = x;
                }
            } else {
                for (int i = 1; i < length_ + 1; i++) {
                    int x = int(str[i]) - 48;
                    if (x < 0 || x > 9) {
                        std::cout << std::endl << "Wrong symbol in given string! - " << x << std::endl;
                        throw "Wrong symbol in given string!"; // wil give "libc++abi: terminating due to uncaught exception of type char const*"
                    }
                    numbers_[i - 1] = x;
                }
            }
        }
    }

    LongNumber::LongNumber(const int x) {
        if (x == 0) {
            //std::cout << std::endl << "ZERO INT! - " << x << std::endl;
            length_ = 1;
            sign_ = POSITIVE;
            numbers_ = new int[1];
            numbers_[0] = 0;
        } else {
            //std::cout << std::endl << "NOT ZERO INT! - " << x << std::endl;
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
    }

    LongNumber::LongNumber(const LongNumber &x) {
        length_ = x.length_;
        sign_ = x.sign_;

        numbers_ = new int[length_];

        for (int i = 0; i < length_; i++) {
            numbers_[i] = x.numbers_[i];
        }
    }

    LongNumber::LongNumber(LongNumber &&x) {
        length_ = x.length_;
        sign_ = x.sign_;
        numbers_ = x.numbers_;

        x.numbers_ = nullptr;
    }

    LongNumber::~LongNumber() {
        if (numbers_ != nullptr) {
            delete[] numbers_;
        }
        length_ = 0;
        numbers_ = nullptr;
    }

    LongNumber &LongNumber::operator=(const char *const str) {

        length_ = strlen(str);
        if (length_ >= 1 && str[0] == '-') {
            sign_ = NEGATIVE;
            length_ -= 1;
        }

        if (numbers_ != nullptr) delete[] numbers_;
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
        if (x == 0) {
            length_ = 1;
            sign_ = POSITIVE;
            numbers_ = new int[1];
            return *this;
        } else {
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

            if (numbers_ != nullptr) delete[] numbers_;
            numbers_ = new int[length_];

            for (int i = 0; i < length_; i++) {
                int symb = b % 10;
                b /= 10;
                numbers_[length_ - i - 1] = symb;
            }
            return *this;
        }
    }

    LongNumber &LongNumber::operator=(const LongNumber &x) {
        if (this == &x) return *this; // in case y = y;
        // if y = y, delete[] numbers will erase both numbers_ arrays -> error
        this->length_ = x.length_;
        this->sign_ = x.sign_;

        if (numbers_ != nullptr) delete[] numbers_;
        numbers_ = new int[length_];

        for (int i = 0; i < length_; i++) {
            numbers_[i] = x.numbers_[i];
        }
        return *this;
    }

    LongNumber &LongNumber::operator=(LongNumber &&x) {
        if (numbers_ != nullptr) delete[] this->numbers_;
        this->length_ = x.length_;
        this->sign_ = x.sign_;
        this->numbers_ = x.numbers_;
        x.numbers_ = nullptr; // FIXME
        return *this;
    }

    bool LongNumber::operator==(const LongNumber &x) const {
        if (this == &x) return true; // if y == y -> optimisation
        if (this->numbers_ == nullptr || x.numbers_ == nullptr) throw "Problems with this or x";
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
        return !(*this == x);
    }

    bool LongNumber::operator>(const LongNumber &x) const {
        if (this->numbers_ == nullptr || x.numbers_ == nullptr) throw "Problems with this or x";
        if (this->sign_ > x.sign_) return true;
        else if (this->sign_ < x.sign_) return false;
        else {
            if (this->sign_ != x.sign_) throw "Wrong comparison >";

            if (this->length_ > x.length_) return true;
            else if (this->length_ < x.length_) return false;
            else {
                for (int i = 0; i < this->length_; i++) {
                    if (this->numbers_[i] < x.numbers_[i]) return false;
                }

                if (this->numbers_[length_ - 1] == x.numbers_[length_ - 1]) return false; // x == this
                else return true;
            }
        }
    }

    bool LongNumber::operator<(const LongNumber &x) const {
        if (this->numbers_ == nullptr || x.numbers_ == nullptr) throw "Problems with this or x";
        if (this->sign_ == x.sign_ && this->length_ == x.length_) {
            bool eq = 1;
            for (int i = 0; i < this->length_; i++) {
                if (this->numbers_[i] != x.numbers_[i]) eq = 0;
            }
            if (eq) return false;
        }
        return !(*this > x);
    }

    LongNumber LongNumber::operator+(const LongNumber &x) {
        if (this->numbers_ == nullptr || x.numbers_ == nullptr) throw "Problems with this or x";

        if (this->sign_ == x.sign_) {
            LongNumber result;
            if (*this == x && x == LongNumber("0")) {
                result = 0;
                return result; // check for 0 + 0

            } else {
                result.sign_ = this->sign_;
                int longest_len = (this->length_ > x.length_) ? (this->length_) : (x.length_);
                result.length_ = longest_len + 1;
                result.numbers_ = new int[result.length_]; // FIXME MEM LEAKS SOMEWHERE!


                int i_a = this->length_ - 1, i_b = x.length_ - 1, i_r = result.length_ - 1;
                for (int i = 0; i < result.length_; i++) {
                    int a = 0, b = 0;
                    if (i_a >= 0) a = this->numbers_[i_a];
                    if (i_b >= 0) b = x.numbers_[i_b];

                    int suma = a + b;
                    if (suma / 10 > 0) result.numbers_[i_r - 1] += 1;
                    result.numbers_[i_r] += suma % 10;
                    if (result.numbers_[i_r] >= 10) {
                        result.numbers_[i_r] %= 10;
                        result.numbers_[i_r - 1] += 1;
                    }

                    i_a -= 1;
                    i_b -= 1;
                    i_r -= 1;
                }


                // Обрезка ведущего нуля
                if (result.numbers_[0] == 0) {

                    LongNumber result_2;
                    result_2.length_ = result.length_ - 1;
                    result_2.sign_ = result.sign_;
                    result_2.numbers_ = new int[result_2.length_];
                    for (int i = 0; i < result_2.length_; i++) {
                        result_2.numbers_[i] = result.numbers_[i + 1];
                    }

                    return result_2;
                }
                return result; // FIXME LEAKS BECAUSE WE CANT DELETE NUMBERS_
            }

        } else {
            LongNumber reversed;
            if (x < *this) {
                reversed = x;
                reversed.sign_ *= -1;

                return (*this - reversed);
            } else {
                reversed = *this;
                reversed.sign_ *= -1;

                LongNumber x_copy = x; // because x - const
                return (x_copy - reversed);
            }
        }
    }

    LongNumber LongNumber::operator-(const LongNumber &x) {
        if (this->numbers_ == nullptr || x.numbers_ == nullptr) throw "Problems with this or x";
        LongNumber res;
        if (*this == x) {
            res.length_ = 1;

            res.sign_ = POSITIVE;
            res.numbers_ = new int[1];
            return res; // check for 0 - 0
        } else {
            if (x.sign_ == this->sign_) {
                bool swap_flag = 0;
                LongNumber a, b; // always a > b
                if (*this > x) {

                    a = *this;
                    b = x;
                } else {
                    a = x;
                    b = *this;
                    swap_flag = 1;
                }
                res.length_ = a.length_;
                res.sign_ = POSITIVE;
                res.numbers_ = new int[res.length_];

                int a_i = a.length_ - 1, b_i = b.length_ - 1;
                for (int i = 0; i < b.length_; i++) {
                    if (a.numbers_[a_i] < 0) {
                        a.numbers_[a_i] += 10;
                        a.numbers_[a_i - 1] -= 1;
                    }

                    if (a.numbers_[a_i] >= b.numbers_[b_i]) {
                        a.numbers_[a_i] = a.numbers_[a_i] - b.numbers_[b_i];
                    } else {
                        a.numbers_[a_i] = a.numbers_[a_i] - b.numbers_[b_i] + 10;
                        a.numbers_[a_i - 1] -= 1;
                    }

                    a_i -= 1;
                    b_i -= 1;
                }

                for (int i = 0; i < a.length_; i++) {
                    if (a.numbers_[a.length_ - i - 1] < 0) {
                        a.numbers_[a.length_ - i - 1] += 10;
                        a.numbers_[a.length_ - i - 2] -= 1;
                    }
                }

                // Обрезка ведущего нуля
                if (a.numbers_[0] == 0) {

                    LongNumber result_2;
                    result_2.length_ = a.length_ - 1;
                    result_2.sign_ = a.sign_;
                    result_2.numbers_ = new int[result_2.length_];
                    for (int i = 0; i < result_2.length_; i++) {
                        result_2.numbers_[i] = a.numbers_[i + 1];
                    }
                    a = result_2;
                }
                // замена знака если изначально this < x
                if (swap_flag) a.sign_ *= -1;
                return a;
            } else {
                if (*this > x) {
                    LongNumber a = x;
                    a.sign_ *= -1;
                    return (*this + a);
                } else {
                    LongNumber a = *this; // a = -123 x = 23
                    a.sign_ *= -1; // a = 123
                    a = a + x; // a = 123 + 23 = (-123 - 23)*-1
                    a.sign_ *= -1; // a = -146 = (-123 - 23)
                    return a;
                }
            }
            throw "Something wrong in '-' ";
            return res;
        }

    }


    LongNumber LongNumber::operator*(const LongNumber &x) {
        if (this->numbers_ == nullptr || x.numbers_ == nullptr) throw "Problems with this or x";
        LongNumber res = "0";
        LongNumber a, b;
        if (*this == LongNumber("0") || x == LongNumber("0")) return res; // FIXME ln(0) != ln("0")

        if (*this > x) { // always a > b
            a = *this;
            b = x;
        } else {
            a = x;
            b = *this;
        }

        res.length_ = 1;
        res.numbers_ = new int[1]; //new int[res.length_];

        int a_i = a.length_ - 1, b_i = b.length_ - 1;
        for (int i = 0; i < b.length_; i++) {
            for (int j = 0; j < a.length_; j++) {
                int pr = a.numbers_[a.length_ - j - 1] *
                         b.numbers_[b_i]; // FIXME переполнение int пр возв в степень 10-ки
                if (pr == 0) continue;
                int len_pr = (pr / 10 > 0) ? (2 + i + j) : (1 + i + j);
                char *pr_step = new char[len_pr + 1]; // + 1 - for \0
                for (int s = 0; s < len_pr; s++) pr_step[s] = static_cast<char>(48);

                if (pr / 10 != 0) {
                    pr_step[0] = static_cast<char>(pr / 10 + 48);
                    pr_step[1] = static_cast<char>(pr % 10 + 48);
                } else {
                    pr_step[0] = static_cast<char>((pr % 10) + 48);
                }
                pr_step[len_pr] = '\0';
                res = res + LongNumber(pr_step);
                delete[] pr_step;
            }
            b_i -= 1;
        }

        res.sign_ = (this->sign_ * x.sign_ > 0) ? (POSITIVE) : (NEGATIVE);

        return res;
    }

    LongNumber LongNumber::operator/(const LongNumber &x) {
        if (this->numbers_ == nullptr || x.numbers_ == nullptr) throw "Problems with this or x";
        LongNumber res = "0", a = *this, b = x, counter = "0";
        if (b < 0) b.sign_ *= -1;
        if (a < 0) a.sign_ *= -1;

        while (res * b < a) {
            res = res + 1;
        }
        if (res * b > a) res = res - 1;

        res.sign_ = (this->sign_ * x.sign_ > 0) ? (POSITIVE) : (NEGATIVE);
        return res;

    }

    LongNumber LongNumber::operator%(const LongNumber &x) {
        if (this->numbers_ == nullptr || x.numbers_ == nullptr) throw "Problems with this or x";
        LongNumber result = ("0");

        LongNumber del = (*this / x);

        result = (*this - (del * x));

        // FIXME - understand how we should %, because in C++ (int) -12 % -5 = -2, but
        // in the Interntet (-12)%(-5) = 3
        // So we should give positive only result or negative is fine?

        if (this->sign_ == x.sign_ && x.sign_ == POSITIVE) result.sign_ = POSITIVE; // 12%5 = 2
        else if (this->sign_ == x.sign_ && x.sign_ == NEGATIVE) result.sign_ = NEGATIVE; // (-12)%(-5) = -2
        else if (this->sign_ == POSITIVE && x.sign_ == NEGATIVE) result.sign_ = POSITIVE; // 12%(-5) = 2
        else result.sign_ = NEGATIVE; // (-12)%5 = -2

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
        if (x.sign_ == -1) os << LongNumber::MINUS;
        for (int i = 0; i < x.length_; i++) {
            os << x.numbers_[i];
        }
        return os;
    }
}
