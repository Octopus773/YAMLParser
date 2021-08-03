//
// Created by cbihan on 03/08/2021.
//

#include "Node.hpp"

#include <utility>

namespace YAML
{

	void Node::setName(std::string name)
	{
		this->_name = std::move(name);
	}

	const std::string &Node::getName() const
	{
		return this->_name;
	}

	void Node::addValue(const std::string& name, std::pair<Datatype, std::string> value)
	{
		this->_values[name] = std::move(value);
	}

	void Node::addChild(Node child)
	{
		this->_children.emplace_back(std::move(child));
	}
}