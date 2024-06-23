## Bytecode
- In a bytecode-compiled system, source code is translated to an intermediate representation known as bytecode.
- It is a form of Instruction set designed for efficient execution by a software interpreter.
- A bytecode program may be executed by parsing and directly executing the instructions, one at a time. 
- Some systems, called dynamic translators, or just-in-time (JIT) compilers, translate bytecode into machine code as necessary at runtime. Eg Java & Smalltalk [JIT -> Bytecode -> Machine Code]
- This introduces a delay before a program is run, when the bytecode is compiled to native machine code, but improves execution speed considerably compared to interpreting source code directly, normally by around an order of magnitude (10x).

## Evaluation Order 
- C and Scheme leave evaluation order unspecified. Java specifies left-to-right evaluation like we do for Lox.

## Stack VM
-  Executing instructions in a stack-based VM is dead simple. 
- Compiling a source language to a stack-based instruction set is a piece of cake.

## Just In time Compilation (JIT) or (Dynamic compilation or run time compilations)
- JIT compilation during execution of a program (at run time) rather than before execution.
- This may consist of source code translation but is more commonly bytecode translation to machine code, which is then executed directly. 

## Random
- JVM, the CLR, and JavaScript all use sophisticated just-in-time compilation pipelines to generate much faster native code on the fly.
- It's faster to dereference the pointer than look up an element in an array by index.