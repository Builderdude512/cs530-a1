
CXX=g++

CXXFLAGS=-Wall -Wextra -std=c++17

TARGET=xed

SOURCES=main.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)
