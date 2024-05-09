#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include "node.h"

using std::vector;

class MinHeap {
public:
  MinHeap();            
  ~MinHeap();           
  size_t size();        
  void insert(Node *n); 
  Node* extract();
  Node* getMin();

private:
  vector<Node *> v;                    
  void up(unsigned int i);             
  void down(unsigned int i);           
  void swap(unsigned int i, unsigned int j);
  unsigned int parent(unsigned int i); 
  unsigned int left(unsigned int i); 
  unsigned int right(unsigned int i);
};