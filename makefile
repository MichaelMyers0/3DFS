CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++11 -fpermissive
net.o:net.c
	$(CXX) $(CXXFLAGS) -g -O -c $< -o $@
main:main.c
	$(CXX) $(CXXFLAGS) -g -O $< -o $@

