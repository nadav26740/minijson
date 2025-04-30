#include <iostream>
#include <functional>
#include <string>

#include "Json.h"

/// <summary>
/// Running the tests in the vector.
/// </summary>
void RunTests();

// Tests
bool test1();
bool failure_Test();



std::vector<std::pair<std::function<bool()>, std::string>> tests
{
	{test1, "Test1"},
	{failure_Test, "Failure Test"},
	{failure_Test, "Failure Test"},
};

int main()
{

	MiniJson::Json json_test;
	MiniJson::Json json_test2;
	json_test2["Tester_string"] = "Hello worle!";
	try
	{
		RunTests();
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

void RunTests()
{
	int Successed = 0;
	for (const auto& test : tests)
	{
		std::cout << "Running " << test.second << "...";
		if (!test.first())
		{
			std::cerr << "failed!" << std::endl;
		}
		else
		{
			Successed++;
			std::cout << "passed!" << std::endl;
		}
	}
	std::cout << "Total tests passed: " << Successed << "/" << tests.size() << "........[" << ((Successed * 100) / (tests.size())) << "%]" << std::endl;
}


bool test1()
{
	return true;
}

bool failure_Test()
{
	return false;
}