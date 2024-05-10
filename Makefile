# Nome do programa de saída
TARGET = main

# Compilador
CC = g++

# Opções de compilação
CFLAGS = -Wall -pedantic -std=c++11

# Diretórios dos arquivos de origem
SRCDIR = /Users/ayach/git/huffman-ed/huffman/src
HEAPDIR = /Users/ayach/git/huffman-ed/huffman/src/heap
NODEDIR = /Users/ayach/git/huffman-ed/huffman/src/node
HASHDIR = /Users/ayach/git/huffman-ed/huffman/src/hash
CELLDIR = /Users/ayach/git/huffman-ed/huffman/src/cell

# Arquivos de origem
SRCS = $(wildcard $(SRCDIR)/*.cpp) \
       $(wildcard $(HEAPDIR)/*.cpp) \
       $(wildcard $(NODEDIR)/*.cpp) \
       $(wildcard $(HASHDIR)/*.cpp) \
       $(wildcard $(CELLDIR)/*.cpp)

# Lista de objetos
OBJS = $(SRCS:.cpp=.o)

# Comando padrão (compilação do programa)
all: $(TARGET)

# Regra para compilar os arquivos de origem em objetos
%.o: %.cpp $(CC) $(CFLAGS) -c $< -o $@

# Regra para linkar os objetos e gerar o executável
$(TARGET): $(OBJS) $(CC) $(OBJS) -o $(TARGET)

# Regra para limpar os arquivos gerados durante a compilação
clean: $(RM) $(OBJS) $(TARGET)
