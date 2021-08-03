//
// Created by cbihan on 03/08/2021.
//

#include "Parser.hpp"
#include "Tree.hpp"

namespace YAML
{
	Tree parser(const std::string &YAMLString)
	{
		Tree tree{};
		int currentIndentLevel = 0;
		tree.indentSize = Utils::getIndentLevel(YAMLString);
		tree.indentType = IndentType::Space;
		std::vector<std::string> lines = Utils::splitStr(YAMLString, '\n');

		for (auto line : lines) {
			if (line.empty()) {
				continue;
			}

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