cmake_minimum_required(VERSION 3.10)
project(ProjetoCompiladores CXX)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 17)

# Bison >= 3.6 (necessário para %define parse.error custom)
find_package(BISON 3.6 REQUIRED)
find_package(FLEX REQUIRED)

BISON_TARGET(Parser parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.tab.cpp
             DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/parser.tab.hpp)
FLEX_TARGET(Lexer classes.l ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cc)
ADD_FLEX_BISON_DEPENDENCY(Lexer Parser)

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(sintatico
    ${BISON_Parser_OUTPUTS}
    ${FLEX_Lexer_OUTPUTS}
    main.cpp
    relatorio_erros.cpp
    enum_genset.cpp)
