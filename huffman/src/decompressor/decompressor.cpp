#include "../../include/decompressor.h"
#include "../../include/buffer.h"

Decompressor::Decompressor(const char* in, const char* out) {
    this->origin = in;
    this->destiny = out;
    this->in = fopen(in, "r");
    this->out = fopen(out, "w");
}

Decompressor::~Decompressor() {
    fclose(in);
    fclose(out);
}

void Decompressor::decompress() {
    printf("DESCOMPACTACAO:\n");

    fread(&k, sizeof(uint16_t), 1, in);

    printf("K: %d\n", k);

    fread(&t, sizeof(uint32_t), 1, in);

    printf("T: %d\n", t);

    uint8_t letter;
    printf("Letras pré-ordem: ");
    for(int i = 0; i < k; i++) {
        fread(&letter, sizeof(uint8_t), 1, in);
        lettersPreOrder.push_back(letter);
        printf("%c ", lettersPreOrder[i]);
    }
    printf("\n");
}