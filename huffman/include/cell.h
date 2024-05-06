#include <cstdint>

class Cell {
  friend class HashTable;
  
public:
  Cell(int asciiCode, uint8_t huffCode, Cell *next = nullptr) : 
  asciiCode(asciiCode), huffCode(huffCode), next(next) { }
  
private:
  int asciiCode;
  uint8_t huffCode;
  Cell *next;
};