#include <cstddef>
#include <cstdint>
#include <vector>

using std::vector;

class Node {
  friend class MinHeap;
  
public:
  Node(int f, uint8_t c, Node *l = nullptr, Node *r = nullptr);
  Node(int f = 0, Node *l = nullptr, Node *r = nullptr);      
  int freq() const;
  uint8_t code() const;
  Node* left();         
  Node* right();        
  bool leaf() const;
  
private:
  int f;
  uint8_t c;
  Node *l;
  Node *r;
};
