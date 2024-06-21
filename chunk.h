// * Module to define our code representation
// * "chunk" refers to sequences of bytecode

#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"

// * Opcode
typedef enum
{
  OP_RETURN,
} OpCode;

// * Dynamic Array
typedef struct
{
  int count;
  int capacity;
  uint8_t *code;
} Chunk;

// * Initialize chunk [dynamic array]
void initChunk(Chunk* chunk);

// * Free the chunk memeory
void freeChunk(Chunk* chunk);

// * Append at the end of chunk [dynamic array]
void writeChunk(Chunk* chunk, u_int8_t byte);

#endif

//  * capacity = The number of elements in the array we have allocated
//  * count = how many of those allocated entries are actually in use