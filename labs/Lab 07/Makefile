TARGET = a.out
SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h*)
OBJECTS = $(SOURCES:%.cpp=%.o)
CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -Iinclude
LDFLAGS = 

.PHONY: all clean

all: $(TARGET)

clean:
	$(RM) src/*.o
	$(RM) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $(OBJECTS) $(LDFLAGS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

