#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

#include <iostream>
#include <sstream>

class ScalarConverter {
    private:
        ScalarConverter(); // Private constructor to prevent instantiation
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);

    public:
        static void convert(const std::string &str); // Static method to perform conversion, can be called without an instance
};
    
enum Type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    SPECIAL,
    INVALID
};

Type detectType(const std::string &str); // Function to detect the type of the literal
bool isChar(const std::string &str);
bool isInt(const std::string &str);
bool isFloat(const std::string &str);
bool isDouble(const std::string &str);
bool isSpecial(const std::string &str);

#endif 