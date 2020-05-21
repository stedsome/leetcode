CXX = g++
CXXFLAGS = -Wall -g -std=c++11

objects = e1180 m1058 m761
all: $(objects)

$(objects): %: %.cpp
		$(CXX) $(CXXLAGS) -o $@ $<
