# C compiler learnings

## Bytecode
- Bytecode is series of instructions

### Assembler
-  An assembler is an old-school program that takes a file containing human-readable mnemonic names for CPU instructions like “ADD” and “MULT” and translates them to their binary machine code equivalent.

### Disassembler
- Given a blob of machine code, disassembler spits out a textual listing of the instructions.

### Constant pool
- The constant pool is an array of values.
- They are known at compile time.
 

## Virtual Machine (VM)
- The virtual machine is one part of our interpreter’s internal architecture.
- You hand it a chunk of code—literally a Chunk—and it runs it.

### Instruction Pointer
- Its type is a byte pointer.
- Points to the next instruction to be executed [Pointer to bytecode]
- We use an actual real C pointer pointing right into the middle of the bytecode array instead of something like an integer index because it’s faster to dereference a pointer than look up an element in an array by index.

### Decoding & Dispatching
- The first byte of any instruction is the opcode.
- Given a numeric opcode, we need to get to the right C code that implements that instruction’s semantics.
- This process is called decoding or dispatching the instruction.

### Execution Tracing
- This helps with diagnostic logging in VM

### Value Stack Manipulator
- When an instruction “produces” a value, it pushes it onto the stack.
- When it needs to consume one or more values, it gets them by popping them off the stack.