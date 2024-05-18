// valgrind --leak-check=full --show-reachable=yes --track-fds=yes ./programa <parâmetros>

/**************************************************
 *
 * Fernando Ribeiro Ayach
 * Trabalho de Estruturas de Dados
 * Professor(a): Diego Rubert Padilha
 *
 */

#include "../include/compressor.h"
#include "../include/decompressor.h"

int main(int argc, char **argv) {
    const char* arch1 = "/Users/ayach/git/huffman-ed/io/exemplo.txt";
    const char* arch2 = "/Users/ayach/git/huffman-ed/io/out.huff";
    const char* arch3 = "/Users/ayach/git/huffman-ed/io/exemplo2.txt";

    Compressor* compressor = new Compressor(arch1, arch2);
    compressor->compress();

    delete compressor;

    Decompressor* decompressor = new Decompressor(arch2, arch3);
    decompressor->decompress();
}