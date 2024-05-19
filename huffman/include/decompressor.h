#include <iostream>
#include <cerrno>
#include "../include/buffer.h"
#include "../include/node.h"

#define MAX 256

using std::cout;

class Decompressor {
public:
    Decompressor(const char* in, const char* out);
    ~Decompressor();

    void decompress();

private:
    void buildHuffman(Node* &u, Buffer &buffer, int &i, bool left);
    void writeDecompressedArchive(Node* u, Buffer &buffer, int &i);

    uint16_t k;
    uint32_t t;
    vector<uint8_t> lettersPreOrder;
    vector<uint8_t> bitsTree;
    Node* root;

    FILE* in;
    FILE* out;
    const char* origin;
    const char* destiny;
};