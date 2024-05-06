// #include "../../include/hash.h"

// TabelaDispersao::TabelaDispersao(int tamanho) : m(tamanho) {
//     this->tabela = new Celula*[tamanho];
//     for(int i = 0; i < tamanho; i++) tabela[i] = nullptr;
// }

// TabelaDispersao::~TabelaDispersao() {
//     delete[] tabela;
// }

// void TabelaDispersao::insere(int x) {
//     tabela[h(x)] = new Celula(x, tabela[h(x)]);
// }

// bool TabelaDispersao::busca(int x) {
//     Celula* target = tabela[h(x)];

//     while(target != nullptr && target->chave != x) {
//         target = target->prox;
//     }

//     return target != nullptr;
// }

// bool TabelaDispersao::remove(int x) {
//     Celula *p = nullptr, *q = tabela[h(x)];

//     while(q != nullptr && q->chave != x) {
//         p = q;
//         q = q->prox;
//     }

//     if(q != nullptr) {
//         if(p != nullptr) p->prox = q->prox;
//         else tabela[h(x)] = q->prox;

//         delete q;

//         return true;
//     }

//     return false;
// }

// double TabelaDispersao::fator_carga() {
//     return elementos() / (double) m;
// }

// int TabelaDispersao::elementos() {
//     int size = 0;

//     for(int i = 0; i < m; i++) {
//         Celula *p = tabela[i];
//         while(p != nullptr) {
//             size++;
//             p = p->prox;
//         }
//     }

//     return size;
// }

// void TabelaDispersao::escreve() {
//     for(int i = 0; i < m; i++) {
//         Celula *p = tabela[i];
//         printf("%d ", i);
//         while(p != nullptr) {
//             printf("%d ", p->chave);
//             p = p->prox;
//         }
//         printf("\n");
//     }
//     printf("\n");
// };

// int TabelaDispersao::h(int x) {
// //   double A = (sqrt(5) - 1) / 2;
// //   double fraction = A * x - (int)(A * x);
// //   int result = m * fraction;
// //   return result;
//     return x % m;
// }