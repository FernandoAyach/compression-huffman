#include <cstddef>
#include <cstdint>
#include <vector>
#include "node.h"

using std::vector;

class MinHeap {
public:
  MinHeap();            // Construtor padrão
  ~MinHeap();           // Destrutor padrão
  size_t size();        // Tamanho da heap
  void insert(Node *n); // Inserir elemento
  Node *extract();      // Remover (menor) elemento

private:
  vector<Node *> v;                    // Elementos
  void up(unsigned int i);             // Sobe
  void down(unsigned int i);           // Desce
  void swap(unsigned int i, unsigned int j);
  unsigned int parent(unsigned int i); // Pai
  unsigned int left(unsigned int i);   // Filho esquerdo
  unsigned int right(unsigned int i);  // Filho direito
};