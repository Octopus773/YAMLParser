//
// Created by cbihan on 03/08/2021.
//

#pragma once

#include <string>
#include <map>
#include <vector>
#include "Utils.hpp"

namespace YAML
{
	class Node
	{
	private:
		std::string _name;
		bool _isList;
		std::map<std::string, std::pair<Datatype, std::string>> _values;
		std::vector<Node> _children;
	public:

		void setName(std::string name);
		[[nodiscard]] const std::string &getName() const;
		void addValue(const std::string& name, std::pair<Datatype, std::string> value);
		void addChild(Node child);
	};


}