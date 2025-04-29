#include "Json.h"

namespace MiniJson
{
	template <>
	void Json::SetElement<std::string>(const std::string& key, const std::string& value)
	{
		if (m_Elements_map.find(key) == m_Elements_map.end())
		{
			m_Elements_map[key] = std::make_unique<JsonElement>();
			m_Elements_map[key]->SetString(value);
			return;
		}

		// else
		m_Elements_map[key]->SetString(value);
	}

	//template <>
	//void Json::SetElement<int>(const std::string& key, const int& value)
	//{
	//	if (m_Elements_map.find(key) == m_Elements_map.end())
	//	{
	//		m_Elements_map[key] = std::make_unique<JsonElement>();
	//		m_Elements_map[key]->SetNumber(value);
	//		return;
	//	}

	//	// else
	//	m_Elements_map[key]->SetNumber(value);

	//}

	template <>
	void Json::SetElement<float>(const std::string& key, const float& value)
	{
		if (m_Elements_map.find(key) == m_Elements_map.end())
		{
			m_Elements_map[key] = std::make_unique<JsonElement>();
			m_Elements_map[key]->SetNumber(value);
			return;
		}

		// else
		m_Elements_map[key]->SetNumber(value);
	}

	template <>
	void Json::SetElement<bool>(const std::string& key, const bool& value)
	{
		if (m_Elements_map.find(key) == m_Elements_map.end())
		{
			m_Elements_map[key] = std::make_unique<JsonElement>();
			m_Elements_map[key]->SetBool(value);
			return;
		}

		// else
		m_Elements_map[key]->SetBool(value);
	}

	Json::Json()
	{
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

}