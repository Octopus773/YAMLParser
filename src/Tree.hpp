//
// Created by cbihan on 03/08/2021.
//

#pragma once

#include <iostream>
#include <fstream>

#include "Node.hpp"

namespace YAML
{
	class Tree
	{
	public:
		unsigned int indentSize;
		bool indentWithTabs;

		std::vector<Node> data;
	public:
		void parse(std::ifstream &file);

		void hi() {
			std::cout << "hello world !" << std::endl;
		};

	};
}