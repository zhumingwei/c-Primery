cmake_minimum_required(VERSION 3.16)
project(main)

set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp src/text_query.cpp src/text_query.h src/query_result.cpp src/query_result.h main.h)