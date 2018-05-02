*******************************************************
*  Name      : Jake Billings
*  Student ID: 105955110
*  Class     : CSCI 2421
*  Due Date  : May. 02, 2018
*******************************************************


                        Read Me


*******************************************************
*  Description of the program
*******************************************************


 Final Project
 =============

 Task: Implement a database using any data structures you want; although, using a binary search tree is required.
  It was also required to use some provided files for the binary search tree.

 I implement the database as an unordered map of unordered maps of binary search trees of unordered maps
  Layer 1: Table: the data shape/type Key: Table Name (E.g. Actors, Nominations)
  Layer 2: Index: the pre-sort column of the binary tree Key: Column Name (E.g. Name)
  Layer 3: BST: the sorted BST for a given column name Key: Cell Value Name (E.g. John Smith)
  Layer 4: object/row inspired by javascript objects Key: Column Name (E.g. Name)

 Any exact, single-element lookup should return in Avg: O(1) * O(1) * O(log(n)) * O(1) = O(log(n))
  This could theoretically be more efficient if the BST was replaced with another unordered map; however,
  we would lose sort indexing, and the project requirement of having a BST.

 I perform Unit, Integration, and E2E styles of testing in test() in test.cpp. This verifies the functionality
  of the database software and of the UI.

 Extra Credit
 ============
 Task: include an additional CSV file and interesting statistics

 I only included nominations.csv into the project. All nominations can be viewed, edited, etc. just like the other
 files.

 I did not implement statistics.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   main.cpp calls test() and starts the menu system

Name:  BSTDriver.cpp
    Dr. Augustine's BST test class
    unused in compilation; included for completeness
    slightly modified

Name:  BSTree.h
    Dr. Augustine's declaration file for BSTree class

Name:  BSTree.hpp
    Dr. Augustine's implentation file for BSTree class
    modified: I implemented the "student implementation" sections

Name:  csv.cpp
    implementation file for csv utility
    contains utility functions for reading/writing vectors of
    unordered maps to/from csv fi

Name:  csv.h
    declaration file for csv utility
    contains utility functions for reading/writing vectors of
    unordered maps to/from csv files

Name:  MenuSystem.cpp
    implemantaion file for MenuSystem class
    contains the entire user interface IO menu interface

Name:  MenuSystem.h
    declaration file for MenuSystem class
    contains the entire user interface IO menu interface

Name:  operators.cpp
    implemantaion file for read/write operators for items in BST
    this is admitedly a little bit hacky, but I didn't change
    the pre-impleneted BSTree.hpp from the assignment

Name:  operators.h
    declaration file for read/write operators for items in BST
    this is admitedly a little bit hacky, but I didn't change
    the pre-impleneted BSTree.hpp from the assignment

Name:  Table.cpp
    implemantaion file for Table class
    the Table class represents a single CSV file
    and contains indexed BSTs

Name:  Table.h
    declaration file for Table class
    the Table class represents a single CSV file
    and contains indexed BSTs

Name:  test.cpp
    implementation file for tests
    unit, integration, and E2E tests verify functionality
    of this software on startup

Name:  test.h
    declaration file for tests
    unit, integration, and E2E tests verify functionality
    of this software on startup

Name:  test_support.cpp
    implementation file for test support
    these functions form the basis of a mini testing suite

Name:  test_support.h
    declaration file for test support
    these functions form the basis of a mini testing suite

Name:  actor-actress.csv
    csv file containing actor and actress data

Name:  nominations.csv
    csv file containing extra credit nomination data

Name:  pictures.csv
    csv file containing the motion picture data

Name:  small.csv
    small dummy csv file used for testing parsing

   
*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on CLion on OSX.  It was
   compiled, run, and tested on csegrid.ucdenver.pvt.

