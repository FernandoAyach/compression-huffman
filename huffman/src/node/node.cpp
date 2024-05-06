#include "../../include/node.h"

Node::Node(int f, uint8_t c, Node *l = nullptr, Node *r = nullptr) {
    this->f = f;
    this->c = c;
    this->l = l;
    this->r = r;
}

Node::Node(int f = 0, Node *l = nullptr, Node *r = nullptr) {
    this->f = f;
    this->c = 0;
    this->l = l;
    this->r = r;
}

int Node::freq() const {
    return this->f;
};

uint8_t Node::code() const {
    return this->c;
}

Node* Node::left() {
    return this->l;
}

Node* Node::right() {
    return this->r;
}

bool Node::leaf() const {
    return this->l == nullptr && this->r == nullptr;
}; 