#include "../../include/buffer.h"
  
Buffer::Buffer(FILE *file) : file(file), n(0) { }

Buffer::~Buffer() {}

void Buffer::add(uint8_t bit) {
  bits[n++] = bit != 0;

  if (n == 8)
    flush();
}

void Buffer::flush() {
  if(n == 0) return;

  uint8_t byte = 0;

  if(n < 8) {
    for(int i = n; i < 8; i++) {
      bits[i] = 0;
    }
  }

  for(int i = 0; i < 8; i++) {
    byte = byte << 1;
    byte += bits[i];
  }
  
  fwrite(&byte, sizeof(uint8_t), 1, file);
  n = 0;
}

uint8_t Buffer::getBit() {
  if(n == 0) {
    uint8_t byte;
    int size = fread(&byte, sizeof(uint8_t), 1, file);

    if(size == 0) return 2;

    for(int i = 0; i < 8; i++) {
      bits[i] = (byte >> (7 - i)) & 1;
    }
    
    n = 8;
  }

  uint8_t bit = bits[availableBits()];
  n--;

  return bit;
}

uint8_t Buffer::ocuppiedBits() {
  return n;
}

uint8_t Buffer::availableBits() {
  return 8 - n;
}