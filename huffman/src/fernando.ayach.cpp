// valgrind --leak-check=full --show-reachable=yes --track-fds=yes ./programa <parâmetros>
// g++ 
// /Users/ayach/git/huffman-ed/huffman/src/*.cpp 
// /Users/ayach/git/huffman-ed/huffman/src/heap/*.cpp 
// /Users/ayach/git/huffman-ed/huffman/src/node/*.cpp 
// -Wall -pedantic -std=c++11 -o main

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

#define MAX 256

using namespace std;

void readInput(vector<uint8_t>& letters, vector<int>& freq);
Node* buildHuffmanTree(vector<uint8_t> letters, vector<int> freq);

int main(int argc, char** argv) {
    vector<int> freq(MAX, 0);
    vector<uint8_t> letters;

    readInput(letters, freq);
    buildHuffmanTree(letters, freq); 
}

void readInput(vector<uint8_t>& letters, vector<int>& freq) {
    FILE * in;
    in = fopen("./io/exemplo.txt", "r");

    if (in == nullptr) {
        cout << "Erro ao abrir o arquivo: " << strerror(errno) << endl;
        return;
    }

    int c;
    while ((c = fgetc(in)) != EOF) {
        if(freq[c] == 0) letters.push_back(c);
        freq[c]++;
    }

    for(int i = 0; i < letters.size(); i++) 
        cout << (char) letters[i] << " " << freq[letters[i]] << endl;
    
    fclose(in);
}

Node* buildHuffmanTree(vector<uint8_t> letters, vector<int> freq) {
    MinHeap heap = MinHeap();

    printf("Criou a heap\n");

    for(auto l : letters) {
        Node *n = new Node(l);
        printf("Node %c\n", n->code());
        heap.insert(n);
        printf("Inseriu %c\n", l);
    }

    // while(heap.size() != 1) {
    //     Node *a, *b, *c;
    //     a = heap.extract();
    //     b = heap.extract();

    //     c = new Node(0, a->freq() + b->freq(), a, b);
    //     heap.insert(c);
    // }

    printf("%d\n", heap.getMin()->freq());
    
    
    return nullptr;
}