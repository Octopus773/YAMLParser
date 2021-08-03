//
// Created by cbihan on 03/08/2021.
//

#include <Tree.hpp>
#include <Parser.hpp>
#include <Utils.hpp>

void slt();

int main(int ac, char **av)
{
	YAML::Tree testParser = YAML::parser(
		R"(re: '[re'
t: 2
k: "re"
e: )");

	testParser.hi();
}