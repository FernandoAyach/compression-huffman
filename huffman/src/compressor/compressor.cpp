#include "../../include/compressor.h"

Compressor::Compressor() : freq(MAX, 0) {}

void Compressor::compress() {
    readInput();
    buildHuffmanTree();
    hashTable = new HashTable(letters.size());
    storeCodesInHash();
}

void Compressor::readInput() {
    FILE *in;
    in = fopen("./io/exemplo.txt", "r");

    if (in == nullptr)
    {
        cout << "Erro ao abrir o arquivo: " << strerror(errno) << "\n";
        return;
    }

    int c;
    while ((c = fgetc(in)) != EOF)
    {
        if (freq[c] == 0)
            letters.push_back(c);
        freq[c]++;
    }

    for (int i = 0; i < letters.size(); i++)
        cout << (char)letters[i] << " " << freq[letters[i]] << "\n";

    fclose(in);
}

void Compressor::buildHuffmanTree(){
    MinHeap* heap = new MinHeap();

    for (auto l : letters) {
        Node *n = new Node(l, freq[l]);
        heap->insert(n);
        printf("Inseriu %c\n", l);
    }

    Node *a, *b, *c;

    while (heap->size() != 1) {
        a = heap->extract();
        b = heap->extract();

        c = new Node(0, a->freq() + b->freq(), a, b);
        printf("NOVO NO HUFFMAN: (%d %c) (%d %c) (%d %c)\n", c->freq(), c->code(), c->left()->freq(), c->left()->code(), c->right()->freq(), c->right()->code());
        heap->insert(c);
    }
    heap->write();

    root = heap->min();
}

void Compressor::storeCodesInHash() {
    vector<int> stack;
    getCodes(root);
}

void Compressor::getCodes(Node *u, bool left) {
    if (u->leaf()) {
        string huff = "";
        for(auto bit : stack) {
            huff += (bit == 0) ? '0' : '1';
        }
        
        hashTable->insert(u->code(), huff);
        printf("%c %s\n", u->code(), hashTable->get(u->code())->getHuffCode().c_str());
        return;
    }

    stack.push_back(0);

    getCodes(u->left());

    stack.pop_back();
    stack.push_back(1);

    getCodes(u->right(), false);
    stack.pop_back();
}