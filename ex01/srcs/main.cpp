#include "../includes/Serializer.hpp"
#include <iostream>

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