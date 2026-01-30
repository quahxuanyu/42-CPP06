#include "ScalarConverter.hpp"

bool isChar(const std::string &str) {
    return str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]);
}

bool isInt(const std::string &str) {
    size_t i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    for (; i < str.length(); i++) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return !str.empty();
}

bool isFloat(const std::string &str) {
    size_t i = 0;
    bool decimalPointSeen = false;
    if (str[i] == '-' || str[i] == '+')
        i++;
    for (; i < str.length(); i++) {
        if (str[i] == '.') {
            if (decimalPointSeen)
                return false;
            decimalPointSeen = true;
        } else if (str[i] == 'f') {
            // 'f' should be the last character
            return decimalPointSeen && i == str.length() - 1;
        } else if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return false; // Must have decimal point and 'f' suffix
}

bool isDouble(const std::string &str) {
    size_t i = 0;
    bool decimalPointSeen = false;
    if (str[i] == '-' || str[i] == '+')
        i++;
    for (; i < str.length(); i++) {
        if (str[i] == '.') {
            if (decimalPointSeen)
                return false;
            decimalPointSeen = true;
        } else if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return decimalPointSeen;
}

bool isSpecial(const std::string &str) {
    return str == "nan" || str == "+inf" || str == "-inf" ||
           str == "nanf" || str == "+inff" || str == "-inff";
}

Type detectType(const std::string &str) {
    if (isChar(str))
        return CHAR;
    else if (isInt(str))
        return INT;
    else if (isFloat(str))
        return FLOAT;
    else if (isDouble(str))
        return DOUBLE;
    else if (isSpecial(str))
        return SPECIAL;
    else
        return INVALID;
}
