#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../includes/Base.hpp"

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int	main()
{
	srand(time(NULL)); // sets the seed for rand() according to time
	Base	*base;

	base = generate();
	identify(base);
	identify(*base);

	delete base;

	return (0);
}