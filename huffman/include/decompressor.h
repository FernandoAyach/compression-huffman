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
    void readHeader(); 
    uint16_t k;
    uint32_t t;
    vector<uint8_t> lettersPreOrder;
    Node* root;

    FILE* in;
    FILE* out;
    const char* origin;
    const char* destiny;
};