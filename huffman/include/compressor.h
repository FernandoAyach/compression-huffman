#include <iostream>
#include <cerrno>
#include "../include/heap.h"
#include "../include/hash.h"
#include "../include/buffer.h"

#define MAX 256

using std::cout;

class Compressor {
public:
    Compressor();

    void compress();
    void readInput();
    void buildHuffmanTree();
    void storeCodesInHash();
    void getCodes(Node *u, bool left = true);

private:
    vector<int> freq;
    vector<int> stack;
    vector<uint8_t> letters;
    Node *root;
    HashTable *hashTable;
};