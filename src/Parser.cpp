//
// Created by cbihan on 03/08/2021.
//

#include "Parser.hpp"
#include "Exceptions/ParserError.hpp"
#include "Tree.hpp"


void slt()
{
	std::cout << "eh oh!" << std::endl;
}

namespace YAML
{
	Tree parser(const std::string &YAMLString)
	{
		Tree tree{};
		int currentIndentLevel = 0;
		tree._indentSize = Utils::getIndentLevel(YAMLString);
		tree._indentType = IndentType::Space;
		std::vector<std::string> lines = Utils::splitStr(YAMLString, '\n');
		std::vector<std::string> keyValue;

		for (auto line : lines) {
			if (line.empty()) {
				continue;
			}
			keyValue = Utils::splitStr(line, ": ");
			if (keyValue.size() != 2) {
				throw Exception::ParserError(line);
			}
			tree.addValue(keyValue[0], Parser::getValue(keyValue[1]));
		}
		return tree;
	}

	namespace Parser
	{
		std::pair<Datatype, std::string> getValue(const std::string &value)
		{
			std::string valueTrimmed = Utils::trimCopy(value);

			if (valueTrimmed.empty()) {
				return std::make_pair(Datatype::Null, valueTrimmed);
			}
			if (valueTrimmed.front() == '[') {
				return std::make_pair(Datatype::List, valueTrimmed);
			}
			if (Utils::isEquals(valueTrimmed, "true")
				|| Utils::isEquals(valueTrimmed, "false")
				|| Utils::isEquals(valueTrimmed, "yes")
				|| Utils::isEquals(valueTrimmed, "no")
				|| Utils::isEquals(valueTrimmed, "on")
				|| Utils::isEquals(valueTrimmed, "off")) {
				return std::make_pair(Datatype::Boolean, valueTrimmed);
			}

			int i;
			if (Utils::tryParse(valueTrimmed, i)) {
				return std::make_pair(Datatype::Integer, valueTrimmed);
			}
			double d;
			if (Utils::tryParse(valueTrimmed, d)) {
				return std::make_pair(Datatype::Double, valueTrimmed);
			}
			return std::make_pair(Datatype::String, valueTrimmed);
		}
	}
}