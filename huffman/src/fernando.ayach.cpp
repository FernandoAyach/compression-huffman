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
void getCodes(HashTable *hashTable, Node *u);

int main(int argc, char **argv)
{
    vector<int> freq(MAX, 0);
    vector<uint8_t> letters;
    Node *root;

    readInput(letters, freq);
    root = buildHuffmanTree(letters, freq);
    printf("%d\n", root->freq());
    printf("%d %d\n", root->left()->freq(), root->right()->freq());
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

    printf("NO FINAL: %d\n", heap->min()->freq());
    return heap->min();
}

void storeCodesInHash(Node *root)
{
    HashTable *hashTable = new HashTable(MAX);
    getCodes(hashTable, root);
}

void getCodes(HashTable *hashTable, Node *u) {
    // USAR UMA PILHA
    if (u->leaf()) {
        printf("%c\n", u->code());
        return;
    }

    getCodes(hashTable, u->left());
    getCodes(hashTable, u->right());
}