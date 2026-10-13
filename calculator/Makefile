CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
TARGET = calc
SRCS = main.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)
