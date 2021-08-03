//
// Created by cbihan on 03/08/2021.
//

#pragma once

#include <iostream>
#include <fstream>

namespace YAML
{
	class Document
	{
	public:
		void parse(std::ifstream &file);

		void hi() {
			std::cout << "hello world !" << std::endl;
		};
	};
}