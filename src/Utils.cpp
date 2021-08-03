//
// Created by cbihan on 03/08/2021.
//

#include <sstream>
#include "Utils.hpp"

namespace YAML::Utils
{
	unsigned int getIndentLevel(const std::string &yamlString)
	{
		return 2;
	}

	std::vector<std::string> splitStr(const std::string &str, char delimiter)
	{
		std::vector<std::string> strings;
		std::istringstream f(str);
		std::string buffer;

		while (std::getline(f, buffer, delimiter)) { ;
			strings.push_back(buffer);
		}
		if (str.back() == delimiter) {
			strings.emplace_back("");
		}
		return strings;
	}

	std::vector<std::string> splitStr(std::string str, const std::string &delimiter)
	{
		std::vector<std::string> strings;

		size_t pos = 0;
		while ((pos = str.find(delimiter)) != std::string::npos) {
			strings.emplace_back(str.substr(0, pos));
			str.erase(0, pos + delimiter.length());
		}
		strings.emplace_back(str);
		return strings;
	}

	void lTrim(std::string &s)
	{
		s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
			return !std::isspace(ch);
		}));
	}

	void rTrim(std::string &s)
	{
		s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
			return !std::isspace(ch);
		}).base(), s.end());
	}

	void trim(std::string &s)
	{
		lTrim(s);
		rTrim(s);
	}

	std::string lTrimCopy(std::string s)
	{
		lTrim(s);
		return s;
	}

	std::string rTrimCopy(std::string s)
	{
		rTrim(s);
		return s;
	}

	std::string trimCopy(std::string s)
	{
		trim(s);
		return s;
	}

	bool isEquals(const std::string &str1, const std::string &str2)
	{
		return std::equal(str1.begin(), str1.end(),
		                  str2.begin(), str2.end(),
		                  [](char a, char b) {
			                  return std::tolower(a) == std::tolower(b);
		                  });
	}

}