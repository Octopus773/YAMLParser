//
// Created by cbihan on 03/08/2021.
//

#pragma once

#include <iostream>
#include <fstream>

#include "Utils.hpp"
#include "Node.hpp"

namespace YAML
{
	class Tree
	{
	public:
		unsigned int _indentSize;
		IndentType _indentType;

		Node _root;
	public:

		void addValue(const std::string& key, std::pair<Datatype, std::string> value);
		void addChild(Node child);

		void hi() {
			std::cout << "hello world !" << std::endl;
		};

		Tree();
		Tree(const Tree &) = default;
		~Tree() = default;
		Tree &operator=(const Tree &) = default;

	};
}