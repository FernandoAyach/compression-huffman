#include "../../include/heap.h"

MinHeap::MinHeap() {}        

MinHeap::~MinHeap() {
  for(int i = 0; i < v.size(); i++) {
    delete v[i];
  }
}

size_t MinHeap::size() {
  return this->v.size();
}

void MinHeap::insert(Node *n) {
  this->v.push_back(n);
  up(v.size() - 1);
}

Node* MinHeap::extract() {
  Node* min = this->v[0];
  v[0] = v[size() - 1];
  down(0);

  return min;
}

void MinHeap::up(unsigned int i) {
  while(v[i]->freq() > v[parent(i)]->freq()) {
    swap(i, parent(i));
    i = parent(i);
  }
}

void MinHeap::down(unsigned int i) {
  int e = left(i), d = right(i), min = i;

  min = v[e]->freq() < v[min]->freq() ? e : min;
  min = v[d]->freq() < v[d]->freq() ? d : min;

  if(min != i) {
    swap(i, min);
    down(min);
  }
}

void MinHeap::swap(unsigned int i, unsigned int j) {
  int fAux = v[i]->freq();
  uint8_t cAux = v[i]->code();

  v[i]->f = v[j]->freq();
  v[i]->c = v[j]->code();

  v[j]->f = fAux;
  v[j]->c = cAux;
}

unsigned int MinHeap::parent(unsigned int i) {
  return (i - 1) / 2;
}

unsigned int MinHeap::left(unsigned int i) {
  return 2 * (i + 1) - 1;
}

unsigned int MinHeap::right(unsigned int i) {
  return 2 * (i + 1);
}