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
		unsigned int indentSize;
		IndentType indentType;

		std::vector<Node> data;
	public:
		void parse(std::ifstream &file);

		void hi() {
			std::cout << "hello world !" << std::endl;
		};

	};
}