#include "ScalarConverter.hpp"

static void printChar(std::string const &str)
{
    char c = str[0];

    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void printInt(std::string const &str)
{
    int i = ft_stoi(str);

    if (i >= 32 && i <= 126)
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else if (i >= -128 && i <= 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: Impossible" << std::endl;

    // check if over/underflow
    if (errno == ERANGE)
    {
        if (i == INT_MAX)
        {
            std::cout << "int: Overflow" << std::endl;
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        }
        else
        {
            std::cout << "int: Underflow" << std::endl;
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
        return;
    }

    std::cout << "int: " << i << std::endl;

    if ((str.length() == 7 && str[0] != '-') || str.length() > 7)
    {
        std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(i) << std::endl;
    }
    else
    {
        std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
    }
}

static void printFloat(std::string const &str)
{
    std::stringstream ss;
    double _temp = std::strtod(str.c_str(), NULL);
    errno = 0;
    float _f = std::strtof(str.c_str(), NULL);
    double _d = static_cast<double>(_f);
    char _c = static_cast<char>(_f);

    // if float over/underflows, double will too, but check float first to get correct sign
    if (errno == ERANGE)
    {
        if (_f == HUGE_VAL)
        {
            std::cout << "char: Impossible" << std::endl;
            std::cout << "int: Overflow" << std::endl;
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        }
        else if (_f == -HUGE_VAL)
        {
            std::cout << "char: Impossible" << std::endl;
            std::cout << "int: Underflow" << std::endl;
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
        else
        {
            std::cout << "char: Non displayable" << std::endl;
            std::cout << "int: 0" << std::endl;
            std::cout << "float: 0.0f" << std::endl;
            std::cout << "double: 0.0" << std::endl;
        }
        return;
    }

    if (_temp >= 32 && _temp <= 126)
        std::cout << "char: '" << _c << "'" << std::endl;
    else if (_temp >= -128 && _temp <= 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: Impossible" << std::endl;

    if (_temp < (std::numeric_limits<int>::min()))
        std::cout << "int: Underflow" << std::endl;
    else if (_temp > (std::numeric_limits<int>::max()))
        std::cout << "int: Overflow" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(_f) << std::endl;

    ss << _f;
    std::string floatStr = ss.str();
    if (floatStr.find('.') != std::string::npos || floatStr.find('e') != std::string::npos)
    {
        std::cout << "float: " << _f << "f" << std::endl;
        std::cout << "double: " << _d << std::endl;
    }
    else
    {
        std::cout << "float: " << _f << ".0f" << std::endl;
        std::cout << "double: " << _d << ".0" << std::endl;
    }
}

static void printDouble(std::string const &str)
{
    std::stringstream ss;
    float _temp = std::strtof(str.c_str(), NULL);
    int savedErrno = errno;
    errno = 0;
    double _d = std::strtod(str.c_str(), NULL);
    float _f = static_cast<float>(_d);
    char _c = static_cast<unsigned char>(_d);

    if (errno == ERANGE)
    {
        if (_d == HUGE_VAL)
        {
            std::cout << "char: Impossible" << std::endl;
            std::cout << "int: Overflow" << std::endl;
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        }
        else if (_d == -HUGE_VAL)
        {
            std::cout << "char: Impossible" << std::endl;
            std::cout << "int: Underflow" << std::endl;
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
        else
        {
            std::cout << "char: Non displayable" << std::endl;
            std::cout << "int: 0" << std::endl;
            std::cout << "float: 0.0f" << std::endl;
            std::cout << "double: 0.0" << std::endl;
        }
        return;
    }

    if (_d >= 32 && _d <= 126)
        std::cout << "char: '" << _c << "'" << std::endl;
    else if (_d >= -128 && _d <= 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: Impossible" << std::endl;

    if (_d < (std::numeric_limits<int>::min()))
        std::cout << "int: Underflow" << std::endl;
    else if (_d > (std::numeric_limits<int>::max()))
        std::cout << "int: Overflow" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(_d) << std::endl;

    if (savedErrno == ERANGE)
    {
        if (_temp == HUGE_VAL)
            std::cout << "float: +inff" << std::endl;
        else if (_temp == -HUGE_VAL)
            std::cout << "float: -inff" << std::endl;
        else
            std::cout << "float: 0.0f" << std::endl;
        if ((str.length() == 7 && str[0] != '-') || str.length() > 7)
            std::cout << "double: " << _d << std::endl;
        else
            std::cout << "double: " << _d << ".0" << std::endl;
    }
    else
    {
        ss << _d;
        std::string doubleStr = ss.str();
        if (doubleStr.find('.') != std::string::npos || doubleStr.find('e') != std::string::npos)
        {
            std::cout << "float: " << _f << "f" << std::endl;
            std::cout << "double: " << _d << std::endl;
        }
        else
        {
            std::cout << "float: " << _f << ".0f" << std::endl;
            std::cout << "double: " << _d << ".0" << std::endl;
        }
    }
}

static void printPseudoliteral(std::string const &str)
{
    std::cout << "char: Impossible" << std::endl;
    std::cout << "int: Impossible" << std::endl;

    if (!str.compare("+inf") || !str.compare("+inff"))
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (!str.compare("-inf") || !str.compare("-inff"))
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
}

void ScalarConverter::convert(std::string const &str)
{
    Type type = detectType(str);

    switch (type)
    {
    case CHAR:
        printChar(str);
        break;
    case INT:
        printInt(str);
        break;
    case FLOAT:
        printFloat(str);
        break;
    case DOUBLE:
        printDouble(str);
        break;
    case PSEUDOLITERAL:
        printPseudoliteral(str);
        break;
    default:
        throw(std::invalid_argument("Invalid input"));
    }
}