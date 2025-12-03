# Mini Compiler Lab

This lab implements a simple compiler front-end and code generator for a tiny imperative language with:

- Variable declarations: `int x;`
- Assignment: `x = expr;`
- Printing: `print(x);`
- Scanning (input): `scan(x);`
- Arithmetic: `+ - * /`
- Relational: `< > ==`
- Control flow: `if (cond) { ... } else { ... }`, `while (cond) { ... }`

## Components
- `lexer.l` Flex specification producing tokens
- `parser.y` Bison grammar building intermediate code (quad-like) via `gen_code`
- `symtab.c/h` Symbol table with simple linear list and stack frame address assignment
- `codeGen.c/h` Intermediate instruction list + x86 MASM assembly emission

## New Additions
- Added opcodes and grammar actions for SUB, MUL, DIV, EQ (equality) operations.
- Fixed format strings in generated assembly (removed stray percent escapes).
- Unified stack depth tracking for all binary operations and relational/equality ops.

## Build
Requires flex and bison plus GCC (tested on macOS for front-end). MASM assembly output is Windows-specific; on macOS you can still view the emitted MASM code but not assemble it directly.

```bash
make            # builds parser + lexer, runs on input.txt producing output.txt
make input=input2.txt   # run with the second sample (invoke manually: a <input2.txt >output2.txt)
```

The executable produced (`a` by default) reads from stdin and writes intermediate + assembly to stdout.

## Try Another Input
Create a new file `prog.txt` and run:
```bash
./a < prog.txt > prog.out
```

## Example Expression Semantics
Stack-based evaluation: each `LD_INT` / `LD_VAR` pushes a value; binary ops pop two and push result. Relational/equality ops produce 0/1.

## Future Work
- Type system extension (REAL, CHAR processing in grammar)
- Error recovery in parser instead of immediate exit
- Portable assembly backend (e.g., NASM/Linux or LLVM IR)
- Temporary register reuse optimization

## Notes
Equality generates labels similar to `<` and `>`; labels are numbered by code position for uniqueness.
