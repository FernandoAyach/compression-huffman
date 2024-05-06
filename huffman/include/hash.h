#include "../../include/cell.h"

class HashTable {
public:
  HashTable(int size);
  ~HashTable();
  void insert(int x);
  bool search(int x);
  bool remove(int x);
  int size();
  
private:
  int h(int x);
  int m;
  Cell **table;
};

