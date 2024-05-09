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
  write();
  Node* min = this->v[0];
  v[0] = v[size() - 1];
  v.pop_back();
  down(0);

  write();
  return min;
}

void MinHeap::write() {
  for(int i = 0; i < size(); i++) printf("(%d %c) ", v[i]->freq(), v[i]->code());
  printf("\n");
}

Node* MinHeap::min() {
  return v[0];
}

void MinHeap::up(unsigned int i) {
  while(v[i]->freq() < v[parent(i)]->freq()) {
    swap(i, parent(i));
    i = parent(i);
  }
}

void MinHeap::down(unsigned int i) {
  int e = left(i), d = right(i), min = i;

  min = e < size() && v[e]->freq() < v[min]->freq() ? e : min;
  min = d < size() && v[d]->freq() < v[min]->freq() ? d : min;

  if(min != i) {
    swap(i, min);
    down(min);
  }
}

void MinHeap::swap(unsigned int i, unsigned int j) {
  Node* aux = v[i];
  v[i] = v[j];
  v[j] = aux;
}

unsigned int MinHeap::parent(unsigned int i) {
  return i == 0 ? i : (i - 1) / 2;
}

unsigned int MinHeap::left(unsigned int i) {
  return 2 * (i + 1) - 1;
}

unsigned int MinHeap::right(unsigned int i) {
  return 2 * (i + 1);
}