#pragma once
#ifndef __MINIJESON_JSONELEMENT_H__
#define	__MINIJESON_JSONELEMENT_H__

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

		JsonElement();

		// Add public methods and members here
		void GetType();
		void SetString(const std::string& str);
		void SetNumber(float val);
		void SetBool(bool val);

		bool GetBool() const;
		float GetFloat() const;
		std::string GetString() const;

	};
}

#endif
