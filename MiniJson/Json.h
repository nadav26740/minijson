#pragma once
#ifndef __MINIJESON_JSON_H__
#define	__MINIJESON_JSON_H__

#include <iostream>
#include <string>
#include <map>
#include <memory>

#include "JsonElement.h"


namespace MiniJson
{
	class Json
	{
	private:
		// Private members and methods can be declared here
		std::map<std::string, std::unique_ptr<JsonElement>> m_Elements_map;

	public:
		Json();
		
		template <typename T>
		void SetElement(const std::string& key, const T& value);

		template <typename T>
		T GetElement(const std::string& key) const;

		template <typename T>
		void RemoveElement(const std::string& key);

	};
	
	// Template specializations for SetElement
	template <>
	void Json::SetElement<std::string>(const std::string& key, const std::string& value);
	
	template <>
	void Json::SetElement<bool>(const std::string& key, const bool& value);
	
	template <>
	void Json::SetElement<float>(const std::string& key, const float& value);

	// Template specializations for GetElement
	template<> float Json::GetElement<float>(const std::string& key) const;
	template<> bool Json::GetElement<bool>(const std::string& key) const;
	template<> std::string Json::GetElement<std::string>(const std::string& key) const;

}
#endif