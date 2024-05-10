// valgrind --leak-check=full --show-reachable=yes --track-fds=yes ./programa <parâmetros>
// g++ /Users/ayach/git/huffman-ed/huffman/src/compressor/*.cpp /Users/ayach/git/huffman-ed/huffman/src/*.cpp /Users/ayach/git/huffman-ed/huffman/src/heap/*.cpp /Users/ayach/git/huffman-ed/huffman/src/node/*.cpp /Users/ayach/git/huffman-ed/huffman/src/hash/*.cpp /Users/ayach/git/huffman-ed/huffman/src/cell/*.cpp /Users/ayach/git/huffman-ed/huffman/src/buffer/*.cpp -Wall -pedantic -std=c++11 -o main

/**************************************************
 *
 * Fernando Ribeiro Ayach
 * Trabalho de Estruturas de Dados
 * Professor(a): Diego Rubert Padilha
 *
 */

#include "../include/compressor.h"

//void createCompressedArchive(HashTable* hashTable, vector<uint8_t> letters, FILE* in, FILE* out);

int main(int argc, char **argv) {
    Compressor* compressor = new Compressor();
    compressor->compress();
}

// void createCompressedArchive(HashTable* hashTable, vector<uint8_t> letters, FILE* in, FILE* out) {
//     uint16_t k = letters.size();
//     uint32_t t;
// }