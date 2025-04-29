#include "JsonElement.h"

MiniJson::JsonElement::operator std::string()
{
	return this->GetString();
}

MiniJson::JsonElement::operator float()
{
	return this->GetFloat();
}

MiniJson::JsonElement::operator bool()
{
	return this->GetBool();
}

MiniJson::JsonElement::JsonElement()
{
	this->m_type = JSON_TYPE::JSON_NULL;
	this->m_ValueUnion.string_val = nullptr;
}

void MiniJson::JsonElement::GetType()
{
}

void MiniJson::JsonElement::SetString(const std::string& str)
{
		if (this->m_type == JSON_TYPE::JSON_STRING)
	{
		this->m_ValueUnion.string_val.reset();
	}
	
	this->m_ValueUnion.string_val = std::make_shared<std::string>(str);
	this->m_type = JSON_TYPE::JSON_STRING;
}

void MiniJson::JsonElement::SetNumber(const float& val)
{
	if (this->m_type == JSON_TYPE::JSON_STRING)
	{
		this->m_ValueUnion.string_val.reset();
	}
	
	this->m_ValueUnion.float_val = val;
	this->m_type = JSON_TYPE::JSON_NUMBER;
}

void MiniJson::JsonElement::SetBool(const bool& val)
{
	if (this->m_type == JSON_TYPE::JSON_STRING)
	{
		this->m_ValueUnion.string_val.reset();
	}
	
	this->m_ValueUnion.bool_val = val;
	this->m_type = JSON_TYPE::JSON_BOOL;
}

bool& MiniJson::JsonElement::GetBool()
{
	if (this->m_type == JSON_TYPE::JSON_BOOL)
	{
		return this->m_ValueUnion.bool_val;
	}
	else
	{
		throw std::runtime_error("JSON Element Type mismatch: expected bool");
	}
}

float& MiniJson::JsonElement::GetFloat()
{
	if (this->m_type == JSON_TYPE::JSON_NUMBER)
	{
		return this->m_ValueUnion.float_val;
	}
	else
	{
		throw std::runtime_error("JSON Element Type mismatch: expected float");
	}
}

std::string& MiniJson::JsonElement::GetString()
{
	if (this->m_type == JSON_TYPE::JSON_STRING)
	{
		return *(this->m_ValueUnion.string_val.get());
	}
	else
	{
		throw std::runtime_error("JSON Element Type mismatch: expected string");
	}
}

template<>
float& MiniJson::JsonElement::operator=<float>(const float& val)
{
	// TODO: insert return statement here
	this->SetNumber(val);
	
	return this->GetFloat();
}

template<>
std::string& MiniJson::JsonElement::operator=<std::string>(const std::string& val)
{
	// TODO: insert return statement here
	this->SetString(val);

	return this->GetString();
}

template<>
bool& MiniJson::JsonElement::operator=<bool>(const bool& val)
{
	// TODO: insert return statement here
	this->SetBool(val);

	return this->GetBool();
}


std::string& MiniJson::JsonElement::operator=(const char* val)
{
	this->SetString(std::string(val));
	return this->GetString();
}

//
std::ostream& MiniJson::operator<<(std::ostream& os, const JsonElement& obj)
{
	// TODO: insert return statement here
	switch (obj.m_type)
	{
		case JSON_TYPE::JSON_STRING:
			os << *(obj.m_ValueUnion.string_val.get());
			break;

		case JSON_TYPE::JSON_NUMBER:
			os <<  (obj.m_ValueUnion.float_val);
			break;
	
		case JSON_TYPE::JSON_BOOL:
			os << (obj.m_ValueUnion.bool_val ? "true" : "false");
			break;

		case JSON_TYPE::JSON_NULL:
			os << ("null");
			break;

		case JSON_TYPE::JSON_OBJECT:
			os << ("object TODO");
			break;

		case JSON_TYPE::JSON_ARRAY:
			os << ("array TODO");
			break;

		default:
			os << ("unknown type");
			break;
	}
	return os;
}
