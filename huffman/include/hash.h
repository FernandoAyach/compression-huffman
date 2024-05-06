#include "./cell.h"

class HashTable {
public:
  HashTable(int size);
  ~HashTable();
  void insert(int asciiCode, u_int8_t huffCode);
  bool search(int x);
  int size();
  
private:
  int h(int x);
  int m;
  Cell **table;
};

