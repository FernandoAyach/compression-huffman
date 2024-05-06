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

#define MAX 256

using namespace std;

void countLetters(vector<int>& freq, FILE* in);

int main(int argc, char** argv) {
    FILE * in;
    vector<int> freq(MAX, 0);

    in = fopen ("../../io/exemplo.txt", "r");

    if (in == nullptr) {
        cout << "Erro ao abrir o arquivo." << endl;
        return 0;
    }

    countLetters(freq, in);

    fclose(in);
}

void countLetters(vector<int>& freq, FILE* in) {
    int c;
    while ((c = fgetc(in)) != EOF) {
        freq[c]++;
    }

    for(int i = 0; i < 256; i++) cout << i << " " << freq[i] << endl;
}