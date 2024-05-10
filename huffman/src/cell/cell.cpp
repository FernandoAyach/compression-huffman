#include "../../include/cell.h"

Cell::Cell(int asciiCode, string huffCode, Cell *next) {
    this->asciiCode = asciiCode;
    this->huffCode = huffCode;
    this->next = next;
}

string Cell::getHuffCode() {
    return this->huffCode;
}