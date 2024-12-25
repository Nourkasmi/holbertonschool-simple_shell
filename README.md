# Simple Shell Program

## Description

This project implements a basic Unix-like shell program in C. The shell allows users to execute commands either by typing them directly or by using built-in commands like `cd`, `env`, and `exit`. It mimics the basic functionality of a shell environment and is capable of running external programs while handling environment variables and user input. This shell program demonstrates the use of system calls and process management in C, including process creation with `fork`, executing commands with `execve`, and managing file descriptors.

## Features

- **Built-in Commands:**
  - `cd`: Changes the current directory.
  - `env`: Displays environment variables.
  - `exit`: Exits the shell program.

- **External Command Execution:**
  - The shell can execute commands located in the directories listed in the system's `PATH`.
  - The shell supports absolute and relative paths.

- **Compile the shell program with the following command**
  - gcc -Wall -Werror -Wextra -pedantic -o simple_shell *.c

- **Interactive Mode:**
  - Displays a prompt (`($)`) when running interactively.
  - Handles input through `stdin` and outputs to `stdout`.

## Requirements
  - C Compiler: gcc 
  - Libraries: stdio.h stdlib.h string.h unistd.h sys/wait.h

## Installation

To install and use the simple shell, follow these steps:

1. Clone the repository to your local machine:

   ```bash
   git clone https://github.com/Nourkasmi/holbertonschool-simple_shell.git

## Flowchart
![Flowchart](flowchart.png)
