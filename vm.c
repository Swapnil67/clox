#include<stdio.h>

#include "common.h"
#include "vm.h"

VM vm;

void initVM() {}

void freeVM() {}

// * It is the beating heart of the VM.
static InterpretResult run() {
  // * Macro reads the byte currently pointed at by ip and then advances ip.
  #define READ_BYTE() (*vm.ip++)
  /**
   * * reads the next byte from the bytecode, treats the resulting number as an
   * * index, and looks up the corresponding Value in the chunk’s constant table. 
   */
  #define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])

  // * Infinite loop
  for(;;) {
    uint8_t instruction;
    switch(instruction = READ_BYTE()) {
      case OP_CONSTANT: {
        Value constant = READ_CONSTANT();
        printValue(constant);
        printf("\n");
        break;
      }
      case OP_RETURN: {
        return INTERPRET_OK;
      }
    }
  }

  // * Undefining macros
  #undef READ_BYTE
  #undef READ_CONSTANT
}

InterpretResult interpret(Chunk* chunk) {
  vm.chunk = chunk;
  vm.ip = vm.chunk->code;
  return run();
}