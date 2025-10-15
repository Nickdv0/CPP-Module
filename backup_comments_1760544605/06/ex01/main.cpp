/* ************************************************************************** */











#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Testing Serializer Class ===" << std::endl;


	Data originalData;
	originalData.id = 42;
	originalData.name = "Test Data";
	originalData.value = 3.14159;
	originalData.active = true;

	std::cout << "\n1. Original Data:" << std::endl;
	std::cout << "Address: " << &originalData << std::endl;
	std::cout << "ID: " << originalData.id << std::endl;
	std::cout << "Name: " << originalData.name << std::endl;
	std::cout << "Value: " << originalData.value << std::endl;
	std::cout << "Active: " << (originalData.active ? "true" : "false") << std::endl;


	uintptr_t serialized = Serializer::serialize(&originalData);
	std::cout << "\n2. Serialization:" << std::endl;
	std::cout << "Serialized value: " << serialized << std::endl;
	std::cout << "Serialized value (hex): 0x" << std::hex << serialized << std::dec << std::endl;


	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "\n3. Deserialization:" << std::endl;
	std::cout << "Deserialized address: " << deserialized << std::endl;
	std::cout << "ID: " << deserialized->id << std::endl;
	std::cout << "Name: " << deserialized->name << std::endl;
	std::cout << "Value: " << deserialized->value << std::endl;
	std::cout << "Active: " << (deserialized->active ? "true" : "false") << std::endl;


	std::cout << "\n4. Verification:" << std::endl;
	std::cout << "Original pointer == Deserialized pointer: "
			  << ((&originalData == deserialized) ? "true" : "false") << std::endl;


	std::cout << "\n5. Testing with different data:" << std::endl;
	Data anotherData;
	anotherData.id = 100;
	anotherData.name = "Another Test";
	anotherData.value = 2.71828;
	anotherData.active = false;

	uintptr_t serialized2 = Serializer::serialize(&anotherData);
	Data* deserialized2 = Serializer::deserialize(serialized2);

	std::cout << "Original address: " << &anotherData << std::endl;
	std::cout << "Deserialized address: " << deserialized2 << std::endl;
	std::cout << "Pointers equal: " << ((&anotherData == deserialized2) ? "true" : "false") << std::endl;
	std::cout << "Data intact: " << ((anotherData.id == deserialized2->id &&
									  anotherData.name == deserialized2->name &&
									  anotherData.value == deserialized2->value &&
									  anotherData.active == deserialized2->active) ? "true" : "false") << std::endl;

	std::cout << "\n=== All tests completed ===" << std::endl;
	return 0;
}
