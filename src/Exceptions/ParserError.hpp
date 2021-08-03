//
// Created by cbihan on 04/08/2021.
//

#pragma once

#include <exception>
#include <stdexcept>

namespace YAML::Exception
{
	class ParserError : public std::runtime_error
	{
	public:
		//! @brief Create a new parser exception
		explicit ParserError(const std::string &what)
			: std::runtime_error(what)
		{}

		//! @brief A parser exception is copy constructable
		ParserError(const ParserError &) = default;

		//! @brief A default destructor
		~ParserError() override = default;

		//! @brief A default assignment operator
		ParserError &operator=(const ParserError &) = default;
	};
}