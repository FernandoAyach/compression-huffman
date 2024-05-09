#include "../../include/node.h"

Node::Node(uint8_t c, int f, Node *l, Node *r) {
    this->f = f;
    this->c = c;
    this->l = l;
    this->r = r;
}

Node::Node(int f, Node *l, Node *r) {
    this->f = f;
    this->c = -1;
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

void Node::setFreq(int f) {
    this->f = f;
}

void Node::setCode(int c) {
    this->c = c;
}