#include "JsonBaseType.h"

void MiniJson::JsonBaseType::Reset()
{
	switch (this->m_type)
	{
	case JSON_TYPE::JSON_STRING:
		this->m_ValueUnion.string_val.reset();
		break;
	
	case JSON_TYPE::JSON_ARRAY:
		this->m_VectorElements.clear();
		break;

	case JSON_TYPE::JSON_OBJECT:
		this->m_ValueUnion.object_val.reset();
		break;

	default:
		break;
	}

	this->m_type = JSON_TYPE::JSON_NULL;
}

MiniJson::JsonBaseType::operator std::string()
{
	return this->GetString();
}

MiniJson::JsonBaseType::operator float()
{
	return this->GetFloat();
}

MiniJson::JsonBaseType::operator bool()
{
	return this->GetBool();
}

MiniJson::JsonBaseType::operator JsonBaseType()
{
	return this->GetObject();
}

MiniJson::JsonBaseType::JsonBaseType()
{
	this->m_type = JSON_TYPE::JSON_NULL;
	this->m_ValueUnion.string_val = nullptr;
}

MiniJson::JsonBaseType::JsonBaseType(const JsonBaseType& val)
{
	this->m_type = val.m_type;
	
}

void MiniJson::JsonBaseType::GetType()
{
}

void MiniJson::JsonBaseType::SetString(const std::string& str)
{
	this->Reset();
	
	this->m_ValueUnion.string_val = std::make_shared<std::string>(str);
	this->m_type = JSON_TYPE::JSON_STRING;
}

void MiniJson::JsonBaseType::SetNumber(const float& val)
{
	this->Reset();
	
	this->m_ValueUnion.float_val = val;
	this->m_type = JSON_TYPE::JSON_NUMBER;
}

void MiniJson::JsonBaseType::SetBool(const bool& val)
{
	this->Reset();
	
	this->m_ValueUnion.bool_val = val;
	this->m_type = JSON_TYPE::JSON_BOOL;
}

bool& MiniJson::JsonBaseType::GetBool()
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

float& MiniJson::JsonBaseType::GetFloat()
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

std::string& MiniJson::JsonBaseType::GetString()
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

MiniJson::JsonBaseType& MiniJson::JsonBaseType::GetObject()
{
	// TODO: insert return statement here
	if (this->m_type == JSON_TYPE::JSON_OBJECT)
	{
		return *(this->m_ValueUnion.object_val.get());
	}
	else
	{
		throw std::runtime_error("JSON Element Type mismatch: expected object");
	}
}

template<>
float& MiniJson::JsonBaseType::operator=<float>(const float& val)
{
	// TODO: insert return statement here
	this->SetNumber(val);
	
	return this->GetFloat();
}

template<>
std::string& MiniJson::JsonBaseType::operator=<std::string>(const std::string& val)
{
	// TODO: insert return statement here
	this->SetString(val);

	return this->GetString();
}

template<>
bool& MiniJson::JsonBaseType::operator=<bool>(const bool& val)
{
	// TODO: insert return statement here
	this->SetBool(val);

	return this->GetBool();
}


std::string& MiniJson::JsonBaseType::operator=(const char* val)
{
	this->SetString(std::string(val));
	return this->GetString();
}

//template<>
//MiniJson::JsonBaseType& MiniJson::JsonBaseType::operator=<MiniJson::JsonBaseType>(const MiniJson::JsonBaseType& val)
//{
//	this->Reset();
//	this->m_ValueUnion.object_val = std::make_shared<JsonBaseType>(val);
//
//	return *val.m_ValueUnion.object_val.get();
//}

//
std::ostream& MiniJson::operator<<(std::ostream& os, const JsonBaseType& obj)
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
