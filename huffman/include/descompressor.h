#include <iostream>
#include <cerrno>
#include "../include/heap.h"
#include "../include/hash.h"
#include "../include/buffer.h"

#define MAX 256

using std::cout;

class Decompressor {
public:
    Decompressor(const char* in, const char* out);
    ~Decompressor();

    void decompress();

private:
    void readInput();
    void buildHuffmanTree();
    void storeCodesInHash();
    void getCodes(Node *u);
    void getTreeCodes(Node *u);
    void writeCompressedArchive();

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