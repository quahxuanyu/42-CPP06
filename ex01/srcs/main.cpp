#include "../includes/Serializer.hpp"
#include <iostream>

/**
 * The reinterpret_cast allows you to convert any pointer type to any other
 * pointer type. But it is dangerous and doesn't perform safety checks.
 * 
 * We use uintptr_t because its size is guaranteed to be able to store a
 * pointer without loss of information
 * 
 * [ PDF REQUIREMENT ]
 * Use serialize() on the address of the Data object and pass its return value
 * to deserialize(). Then, ensure the return value of deserialize() compares
 * equal to the original pointer
 */
int	main()
{
	Data data1;
	uintptr_t	saved;
	// Serializer	test; // proof that it cannot be instantiated

	data1.s1 = "random string";
	saved = Serializer::serialize(&data1);
	if (Serializer::deserialize(saved) == &data1)
	{
		std::cout << "Original address          : " << &data1 << std::endl;
		std::cout << "Reinterpret_casted address: " << Serializer::deserialize(saved) << std::endl;
		std::cout << "SUCCESS!\n";
	}
	else
		std::cout << "FAILURE!\n";
	return (0);
}