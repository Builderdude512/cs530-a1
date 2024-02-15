
# Connor Shands-Sparks
# cssc4022
# CS 530-05, Spring2024
# Program Assignment #1
# main.cpp


CXX=g++

CXXFLAGS=-Wall -Wextra -std=c++17

TARGET=xed

SOURCES=main.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)
