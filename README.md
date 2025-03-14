# Binary Search Tree Implementation

This repository contains a C implementation of a Binary Search Tree (BST) with iterative and recursive interval search functions. (recursive not implemented yet)




## Project Structure

- **ArvoreBinaria.h** - Header file with data structures and function declarations
- **ArvoreBinaria.c** - Implementation of BST functions
- **TestaArvoreBinaria.c** - Test program demonstrating the BST operations

## Features

- Binary Search Tree implementation with insertion operations
- Interval search functionality (both iterative and recursive)
- Finding closest values to a target (predecessor and successor)

## How to Run

### Option 1: Using GCC in Terminal

```bash
# Clone the repository
git clone https://github.com/yourusername/binary-search-tree.git
cd binary-search-tree

# Compile the code
gcc ArvoreBinaria.c TestaArvoreBinaria.c -o BSTProgram

# Run the program
./BSTProgram

```

### Option 2: Using VS Code

Open the project folder in VS Code
Install the "Code Runner" extension 
Open TestaArvoreBinaria.c
Use the terminal to compile BOTH files:

## Function Descriptions

consultaIntervalarArvBinIter: Iterative function to search for a value in the BST. If the value is not found, it returns the closest greater and smaller values.
consultaIntervalarArvBinRec: Recursive version of the interval search function.

## Requirements
GCC compiler
C99 standard or higher
