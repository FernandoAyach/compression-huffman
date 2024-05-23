// valgrind --leak-check=full --show-reachable=yes --track-fds=yes ./programa <parâmetros>

/**************************************************
 *
 * Fernando Ribeiro Ayach
 * Trabalho de Estruturas de Dados
 * Professor(a): Diego Rubert Padilha
 *
 */

// Comandos para executar o sistema:
// make run ARGS="c exemplo.txt exemplo.huff"
// make run ARGS="d exemplo.huff exemplo2.txt"

#include "../include/compressor.h"
#include "../include/decompressor.h"
#include <cstring>

int main(int argc, char **argv) {
    if(argv[1][0] == 'c') {
        printf("%c %s %s\n", argv[1][0], argv[2], argv[3]);
        Compressor* compressor = new Compressor(argv[2], argv[3]);
        compressor->compress();
        delete compressor;
        return 0;
    }
    
    Decompressor* decompressor = new Decompressor(argv[2], argv[3]);
    decompressor->decompress();
    delete decompressor;
    return 0;
}