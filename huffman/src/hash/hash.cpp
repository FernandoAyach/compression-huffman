#include <cmath>

#include "../../include/hash.h"

HashTable::HashTable(int m) : m(m) {
    this->table = new Cell*[m];
    for(int i = 0; i < m; i++) table[i] = nullptr;
}

HashTable::~HashTable() {
    delete[] table;
}

void HashTable::insert(uint8_t asciiCode, string huffCode) {
    table[h(asciiCode)] = new Cell(asciiCode, huffCode, table[h(asciiCode)]);
}

Cell* HashTable::get(int x) {
    Cell* target = table[h(x)];

    while(target != nullptr && target->asciiCode != x) {
        target = target->next;
    }

    return target;
}

int HashTable::size() {
    int size = 0;

    for(int i = 0; i < m; i++) {
        Cell *p = table[i];
        while(p != nullptr) {
            size++;
            p = p->next;
        }
    }

    return size;
}

int HashTable::h(int x) {
  double A = (sqrt(5) - 1) / 2;
  double fraction = A * x - (int)(A * x);
  int result = m * fraction;
  return result;
}