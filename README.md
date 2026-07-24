# train-compartment-management-system

A C implementation of a linked list-based train compartment management system. This project demonstrates fundamental data structure operations using a singly linked list to represent train compartments.

## Overview

This program simulates a train composed of individual compartments. Each compartment can be added or removed from the train, and you can query the total number of compartments at any time. The project uses a **singly linked list** data structure to efficiently manage compartments.

## Features

- ✅ **Add compartments** at the beginning or end of the train
- ✅ **Remove compartments** from the beginning or end of the train
- ✅ **Count compartments** in the train
- ✅ **Display all compartments** in the train
- ✅ **Dynamic memory management** using malloc and free

## Data Structure

### Compartment
```c
typedef struct Compartment {
    int number;                  // Unique compartment number
    struct Compartment* next;    // Pointer to next compartment
} Compartment;
```

### Train
```c
typedef struct {
    Compartment* head;           // Pointer to first compartment
} Train;
```

## Functions

| Function | Description |
|----------|-------------|
| `create_compartment(int number)` | Creates a new compartment with the given number |
| `initialize_train(Train* train)` | Initializes an empty train |
| `add_compartment_at_beginning(Train* train, int number)` | Adds a compartment at the front of the train |
| `add_compartment_at_end(Train* train, int number)` | Adds a compartment at the end of the train |
| `remove_compartment_from_beginning(Train* train)` | Removes the first compartment |
| `remove_compartment_from_end(Train* train)` | Removes the last compartment |
| `count_compartments(Train* train)` | Returns the total number of compartments |
| `display_compartments(Train* train)` | Prints all compartments in order |

## Compilation & Execution

### Compile
```bash
gcc -o train_compartment Train_Compartment.c
```

### Run
```bash
./train_compartment
```

## Sample Output

```
Compartments: 0 -> 1 -> 2 -> 3 -> NULL
Count: 4
Compartments after removing from end: 0 -> 1 -> 2 -> NULL
Compartments after removing from beginning: 1 -> 2 -> NULL
Final Count: 2
```

## Time Complexity

| Operation | Complexity |
|-----------|-----------|
| Add at beginning | O(1) |
| Add at end | O(n) |
| Remove from beginning | O(1) |
| Remove from end | O(n) |
| Count compartments | O(n) |
| Display all | O(n) |

## Memory Management

- Memory is dynamically allocated for each new compartment using `malloc()`
- Compartments are properly freed when removed using `free()`
- No memory leaks when the train is properly maintained

## Learning Objectives

This project demonstrates:
- Understanding of **singly linked lists**
- Pointer manipulation and dynamic memory allocation
- Basic linked list operations (insertion, deletion, traversal)
- Memory management in C
- Struct usage and typedef declarations

## License

This project is open source and available for educational purposes.

## Author

Created by **pav1116**

---

**Note:** This is a educational project designed to teach fundamental data structures in C. For production use, consider adding error handling, validation, and additional features as needed.
