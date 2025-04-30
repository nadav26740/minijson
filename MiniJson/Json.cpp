#include "Json.h"

namespace MiniJson
{
	Json::Json()
	{
	}

	JsonBaseType& Json::operator[](const std::string& key)
	{
		auto itr = m_Elements_map.find(key);
		if (itr == m_Elements_map.end())
		{
			itr = m_Elements_map.emplace(key, std::make_unique<JsonBaseType>()).first;
		}
		return *(itr->second.get());
	}

	template<>
	float Json::GetElement<float>(const std::string& key) const
	{
		auto itr = m_Elements_map.find(key);
		if (itr != m_Elements_map.end())
		{
			return itr->second->GetFloat();
		}
		else
		{
			throw std::runtime_error("Key not found");
		}
	}

	template<typename T>
	T& Json::emplace(const std::string& key, const T& val)
	{
		// TODO: insert return statement here
		m_Elements_map[key] = std::make_unique<JsonBaseType>();
		return m_Elements_map[key]->operator=<T>(val);
	}

	template<>
	std::string Json::GetElement<std::string>(const std::string& key) const
	{
		auto itr = m_Elements_map.find(key);
		if (itr != m_Elements_map.end())
		{
			return itr->second->GetString();
		}
		else
		{
			throw std::runtime_error("Key not found");
		}
	}

	template<>
	bool Json::GetElement<bool>(const std::string& key) const
	{
		auto itr = m_Elements_map.find(key);
		if (itr != m_Elements_map.end())
		{
			return itr->second->GetBool();
		}
		else
		{
			throw std::runtime_error("Key not found");
		}
	}

	JsonBaseType& Json::at(const std::string& key)
	{
		auto itr = m_Elements_map.find(key);
		if (itr == m_Elements_map.end())
		{
			throw std::runtime_error("Key not found");
		}
		return *(itr->second.get());
	}
}