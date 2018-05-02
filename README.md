# edu-csci2421
This repository contains the work I completed for the course CSCI2421 Data Structures and Program Design at the University of Colorado Denver.

## Building this Project
This project has no non-standard library dependencies. I wrote a majority of this code using CMake in CLion. However, homework requirements dictate that each assignment must have a working makefile from a standard template distributed at the beginning of the class. Thus, each folder contains a make file. If you have `g++` installed, all you have to do is clone the repository and run make in a directory to build the project. The executable will be place in that directory. I do not include `CMakeLists.txt`.


## Unit, E2E, and Integration Testing
I wrote automated testing for each assignment. Using a few functions as a very basic testing suite, I test the critical functionality of each assignment. I also compare the pros/cons of unit/integration/e2e testing. See the function `test()` in each main file for the testing written for that assignment.


## Documentation
I put a lot of effort into documenting the code in this repository. All functions, variables, blocks, includes, and classes have documentation-style comments detailing the name, type, purpose, and details of the following code.
```C++
/**
 * Table
 *
 * class
 *
 * data structure
 *
 * trade off: high memory usage for quick access times
 *
 * a "Table" is essentially an unorderd map of binary search trees of unordered maps
 *
 * the innermost unordered maps are inspired by javascript objects and can be thought of as rows
 * each binary search tree is sorted by a different key (a.k.a column name) from each row
 * the outermost unordered map connects BSTs with the keys for which they are sorted
 *
 * to access data:
 *  1. pick a key to search by -> this picks a BST from the outermost unorderedMap
 *  2. pick a value to search for -> this retreives an item out of the BST
 *
 * the constructor builds all of the trees and maps; it performs multiple sorts and may
 *  impede performance; however, subsequent reads are much faster
 *
 * I make use of many inefficient string copies to get this prototype to work; however, I didn't
 *  feel like messing with the pointers at this point in this project.
 */
class Table { ... }
```

## Work
- HW1: Introductory Guessing Game Assignment
- HW2: Set Implementation
- HW3: Searching, Sorting, Binary Search
- HW4: Vector Implementaion (Dynamic Array using malloc() and free())
- HW5: Linked List Implementation (using malloc() and free())
- HW6: Doubly Linked List with searching and sorting
- HW7: Queues, Blocking, and Event-based Simulation
- HW8: Final Project Preparation - Design Brainstorming and Documentation
- HW9: Hash Table as a simple spell checker
- FINAL PROJECT: Complete Database Implementation using binary search trees and hash tables 


### Other Projects ###
Checkout my other projects at [https://jakebillings.com](https://jakebillings.com) or contact me via [LinkedIn](https://www.linkedin.com/in/jake-billings/).