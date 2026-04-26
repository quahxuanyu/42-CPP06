#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

#include <iostream>
#include <sstream>
#include <climits>
#include <limits>
#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <string>

class ScalarConverter
{
private:
    ScalarConverter(); // Private constructor to prevent instantiation
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);

public:
    static void convert(const std::string &str); // Static method to perform conversion, can be called without an instance
};

enum Type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDOLITERAL,
    INVALID
};

Type detectType(const std::string &str);
bool isChar(const std::string &str);
bool isInt(const std::string &str);
bool isFloat(const std::string &str);
bool isDouble(const std::string &str);
bool isPseudoliteral(const std::string &str);
int ft_stoi(const std::string &str);

#endif