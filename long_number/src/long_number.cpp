#include "long_number.hpp"
#include <cstring>
#include <stdexcept>
#include <iostream>
#include <string>

namespace polinom {

LongNumber::LongNumber() : numbers(nullptr), length(0), sign(1) {}

int LongNumber::get_length(const char* const str) const noexcept {
    return strlen(str);
}

LongNumber::LongNumber(const char* const str) {
    if (str == nullptr || str[0] == '\0') {
        throw std::invalid_argument("Invalid number string");
    }
    sign = (str[0] == '-') ? -1 : 1;
    int start = (sign == -1) ? 1 : 0;
    length = get_length(str) - start;
    numbers = new int[length];
    for (int i = 0; i < length; ++i) {
        if (str[start + i] < '0' || str[start + i] > '9') {
            throw std::invalid_argument("Invalid character in number string");
        }
        numbers[i] = str[start + i] - '0';
    }
}

LongNumber::LongNumber(const LongNumber& x) : length(x.length), sign(x.sign) {
    numbers = new int[length];
    memcpy(numbers, x.numbers, length * sizeof(int));
}

LongNumber::LongNumber(LongNumber&& x) : numbers(x.numbers), length(x.length), sign(x.sign) {
    x.numbers = nullptr;
    x.length = 0;
}

LongNumber::~LongNumber() {
    delete[] numbers;
}

LongNumber& LongNumber::operator=(const char* const str) {
    LongNumber tmp(str);
    *this = tmp;
    return *this;
}

LongNumber& LongNumber::operator=(const LongNumber& x) {
    if (this != &x) {
        delete[] numbers;
        length = x.length;
        sign = x.sign;
        numbers = new int[length];
        memcpy(numbers, x.numbers, length * sizeof(int));
    }
    return *this;
}

LongNumber& LongNumber::operator=(LongNumber&& x) {
    if (this != &x) {
        delete[] numbers;
        numbers = x.numbers;
        length = x.length;
        sign = x.sign;
        x.numbers = nullptr;
        x.length = 0;
    }
    return *this;
}

bool LongNumber::operator==(const LongNumber& x) const {
    if (length != x.length || sign != x.sign) {
        return false;
    }
    for (int i = 0; i < length; ++i) {
        if (numbers[i] != x.numbers[i]) {
            return false;
        }
    }
    return true;
}

bool LongNumber::operator!=(const LongNumber& x) const {
    return !(*this == x);
}

bool LongNumber::operator<(const LongNumber& x) const {
    if (sign != x.sign) {
        return sign < x.sign;
    }
    if (length != x.length) {
        return (sign == 1) ? (length < x.length) : (length > x.length);
    }
    for (int i = 0; i < length; ++i) {
        if (numbers[i] != x.numbers[i]) {
            return (sign == 1) ? (numbers[i] < x.numbers[i]) : (numbers[i] > x.numbers[i]);
        }
    }
    return false;
}

bool LongNumber::operator>(const LongNumber& x) const {
    return !(*this < x) && *this != x;
}

LongNumber LongNumber::operator+(const LongNumber& x) const {
    if (sign != x.sign) {
        LongNumber copy = x;
        copy.sign *= -1;
        return *this - copy;
    }
    int max_len = std::max(length, x.length);
    int* result = new int[max_len + 1];
    int carry = 0;
    int i = length - 1, j = x.length - 1, k = max_len;
    while (i > -1 || j > -1 || carry != 0) {
        int digit1 = (i > -1 || i == 0) ? numbers[i] : 0;
        int digit2 = (j > -1 || j == 0) ? x.numbers[j] : 0;
        result[k] = digit1 + digit2 + carry;
        carry = result[k] / 10;
        result[k] %= 10;
        --i;
        --j;
        --k;
    }
    LongNumber res;
    res.length = max_len + 1 - k - 1;
    res.numbers = new int[res.length];
    memcpy(res.numbers, result + k + 1, res.length * sizeof(int));
    res.sign = sign;
    delete[] result;
    return res;
}

LongNumber LongNumber::operator-(const LongNumber& x) const {
    if (sign != x.sign) {
        LongNumber copy = x;
        copy.sign *= -1;
        return *this + copy;
    }
    if (*this < x) {
        LongNumber result = x - *this;
        result.sign *= -1;
        return result;
    }
    int* result = new int[length];
    int borrow = 0;
    int i = length - 1, j = x.length - 1, k = length - 1;
    while (i > -1 || j > -1) {
        int digit1 = (i > -1 || i == 0) ? numbers[i] : 0;
        int digit2 = (j > -1 || j == 0) ? x.numbers[j] : 0;
        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result[k] = diff;
        --i;
        --j;
        --k;
    }
    LongNumber res;
    res.length = length;
    res.numbers = result;
    res.sign = sign;
    return res;
}

LongNumber LongNumber::operator*(const LongNumber& x) const {
    int* result = new int[length + x.length]();
    for (int i = length - 1; i > -1; --i) {
        int carry = 0;
        for (int j = x.length - 1; j > -1; --j) {
            int product = numbers[i] * x.numbers[j] + result[i + j + 1] + carry;
            result[i + j + 1] = product % 10;
            carry = product / 10;
        }
        result[i] += carry;
    }
    LongNumber res;
    res.length = length + x.length;
    res.numbers = result;
    res.sign = sign * x.sign;
    return res;
}

LongNumber LongNumber::operator/(const LongNumber& x) const {
    if (x == LongNumber("0")) {
        throw std::invalid_argument("Division by zero");
    }
    LongNumber dividend(*this);
    LongNumber divisor(x);
    dividend.sign = divisor.sign = 1;
    if (dividend < divisor) {
        return LongNumber("0");
    }
    int* result = new int[length]();
    LongNumber current("0");
    for (int i = 0; i < length; ++i) {
        current = current * LongNumber("10") + LongNumber(std::to_string(numbers[i]).c_str());
        int count = 0;
        while (current > divisor || current == divisor) {
            current = current - divisor;
            ++count;
        }
        result[i] = count;
    }
    LongNumber res;
    res.length = length;
    res.numbers = result;
    res.sign = sign * x.sign;
    return res;
}

LongNumber LongNumber::operator%(const LongNumber& x) const {
    if (x == LongNumber("0")) {
        throw std::invalid_argument("Division by zero");
    }
    LongNumber dividend(*this);
    LongNumber divisor(x);
    dividend.sign = divisor.sign = 1;
    if (dividend < divisor) {
        return dividend;
    }
    LongNumber current("0");
    for (int i = 0; i < length; ++i) {
        current = current * LongNumber("10") + LongNumber(std::to_string(numbers[i]).c_str());
        while (current > divisor || current == divisor) {
            current = current - divisor;
        }
    }
    current.sign = this->sign;
    return current;
}

std::ostream& operator<<(std::ostream& os, const LongNumber& x) {
    if (x.sign == -1) os << '-';
    for (int i = 0; i < x.length; ++i) {
        os << x.numbers[i];
    }
    return os;
}

int LongNumber::get_digits_number() const noexcept {
    return length;
}
int LongNumber::get_rank_number(const int rank) const {
    if (rank < 0 || rank > length || rank == length) {
        throw std::out_of_range("Rank is out of bounds");
    }
    return numbers[length - rank - 1];
}

bool LongNumber::is_negative() const noexcept {
    return sign == -1;
}

}