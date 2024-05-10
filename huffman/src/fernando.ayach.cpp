// valgrind --leak-check=full --show-reachable=yes --track-fds=yes ./programa <parâmetros>
// g++ /Users/ayach/git/huffman-ed/huffman/src/*.cpp /Users/ayach/git/huffman-ed/huffman/src/heap/*.cpp /Users/ayach/git/huffman-ed/huffman/src/node/*.cpp /Users/ayach/git/huffman-ed/huffman/src/hash/*.cpp /Users/ayach/git/huffman-ed/huffman/src/cell/*.cpp -Wall -pedantic -std=c++11 -o main

/**************************************************
 *
 * Fernando Ribeiro Ayach
 * Trabalho de Estruturas de Dados
 * Professor(a): Diego Rubert Padilha
 *
 */

#include <iostream>
#include <cerrno>
#include "../include/heap.h"
#include "../include/hash.h"

#define MAX 256

using namespace std;

void readInput(vector<uint8_t> &letters, vector<int> &freq);
Node* buildHuffmanTree(vector<uint8_t> letters, vector<int> freq);
void storeCodesInHash(Node *root);
void getCodes(HashTable *hashTable, Node *u, vector<int>& stack, bool left = true);

int main(int argc, char **argv)
{
    vector<int> freq(MAX, 0);
    vector<uint8_t> letters;
    Node *root;

    readInput(letters, freq);
    root = buildHuffmanTree(letters, freq);
    storeCodesInHash(root);
}

void readInput(vector<uint8_t> &letters, vector<int> &freq)
{
    FILE *in;
    in = fopen("./io/exemplo.txt", "r");

    if (in == nullptr)
    {
        cout << "Erro ao abrir o arquivo: " << strerror(errno) << endl;
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
        cout << (char)letters[i] << " " << freq[letters[i]] << endl;

    fclose(in);
}

Node *buildHuffmanTree(vector<uint8_t> letters, vector<int> freq){
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

    return heap->min();
}

void storeCodesInHash(Node *root) {
    HashTable *hashTable = new HashTable(MAX);
    vector<int> stack;
    getCodes(hashTable, root, stack);
}

void getCodes(HashTable *hashTable, Node *u, vector<int>& stack, bool left) {
    if (u->leaf()) {
        printf("%c %d: ", u->code(), u->freq());
        string huff = "";
        for(auto bit : stack) {
            huff += (bit == 0) ? '0' : '1';
        }
        printf("%s\n", huff.c_str());
        
        hashTable->insert(u->code(), huff);
        printf("%s\n", hashTable->get(u->code())->getHuffCode().c_str());
        return;
    }

    stack.push_back(left ? 0 : 1);

    getCodes(hashTable, u->left(), stack);

    stack.pop_back();
    stack.push_back(1);

    getCodes(hashTable, u->right(), stack, false);
    stack.pop_back();
}