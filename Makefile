CXX = g++
CXXFLAGS = -std=c++11 -Wall

all:
	bison -d parser.y -o parser.tab.cpp
	flex -o lex.yy.c classes.l
	$(CXX) $(CXXFLAGS) parser.tab.cpp lex.yy.c main.cpp relatorio_erros.cpp enum_genset.cpp -o sintatico

clean:
	rm -f lex.yy.c parser.tab.cpp parser.tab.hpp sintatico
