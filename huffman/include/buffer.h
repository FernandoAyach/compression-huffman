#pragma once
#include <cstdio>
#include <cstdint>

class Buffer {
public:
  Buffer(FILE *file);

  void add(uint8_t bit);
  void flush();

  uint8_t getBit();
  uint8_t ocuppiedBits();
  uint8_t availableBits();

private:
  FILE *file;   
  uint8_t bits[8]; 
  uint8_t n; 
  
};