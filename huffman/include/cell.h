#pragma once
#include <cstdint>

class Cell {
  friend class HashTable;
  
public:
  Cell(int asciiCode, uint8_t huffCode, Cell *next = nullptr);
  
private:
  int asciiCode;
  uint8_t huffCode;
  Cell *next;
};