# Variables
CXX = g++
CXXFLAGS = -Wall -g $(shell pkg-config --cflags opencv4)
LDFLAGS = $(shell pkg-config --libs opencv4)

# Target executable name
TARGET = toAscii

# Source files
SRCS = toAscii.cpp

# Default rule
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

# Clean rule
clean:
	rm -f $(TARGET)
