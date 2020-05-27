cmake_minimum_required(VERSION 3.16)
project(query_process_ng)

set(CMAKE_CXX_STANDARD 11)

add_executable(
        query_process_ng
        main.cpp main.h
        src/query_result.cpp src/query_result.h
        src/text_query.cpp src/text_query.h
        src/Query_base.cpp src/Query_base.h
        src/Query.h src/Query.cpp
        src/WordQuery.h src/WordQuery.cpp
        src/NotQuery.h src/NotQuery.cpp
        src/BinaryQuery.cpp src/BinaryQuery.h)