#include "JsonElement.h"

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

void MiniJson::JsonElement::SetNumber(float val)
{
	if (this->m_type == JSON_TYPE::JSON_STRING)
	{
		this->m_ValueUnion.string_val.reset();
	}
	
	this->m_ValueUnion.float_val = val;
	this->m_type = JSON_TYPE::JSON_NUMBER;
}

void MiniJson::JsonElement::SetBool(bool val)
{
	if (this->m_type == JSON_TYPE::JSON_STRING)
	{
		this->m_ValueUnion.string_val.reset();
	}
	
	this->m_ValueUnion.bool_val = val;
	this->m_type = JSON_TYPE::JSON_BOOL;
}

bool MiniJson::JsonElement::GetBool() const
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

float MiniJson::JsonElement::GetFloat() const
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

std::string MiniJson::JsonElement::GetString() const
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