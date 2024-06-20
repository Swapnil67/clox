#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"

#define GROW_CAPACITY(capacity) \
  ((capacity) < 8 ? 8 : (capacity) * 2)

// * This macro calculates a new capacity based on a given current capacity.
#define GROW_ARRAY(type, pointer, oldCount, newCount) \
  (type*)reallocate(pointer, sizeof(type) * (oldCount), \
  sizeof(type) * (newCount))

#define FREE_ARRAY(type, ponter, oldCount) \
  reallocate(pointer, sizeof(type) * (oldCount), 0)

// * Macro function
void* reallocate(void* pointer, size_t oldSize, size_t newSize);

#endif