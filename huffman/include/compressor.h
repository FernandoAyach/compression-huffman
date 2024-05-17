#include <iostream>
#include <cerrno>
#include "../include/heap.h"
#include "../include/hash.h"
#include "../include/buffer.h"

#define MAX 256

using std::cout;

class Compressor {
public:
    Compressor(const char* in, const char* out);
    ~Compressor();

    void compress();
    void readInput();
    void buildHuffmanTree();
    void storeCodesInHash();
    void getCodes(Node *u);
    void getTreeCodes(Node *u);
    void writeCompressedArchive();

private:
    vector<int> freq;
    vector<int> stack;
    vector<uint8_t> letters;
    vector<uint8_t> bitsTree;
    Node *root;
    HashTable *hashTable;

    FILE* in;
    FILE* out;
    const char* origin;
    const char* destiny;
};