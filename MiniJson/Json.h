#pragma once
#ifndef __MINIJESON_JSON_H__
#define	__MINIJESON_JSON_H__

#include <iostream>
#include <string>
#include <map>
#include <memory>

#include "JsonBaseType.h"


namespace MiniJson
{
	class Json
	{
	private:
		// Private members and methods can be declared here
		std::map<std::string, std::unique_ptr<JsonBaseType>> m_Elements_map;

		template <typename T>
		T GetElement(const std::string& key) const;

	public:
		Json();
		
		template <typename T>
		T& emplace(const std::string& key, const T& val);

		JsonBaseType& operator[](const std::string& key);

		JsonBaseType& at(const std::string& key);
		
	};
	
	// Template specializations for GetElement
	template<> 
	float Json::GetElement<float>(const std::string& key) const;
	
	template<>
	bool Json::GetElement<bool>(const std::string& key) const;
	
	template<>
	std::string Json::GetElement<std::string>(const std::string& key) const;
}
#endif