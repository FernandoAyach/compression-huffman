// valgrind --leak-check=full --show-reachable=yes --track-fds=yes ./programa <parâmetros>

/**************************************************
 *
 * Fernando Ribeiro Ayach
 * Trabalho de Estruturas de Dados
 * Professor(a): Diego Rubert Padilha
 *
 */

#include "../include/compressor.h"

int main(int argc, char **argv) {
    const char* origin = "/Users/ayach/git/huffman-ed/io/exemplo.txt";
    const char* destiny = "../../io/exemplo (1).huff";

    Compressor* compressor = new Compressor(origin, destiny);
    compressor->compress();
}