#include <stdio.h>
#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char* argv[]) {
  initVM();

  Chunk chunk;
  initChunk(&chunk);

  // * add constant
  int constant = addConstant(&chunk, 1.2);
  writeChunk(&chunk, OP_CONSTANT, 10);
  writeChunk(&chunk, constant, 10);

  writeChunk(&chunk, OP_RETURN, 10);
  disassembleChunk(&chunk, "test chunk");
  interpret(&chunk);
  freeVM();
  freeChunk(&chunk);

  return 0;
}

// * Run the code
// * gcc main.c memory.c value.c chunk.c debug.c -o main && ./main