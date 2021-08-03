//
// Created by cbihan on 03/08/2021.
//

#include "Tree.hpp"

#include <utility>

namespace YAML
{
	void Tree::addValue(const std::string &key, std::pair<Datatype, std::string> value)
	{
		this->_root.addValue(key, std::move(value));
	}

	void Tree::addChild(Node child)
	{
		this->_root.addChild(std::move(child));
	}

	Tree::Tree()
		: _indentSize(2),
		  _indentType(IndentType::Space)
	{
		this->_root.setName("root");
	}
}