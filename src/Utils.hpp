//
// Created by cbihan on 03/08/2021.
//

#pragma once

#include <string>
#include <sstream>
#include <vector>

namespace YAML
{
	enum IndentType
	{
		Space,
		Tab
	};

	enum Datatype
	{
		Null,
		Integer,
		Double,
		Boolean,
		String,
		List,
		Dictionary
	};

	namespace Utils
	{
		unsigned int getIndentLevel(const std::string &yamlString);
		std::vector<std::string> splitStr(const std::string &str, char delim);

		//! @brief trim left end
		void lTrim(std::string &s);

		//! @brief trim right end
		void rTrim(std::string &s);

		//! @brief trim from both ends
		void trim(std::string &s);

		//! @brief trim left end (copying)
		std::string lTrimCopy(std::string s);

		//! @brief trim right end (copying)
		std::string rTrimCopy(std::string s);

		//! @brief trim from both ends (copying)
		std::string trimCopy(std::string s);

		//! @brief Compares 2 string case insensitive
		bool isEquals(const std::string &a, const std::string &b);

		//! @brief return true if parsing has been successful result ill be in i
		template<typename T>
		bool tryParse(const std::string &s, T &f)
		{
			std::istringstream iss(s);

			iss >> std::noskipws >> f;
			return iss.eof() && !iss.fail();
		}

	}
}