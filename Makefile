CXX = g++
SRC_DIR = /Users/ayach/git/huffman-ed/huffman/src
COMPRESSOR_SRC_DIR = $(SRC_DIR)/compressor
DECOMPRESSOR_SRC_DIR = $(SRC_DIR)/decompressor
HEAP_SRC_DIR = $(SRC_DIR)/heap
NODE_SRC_DIR = $(SRC_DIR)/node
HASH_SRC_DIR = $(SRC_DIR)/hash
CELL_SRC_DIR = $(SRC_DIR)/cell
BUFFER_SRC_DIR = $(SRC_DIR)/buffer

SRCS := $(wildcard $(COMPRESSOR_SRC_DIR)/*.cpp) \
        $(wildcard $(DECOMPRESSOR_SRC_DIR)/*.cpp) \
        $(wildcard $(SRC_DIR)/*.cpp) \
        $(wildcard $(HEAP_SRC_DIR)/*.cpp) \
        $(wildcard $(NODE_SRC_DIR)/*.cpp) \
        $(wildcard $(HASH_SRC_DIR)/*.cpp) \
        $(wildcard $(CELL_SRC_DIR)/*.cpp) \
        $(wildcard $(BUFFER_SRC_DIR)/*.cpp)

OBJS := $(SRCS:.cpp=.o)
EXECUTABLE = main

CXXFLAGS = -Wall -pedantic -std=c++11

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE) $(OBJS)
