#include "../includes/Serializer.hpp"
#include <iostream>

/**
 * The reinterpret_cast allows you to convert any pointer type to any other
 * pointer type. But it is dangerous and doesn't perform safety checks.
 * 
 * We use uintptr_t because its size is guaranteed to be able to store a
 * pointer without loss of information
 * 
 * Use serialize() on the address of the Data object and pass its return value
 * to deserialize(). Then, ensure the return value of deserialize() compares
 * equal to the original pointer
 */
int	main()
{
	Data data1;
	uintptr_t	saved;

	data1.s1 = "some string";
	saved = Serializer::serialize(&data1);
	if (Serializer::deserialize(saved) == &data1)
	{
		std::cout << "Original string           : " << data1.s1 << std::endl;
		std::cout << "Original address          : " << &data1 << std::endl;
		std::cout << "Serializing... " << std::endl;
		std::cout << "Serialized uintptr_t value: " << saved << std::endl;
		std::cout << "Deserializing... " << std::endl;
		std::cout << "Reinterpret_casted string : " << Serializer::deserialize(saved)->s1 << std::endl;
		std::cout << "Reinterpret_casted address: " << Serializer::deserialize(saved) << std::endl;
		std::cout << "SUCCESS! Addresses match\n";
	}
	else
		std::cout << "FAIL! Addresses do not match\n";
	return (0);
}