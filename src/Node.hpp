//
// Created by cbihan on 03/08/2021.
//

#pragma once

#include <string>
#include <map>
#include <vector>

namespace YAML
{
	class Node
	{
	public:
		std::string name;
		bool isArray;
		std::map<std::string, std::pair<std::string, std::string>> values;
		std::vector<Node> childs;
	};


}