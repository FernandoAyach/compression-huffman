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

    Buffer buffer(in);

    root = nullptr;
    int i = 0;
    buildHuffman(root, buffer, i, true);
    printTree(root);
    writeDecompressedArchive(root, buffer, i);
}

void Decompressor::printTree(Node *u) {
    if (u->leaf()) {
        printf("%c\n", u->code());
        return;
    }

    printTree(u->left());
    printTree(u->right());
}

void Decompressor::buildHuffman(Node* &u, Buffer &buffer, int &i, bool left) {
    // Se o índice chegou ao fim da lista de letras, retorna.
    if (i == lettersPreOrder.size()) return;

    // Cria um novo nó.
    Node* n = new Node();

    // Se o bit atual do buffer é 1, é uma folha, então define o código do nó.
    if (buffer.getBit() == 1) {
        n->setCode(lettersPreOrder[i++]);
        
        if (root == nullptr) {
            u = root = n;
            printf("Colocou a raiz: %c\n", u->code());
        } else if (left) {
            u->setLeft(n);
            printf("Esquerda: %c\n", u->left()->code());
        } else {
            u->setRight(n);
            printf("Direita: %c\n", u->right()->code());
        }
        return;
    }

    // Se a raiz ainda não foi definida, define a raiz.
    if (root == nullptr) {
        u = root = n;
        printf("Colocou a raiz\n");
    } else {
        if (left) {
            u->setLeft(n);
            printf("Esquerda\n");
        } else {
            u->setRight(n);
            printf("Direita\n");
        }
    }

    // Recursivamente constrói a subárvore esquerda e direita.
    buildHuffman(n, buffer, i, true);
    buildHuffman(n, buffer, i, false);
}

void Decompressor::writeDecompressedArchive(Node* u, Buffer &buffer, int &i) {
    if(i == t) return;

    if (u->leaf()) {
        printf("%c\n", u->code());
        i++;
        uint8_t code = u->code();
        fwrite(&code, sizeof(uint8_t), 1, out);

        writeDecompressedArchive(root, buffer, i);
        return;
    }

    uint8_t bit = buffer.getBit();
    printf("%d\n", bit);

    if(bit == 0) {
        writeDecompressedArchive(u->left(), buffer, i);
    } else {
        writeDecompressedArchive(u->right(), buffer, i);
    }
}