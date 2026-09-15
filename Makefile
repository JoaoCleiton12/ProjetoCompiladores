CXX = g++
CXXFLAGS = -std=c++11 -Wall

all:
	flex -o lex.yy.cc classes.l
	$(CXX) $(CXXFLAGS) lex.yy.cc main.cpp -o classes

clean:
	rm -f lex.yy.cc classes