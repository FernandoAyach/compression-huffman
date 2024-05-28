/**************************************************
 *
 * Fernando Ribeiro Ayach
 * Trabalho de Estruturas de Dados
 * Professor(a): Diego Rubert Padilha
 *
 */

#include "../include/compressor.h"
#include "../include/decompressor.h"
#include <cstring>

int main(int argc, char **argv) {
    if(argv[1][0] == 'c') {
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