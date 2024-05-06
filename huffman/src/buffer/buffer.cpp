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
  
Buffer::Buffer(FILE *file) : file(file), n(0) { }

void Buffer::add(uint8_t bit) {
  bits[n++] = bit != 0;

  if (n == 8)
    flush();
}

void Buffer::flush() {
  if(n == 0) return;

  uint8_t byte = 0;

  if(n < 8) {
    for(int i = availableBits(); i < 8; i++) {
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

int main() {
  FILE *original, *copia;
  original = fopen("original.txt", "rb");
  copia = fopen("copia.txt", "wb");

  Buffer in(original), out(copia);
  uint8_t bit;
  
  while ((bit = in.getBit()) != 2) {
    putchar('0' + bit);
    out.add(bit);
  }
  putchar('\n');
  out.flush();

  fclose(original);
  fclose(copia);
  
  return 0;
}