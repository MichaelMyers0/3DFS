CXX=g++
CXXFLAGS=-Wall -Wextra -std=c++11 -fpermissive
net.o:net.c
	$(CXX) $(CXXFLAGS) -g -O -c $< -o $@
fs_user_dump.o:fs_user_dump.c
	$(CXX) $(CXXFLAGS) -g -O -c $< -o $@
abars:abars.c
	$(CXX) $(CXXFLAGS) -g -O $< -o $@
main:main.c fs_user_dump.o net.o
	$(CXX) $(CXXFLAGS) -g -O $^ -o $@

