# Data Structure Visualizer

A command-line tool written in C++ that shows how common data structures and sorting algorithms work, step by step, directly in the terminal.

## Features

| Module | What you can do |
|---|---|
| **Stack (LIFO)** | Push, pop, peek and see the stack drawn vertically with the TOP marked. Shows overflow and underflow errors. |
| **Queue (FIFO)** | Enqueue, dequeue, peek and see the queue drawn from FRONT to REAR. |
| **Linked List** | Insert at head or tail, delete a value, search, reverse the list, and see the pointer chain (`HEAD -> [10] -> [20] -> NULL`). |
| **Sorting** | Bubble, selection and insertion sort animated step by step. Compared elements are shown in `[ ]`, with a comparison and swap count at the end. You can enter your own array. |

## Project structure

```
data-structure-visualizer/
├── main.cpp          # main menu and program start
├── utils.h           # safe integer input helper
├── stack.h           # Stack class and menu
├── queue.h           # Queue class and menu
├── linked_list.h     # LinkedList class and menu
├── sorting.h         # sorting algorithms and menu
├── README.md
└── .gitignore
```

Each data structure lives in its own header file, so a new one (for example a binary tree) can be added by creating one new `.h` file and one menu entry in `main.cpp`.

## Build and run

You need a C++ compiler such as `g++` (MinGW / WinLibs on Windows).

```bash
g++ -std=c++17 main.cpp -o visualizer
```

Run it:

```bash
# Windows
visualizer

# Linux / macOS
./visualizer
```

## Example output

Stack after pushing 10, 20 and 30:

```
   |      |
   |      |
   |      |
   |   30 |  <- TOP
   |   20 |
   |   10 |
   +------+
```

Linked list:

```
   HEAD -> [5] -> [10] -> [30] -> NULL
   Size: 3
```

Bubble sort step:

```
    64 [ 25][ 12] 22  11
   Compare 25 and 12 -> wrong order, swap
```

## Concepts covered

- Classes and encapsulation, header files and include guards
- Dynamic memory with `new` and `delete`, and a destructor that frees every node
- Pointer manipulation in a singly linked list
- Basic sorting algorithms and how many comparisons and swaps each one makes
- Input validation, so typing letters instead of numbers does not crash the program

## Author

Monika Gurbani
