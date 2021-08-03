cmake_minimum_required(VERSION 3.19)
project(YAMLParser)

set(CMAKE_CXX_STANDARD 20)

if (CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -Wshadow -Wno-unused-parameter -W -g")
endif ()
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(SOURCES
	src/Tree.cpp
	src/Tree.hpp
	src/Parser.cpp
	src/Parser.hpp
	src/Node.cpp
	src/Node.hpp
	src/Utils.cpp
	src/Utils.hpp
	)

include_directories(src)

add_library(YAMLParser ${SOURCES})

add_executable(YAMLTestBin tests/main.cpp)
target_link_libraries(YAMLParser)