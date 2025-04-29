#include <iostream>
#include "Json.h"

int main()
{
	MiniJson::Json json_test;
	json_test.SetElement<std::string>("Tester_string", "Test");
	json_test.SetElement<float>("Tester_float", 3.14f);

	bool test_bool = true;
	json_test.SetElement("Tester_bool", test_bool);

	float test_float = json_test.GetElement<float>("Tester_float");
	std::string test_string = json_test.GetElement<std::string>("Tester_string");
	test_bool = json_test.GetElement<bool>("Tester_bool");

	std::cout << "Test Bool: " << std::boolalpha << test_bool << std::endl;
	std::cout << "Test String: " << test_string << std::endl;
	std::cout << "Test Float: " << test_float << std::endl;

	return EXIT_SUCCESS;	
}