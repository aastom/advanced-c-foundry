# Module 02: Performance, Profiling, and the Compiler

This module is about demystifying performance. You'll learn how to measure your code's execution, find bottlenecks, and build an intuition for how the compiler optimizes your C code.

## Pre-flight Check

Review the `Timer` utility in the `common/` directory. You should be comfortable using it to measure the duration of a code block.

## Concepts

1.  **Profiling with `gprof`**: Profiling is the act of measuring a program to see where it spends its time. `gprof` is a classic tool for this. To use it, you compile with the `-pg` flag. When the program runs, it generates a `gmon.out` file, which `gprof` can then analyze to produce a human-readable report.

2.  **Compiler Optimization & Assembly**: The "aha!" moment. You don't need to be an assembly expert to gain huge insights from it. By comparing the assembly output of a function with optimizations off (`-O0`) and on (`-O2` or `-O3`), you can see what the compiler does to make code faster (e.g., inlining functions, unrolling loops, using more efficient instructions). This helps you write C that is "compiler-friendly."

## Example & Exercise

*   `example_profiling.c`: A simple program with an obvious performance bottleneck. The exercise is to compile it with profiling flags, run it, generate a `gprof` report, and identify the function that is taking the most time.
