#include "ScalarConverter.hpp"


/**
 * Static non-member functions ensure the function cannot be used outside this file.
 */


static void printChar(std::string const &str) {
    char c = str[0];
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

static void printInt(std::string const &str) {
    std::istringstream iss(str);
    int i;
    iss >> i;
    if (i >= 32 && i <= 126)
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}

static void printFloat(std::string const &str) {
    std::istringstream iss(str);
    float f;
    iss >> f;
    if (f >= 32 && f <= 126)
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

static void printDouble(std::string const &str) {
    std::istringstream iss(str);
    double d;
    iss >> d;
    if (d >= 32 && d <= 126)
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

static void printSpecial(std::string const &str) {
    if (str == "nan" || str == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    } else if (str == "+inf" || str == "+inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    } else if (str == "-inf" || str == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

void ScalarConverter::convert(std::string const &str) {
    Type type = detectType(str);

    switch (type) {
        case CHAR:
            std::cout << "Detected type: CHAR" << std::endl;
            printChar(str);
            break;
        case INT:
            std::cout << "Detected type: INT" << std::endl;
            printInt(str);
            break;
        case FLOAT:
            std::cout << "Detected type: FLOAT" << std::endl;
            printFloat(str);
            break;
        case DOUBLE:
            std::cout << "Detected type: DOUBLE" << std::endl;
            printDouble(str);
            break;
        case SPECIAL:
            std::cout << "Detected type: SPECIAL" << std::endl;
            printSpecial(str);
            break;
        default:
            std::cout << "Detected type: INVALID" << std::endl;
            break;
    }
}