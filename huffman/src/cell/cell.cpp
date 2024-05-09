#include "../../include/cell.h"

Cell::Cell(int asciiCode, uint8_t huffCode, Cell *next) {
    this->asciiCode = asciiCode;
    this->huffCode = huffCode;
    this->next = next;
}