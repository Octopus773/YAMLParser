cmake_minimum_required(VERSION 3.19)
project(YAMLParser)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
	src/Parser.cpp
	src/Parser.hpp
	)

include_directories(src)

add_executable(YAMLParserTestBin ${SOURCES} tests/main.cpp)