#pragma once
#include <cstdint>
#include <string>

using std::string;

class Cell {
  friend class HashTable;
  
public:
  Cell(int asciiCode, string huffCode, Cell *next = nullptr);

  string getHuffCode();
  
private:
  int asciiCode;
  string huffCode;
  Cell *next;
};