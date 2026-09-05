cmake_minimum_required(VERSION 3.10)
project(ProjetoCompiladores)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 17)

find_package(FLEX REQUIRED)
FLEX_TARGET(Lexer classes.l ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cc COMPILE_FLAGS "-+")
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(classes ${FLEX_Lexer_OUTPUTS})