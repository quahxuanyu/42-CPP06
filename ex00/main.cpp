#include "ScalarConverter.hpp"


int	main(int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
	{
		std::cout << "[ SPECIAL TEST ]\n";
		{
			try
			{
				ScalarConverter::convert("nan"); std::cout << std::endl;
				ScalarConverter::convert("nanf"); std::cout << std::endl;
				ScalarConverter::convert("+inf"); std::cout << std::endl;
				ScalarConverter::convert("+inff"); std::cout << std::endl;
				ScalarConverter::convert("-inf"); std::cout << std::endl;
				ScalarConverter::convert("-inff"); std::cout << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}

		std::cout << "[ CHAR TEST ]\n";
		{
			for (int i = -128; i < 128; ++i)
			{
				char c = static_cast<char>(i);
				std::string	str(1, c);
				try
				{
					ScalarConverter::convert(str);
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
				}
				std::cout << "\n";
			}
		}

		std::cout << "[ INT TEST ]\n";
		{
			try
			{
				ScalarConverter::convert("-123"); std::cout << "\n";
				ScalarConverter::convert("123");std::cout << "\n";
				ScalarConverter::convert("0"); std::cout << "\n";
				ScalarConverter::convert("-2147483648");std::cout << "\n";
				ScalarConverter::convert("2147483647"); std::cout << "\n";
				ScalarConverter::convert("-2147483649");std::cout << "\n";
				ScalarConverter::convert("2147483648");std::cout << "\n";
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}

		{
			std::cout << "[ FLOAT TEST ]\n";
			try
			{
				ScalarConverter::convert("123.0f");
				std::cout << "\n";
				ScalarConverter::convert("-123.0f");
				std::cout << "\n";
				ScalarConverter::convert("0f");
				std::cout << "\n";
				ScalarConverter::convert("12367.223f");
				std::cout << "\n";
				ScalarConverter::convert("-12367.223f");
				std::cout << "\n";
				ScalarConverter::convert("1234567.0f");
				std::cout << "\n";
				ScalarConverter::convert("-1234567.0f");
				std::cout << "\n";
				ScalarConverter::convert("2147483648f");
				std::cout << "\n";
				ScalarConverter::convert("-2147483649f");
				std::cout << "\n";
				ScalarConverter::convert("3.40282347e+38f");
				std::cout << "\n";
				ScalarConverter::convert("-3.40282347e+38f");
				std::cout << "\n";
				ScalarConverter::convert("1.17549435e-38f");
				std::cout << "\n";
				ScalarConverter::convert("-1.17549435e-38f");
				std::cout << "\n";
				ScalarConverter::convert("3.40282347e+39f");
				std::cout << "\n";
				ScalarConverter::convert("-3.40282347e+39f");
				std::cout << "\n";
				ScalarConverter::convert("1.17549435e-39f");
				std::cout << "\n";
				ScalarConverter::convert("-1.17549435e-39f");
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			
		}

		std::cout << "[ DOUBLE TEST ]\n";
		{
			try
			{
				ScalarConverter::convert("123.0");
				std::cout << "\n";
				ScalarConverter::convert("-123.0");
				std::cout << "\n";
				ScalarConverter::convert("0.00");
				std::cout << "\n";
				ScalarConverter::convert("12367.223");
				std::cout << "\n";
				ScalarConverter::convert("-12367.223");
				std::cout << "\n";
				ScalarConverter::convert("1234567.0");
				std::cout << "\n";
				ScalarConverter::convert("-1234567.0");
				std::cout << "\n";
				ScalarConverter::convert("2147483648.0");
				std::cout << "\n";
				ScalarConverter::convert("-2147483649.0");
				std::cout << "\n";
				ScalarConverter::convert("3.40282347e+38");
				std::cout << "\n";
				ScalarConverter::convert("-3.40282347e+38");
				std::cout << "\n";
				ScalarConverter::convert("1.17549435e-38");
				std::cout << "\n";
				ScalarConverter::convert("-1.17549435e-38");
				std::cout << "\n";
				ScalarConverter::convert("3.40282347e+39");
				std::cout << "\n";
				ScalarConverter::convert("-3.40282347e+39");
				std::cout << "\n";
				ScalarConverter::convert("1.17549435e-39");
				std::cout << "\n";
				ScalarConverter::convert("-1.17549435e-39");
				std::cout << "\n";
				ScalarConverter::convert("1.7976931348623157e+308");
				std::cout << "\n";
				ScalarConverter::convert("-1.7976931348623157e+308");
				std::cout << "\n";
				ScalarConverter::convert("2.2250738585072014e-308");
				std::cout << "\n";
				ScalarConverter::convert("-2.2250738585072014e-308");
				std::cout << "\n";
				ScalarConverter::convert("1.7976931348623157e+309");
				std::cout << "\n";
				ScalarConverter::convert("-1.7976931348623157e+309");
				std::cout << "\n";
				ScalarConverter::convert("2.2250738585072014e-309");
				std::cout << "\n";
				ScalarConverter::convert("-2.2250738585072014e-309");
				std::cout << "\n";
			}
			catch(const std::exception& e)
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
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return (0);
}