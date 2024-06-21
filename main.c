#include <stdio.h>
#include "common.h"
#include "chunk.h"

int main(int argc, const char* argv[]) {
  Chunk chunk;
  initChunk(&chunk);
  writeChunk(&chunk, OP_RETURN);
  freeChunk(&chunk);
  return 0;
}

// * Run the code
// * gcc main.c chunk.c memory.c -o main