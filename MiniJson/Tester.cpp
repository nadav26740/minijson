#include <iostream>
#include "Json.h"

int main()
{

	MiniJson::Json json_test;
	try
	{
		json_test["Tester_string"] = "Hello World!";
		json_test["Tester_float"] = 3.14f;
		json_test["Tester_bool"] = true;

		bool test_bool = json_test["Tester_bool"];

		float test_float = json_test["Tester_float"];
		std::string test_string = json_test["Tester_string"];

		std::cout << "Test String: " << json_test["Tester_string"] << std::endl;
		std::cout << "Test Bool: " << std::boolalpha << json_test["Tester_bool"] << std::endl;
		std::cout << "Test Float: " << json_test["Tester_float"] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Unknown error occurred." << std::endl;
	}

	getchar();
	return EXIT_SUCCESS;	
}