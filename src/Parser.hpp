//
// Created by cbihan on 03/08/2021.
//

#pragma once

#include <string>
#include "Tree.hpp"

namespace YAML
{
	Tree parser(const std::string &YAMLString);

	namespace Parser
	{
		std::pair<Datatype, std::string> getValue(const std::string &value);
	}

}