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

	std::vector<std::string> splitStr(const std::string &str, char delim)
	{
		std::vector<std::string> strings;
		std::istringstream f(str);
		std::string buffer;

		while (std::getline(f, buffer, delim)) { ;
			strings.push_back(buffer);
		}
		if (str.back() == delim) {
			strings.emplace_back("");
		}
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

	bool isEquals(const std::string &a, const std::string &b)
	{
		return std::equal(a.begin(), a.end(),
		                  b.begin(), b.end(),
		                  [](char a, char b) {
			                  return std::tolower(a) == std::tolower(b);
		                  });
	}

}