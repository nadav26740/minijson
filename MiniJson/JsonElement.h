#pragma once
#ifndef __MINIJESON_JSONELEMENT_H__
#define	__MINIJESON_JSONELEMENT_H__

#include <iostream>
#include <memory>
#include <string>
#include <exception>
#include <stdexcept>

namespace MiniJson
{
	enum JSON_TYPE
	{
		JSON_NULL,
		JSON_OBJECT,
		JSON_ARRAY,
		JSON_STRING,
		JSON_NUMBER,
		JSON_BOOL
	};

	// Forward declaration of JsonElement class
	class JsonElement
	{
	private:
		JSON_TYPE m_type;
		union t_ValueUnions
		{
			std::shared_ptr<std::string> string_val;
			float float_val;
			bool bool_val;
			t_ValueUnions() : string_val(nullptr) {} // Default constructor
			~t_ValueUnions() { float_val = NULL; } // Destructor
		};

		t_ValueUnions m_ValueUnion;
		// TODO ARRAY

	public:
		// Opertaors
		operator std::string();
		operator float();
		operator bool();

		template <typename T>
		T& operator=(const T& val);
		std::string& operator=(const char* val);
		friend std::ostream& operator<<(std::ostream& os, const JsonElement& jsonElement);

		JsonElement();

		// Add public methods and members here
		void GetType();
		void SetString(const std::string& str);
		void SetNumber(const float& val);
		void SetBool(const bool& val);

		bool& GetBool();
		float& GetFloat();
		std::string& GetString();

	};

	// Template specializations for operator=
	template<>
	float& JsonElement::operator=<float>(const float& val);

	template<>
	std::string& JsonElement::operator=<std::string>(const std::string& val);

	template<>
	bool& JsonElement::operator=<bool>(const bool& val);
	// = Char

}

#endif
