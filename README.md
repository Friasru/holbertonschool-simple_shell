# Simple Shell
A lightweight Unix command interpreter written in C, developed as a collaborative project by Ian Aviles and Alberto Frias.

## Project Description
This project involves writing a simple shell that mimics the behavior of /bin/sh. A shell is a command line interpreter that reads user input, finds and executes programs, and returns results.

**The goal is to understand**:

- How shells work
- Process management in Unix
- System calls and how the operating system works
- PATH resolution
- File I/O and command execution

### Technical Knowledge

- How does a shell work
- What is a pid and ppid
- How to manipulate the enviroment of the current process
- The difference between a function and a system call
- How to create processes
- The tree prototypes of main
- How shell uses PATH to find programs

## What Your Shell Must Do
**Functionality Requirements**
*Interactive Mode*

- Display a prompt (($)) and wait for user input
- Execute commands entered by the user
- Handle multiple commands in succession
- Allow user to exit with exit command

*Non-Interactive Mode*

- Accept commands from pipes: echo "command" | ./hsh
- Accept commands from files: cat file | ./hsh
- Process multiple commands from input

*Command Execution*

- Find executable files in the system PATH
- Fork a child process to execute commands
- Use execve() to run programs
- Handle errors when commands are not found
- Match the exact error output of /bin/sh

*Output & Errors*

- Program output must be identical to /bin/sh
- Error messages must use your program name (argv[0])
- Example error format: ./hsh: 1: command: not found

### Compilation

**Shell project will be compiled using**:

- bashgcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

### Project Info
**Project Weight**: 10
**Manual QA Review**: Required

### Authors
- Ian Aviles
- Alberto Frias

See **AUTHORS** file for details

***Holberton School - C Programming & System Calls Project***
