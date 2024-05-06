// valgrind --leak-check=full --show-reachable=yes --track-fds=yes ./programa <parâmetros>
// g++ /Users/ayach/git/huffman-ed/huffman/src/*.cpp -Wall -pedantic -std=c++11 -o main

/**************************************************
*
* Fernando Ribeiro Ayach
* Trabalho de Estruturas de Dados
* Professor(a): Diego Rubert Padilha
*
*/

#include <iostream>
#include "../include/heap.h"
#include <cerrno> 

#define MAX 256

using namespace std;

void readInput(vector<int>& letters, vector<int>& freq);
Node* buildHuffmanTree();

int main(int argc, char** argv) {
    vector<int> freq(MAX, 0);
    vector<int> letters;

    readInput(letters, freq);
    buildHuffmanTree(); 
}

void readInput(vector<int>& letters, vector<int>& freq) {
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

Node* buildHuffmanTree() {
    return nullptr;
}