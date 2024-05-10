#pragma once
#include "./cell.h"

class HashTable {
public:
  HashTable(int size);
  ~HashTable();
  void insert(uint8_t asciiCode, string huffCode);
  Cell* get(int x);
  int size();
  
private:
  int h(int x);
  int m;
  Cell **table;
};

