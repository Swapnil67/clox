#include<stdio.h>

#include "common.h"
#include "debug.h"
#include "vm.h"

VM vm;

static void resetStack() {
  vm.stackTop = vm.stack;
}

void initVM() {
  resetStack();
}

void freeVM() {}

void push(Value value) {
  *vm.stackTop = value;
  vm.stackTop++;
}

Value pop() {
  vm.stackTop--;
  return *vm.stackTop;
}

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
    #ifdef DEBUG_TRACE_EXECUTION
      printf("          ");
      for (Value* slot = vm.stack; slot < vm.stackTop; slot++) {
        printf("[ ");
        printValue(*slot);
        printf(" ]");
      }
      printf("\n");
      disassembleInstruction(vm.chunk, (int)(vm.ip - vm.chunk->code));
    #endif

    uint8_t instruction;
    switch(instruction = READ_BYTE()) {
      case OP_CONSTANT: {
        Value constant = READ_CONSTANT();
        push(constant);
        break;
      }
      case OP_RETURN: {
        printValue(pop());
        printf('\n');
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