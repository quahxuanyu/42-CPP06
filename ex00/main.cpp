#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
	{
		std::cout << "*PSEUDOLITERAL EDGE CASES*\n";
		{
			try
			{
				ScalarConverter::convert("nan");
				std::cout << std::endl;
				ScalarConverter::convert("nanf");
				std::cout << std::endl;
				ScalarConverter::convert("+inf");
				std::cout << std::endl;
				ScalarConverter::convert("+inff");
				std::cout << std::endl;
				ScalarConverter::convert("-inf");
				std::cout << std::endl;
				ScalarConverter::convert("-inff");
				std::cout << std::endl;
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
			}
		}

		std::cout << "\n* CHAR EDGE CASES *\n";
		{
			try
			{
				ScalarConverter::convert("a");
				std::cout << "\n";
				ScalarConverter::convert(" ");
				std::cout << "\n";
				ScalarConverter::convert("~");
				std::cout << "\n";
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
			}
		}

		std::cout << "\n* INT OVERFLOW/UNDERFLOW *\n";
		{
			try
			{
				ScalarConverter::convert("-2147483648");
				std::cout << "\n";
				ScalarConverter::convert("2147483647");
				std::cout << "\n";
				ScalarConverter::convert("-2147483649");
				std::cout << "\n";
				ScalarConverter::convert("2147483648");
				std::cout << "\n";
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
			}
		}

		{
			std::cout << "\n* FLOAT OVERFLOW/UNDERFLOW *\n";
			try
			{
				ScalarConverter::convert("3.40282347e+38f");
				std::cout << "\n";
				ScalarConverter::convert("-3.40282347e+38f");
				std::cout << "\n";
				ScalarConverter::convert("3.40282347e+39f");
				std::cout << "\n";
				ScalarConverter::convert("-3.40282347e+39f");
				std::cout << "\n";
				ScalarConverter::convert("1.17549435e-38f");
				std::cout << "\n";
				ScalarConverter::convert("-1.17549435e-38f");
				std::cout << "\n";
				ScalarConverter::convert("1.17549435e-39f");
				std::cout << "\n";
				ScalarConverter::convert("-1.17549435e-39f");
				std::cout << "\n";
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
			}
		}

		std::cout << "\n* DOUBLE OVERFLOW/UNDERFLOW *\n";
		{
			try
			{
				ScalarConverter::convert("1.7976931348623157e+308");
				std::cout << "\n";
				ScalarConverter::convert("-1.7976931348623157e+308");
				std::cout << "\n";
				ScalarConverter::convert("1.7976931348623157e+309");
				std::cout << "\n";
				ScalarConverter::convert("-1.7976931348623157e+309");
				std::cout << "\n";
				ScalarConverter::convert("2.2250738585072014e-308");
				std::cout << "\n";
				ScalarConverter::convert("-2.2250738585072014e-308");
				std::cout << "\n";
				ScalarConverter::convert("2.2250738585072014e-309");
				std::cout << "\n";
				ScalarConverter::convert("-2.2250738585072014e-309");
				std::cout << "\n";
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}

	if (argc > 2)
	{
		std::cerr << "Invalid num of args!\n";
		return (1);
	}

	if (argc == 2)
	{
		try
		{
			ScalarConverter::convert(argv[1]);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return (0);
}