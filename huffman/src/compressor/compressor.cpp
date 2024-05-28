#include "../../include/compressor.h"
#include "../../include/buffer.h"

Compressor::Compressor(const char* in, const char* out) : freq(MAX, 0) {
    this->origin = in;
    this->destiny = out;
    this->in = fopen(in, "r");
    this->out = fopen(out, "w");
}

Compressor::~Compressor() {
    fclose(in);
    fclose(out);
    killHuffman(root);
    delete hashTable;
    delete heap;
}

void Compressor::killHuffman(Node* u) {
    if(u == nullptr) return;

    killHuffman(u->left());
    killHuffman(u->right());
    delete u;
}

void Compressor::compress() {
    readInput();
    heap = new MinHeap();
    buildHuffmanTree();
    hashTable = new HashTable(letters.size());
    storeCodesInHash();
    getTreeCodes(root);
    writeCompressedArchive();
    printf("Arquivo comprimido com sucesso!\n");
}

void Compressor::readInput() {
    if (in == nullptr || out == nullptr) {
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
}

void Compressor::buildHuffmanTree(){
    this->heap = new MinHeap();

    for (auto l : letters) {
        Node *n = new Node(l, freq[l]);
        heap->insert(n);
    }

    Node *a, *b, *c;

    while (heap->size() != 1) {
        a = heap->extract();
        b = heap->extract();

        c = new Node(0, a->freq() + b->freq(), a, b);
        heap->insert(c);
    }

    root = heap->min();
}

void Compressor::storeCodesInHash() {
    vector<int> stack;
    getCodes(root);
}

void Compressor::getCodes(Node *u) {
    if (u->leaf()) {
        string huff = "";
        for(auto bit : stack) {
            huff += (bit == 0) ? '0' : '1';
        }
        
        hashTable->insert(u->code(), huff);
        lettersPreOrder.push_back(u->code());
        return;
    }

    stack.push_back(0);

    getCodes(u->left());

    stack.pop_back();
    stack.push_back(1);

    getCodes(u->right());
    stack.pop_back();
}

void Compressor::getTreeCodes(Node *u) {
    if (u->leaf()) {
        bitsTree.push_back(1);
        return;
    }

    bitsTree.push_back(0);

    getTreeCodes(u->left());
    getTreeCodes(u->right());
}

void Compressor::writeCompressedArchive() {
    in = fopen(origin, "r");
    Buffer buffOut(out), buffIn(in);
    uint16_t k = letters.size();

    fwrite(&k, sizeof(uint16_t), 1, out);
    uint32_t t = 0;

    for (int i = 0; i < letters.size(); i++) {
        t += freq[letters[i]];
    }

    fwrite(&t, sizeof(uint32_t), 1, out);

    for (int i = 0; i < lettersPreOrder.size(); i++) {
        fwrite(&lettersPreOrder[i], sizeof(uint8_t), 1, out);
    }

    for (int i = 0; i < bitsTree.size(); i++) {
        buffOut.add(bitsTree[i]);
    }

    int caracter;
    while ((caracter = fgetc(in)) != EOF) {
       string huffCode = hashTable->get(caracter)->getHuffCode();
       for(auto bit : huffCode) {
            buffOut.add(bit == '1' ? 1 : 0);
       }
    }
    buffOut.flush();
    fclose(in);
}
