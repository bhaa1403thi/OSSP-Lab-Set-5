# OSSP Lab – Set 5

## Overview
This repository contains the programs implemented for Operating Systems and System Programming (OSSP) Lab – Set 5.

## Programs

### 1. Inter-Process Communication Using Anonymous Pipe
- Creates a pipe using `pipe()`.
- Creates a child process using `fork()`.
- Transfers a message from the parent to the child using `write()` and `read()`.
- Uses `wait()` for process synchronization.

### 2. Process Termination Using SIGTERM
- Creates a child process using `fork()`.
- Sends `SIGTERM` to the child using `kill()`.
- Uses `waitpid()` to collect the child's termination status.

## Requirements
- Ubuntu or another Linux distribution
- GCC compiler

## Compilation and Execution

### Program 1
```bash
gcc set5q1.c -o set5q1
./set5q1
```

### Program 2
```bash
gcc set5q2.c -o set5q2
./set5q2
```

## Concepts Covered
- Process creation
- Parent and child processes
- Anonymous pipes
- Inter-process communication (IPC)
- Linux signals
- SIGTERM
- Process synchronization using wait()

## Platform
Ubuntu Linux

