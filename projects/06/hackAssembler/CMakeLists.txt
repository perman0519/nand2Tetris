cmake_minimum_required(VERSION 3.25)
project(hackAssembler)

set(CMAKE_CXX_STANDARD 14)

add_executable(hackAssembler
        main.cpp
        HackAssembler.hpp
        Parser.hpp
        Parser.cpp
        SymbolTable.cpp
        SymbolTable.hpp
        Code.cpp
        Code.hpp)
