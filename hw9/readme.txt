*******************************************************
*  Name      : Jake Billings
*  Student ID: 105955110
*  Class     : CSCI 2421
*  Due Date  : Mar. 26, 2018
*******************************************************


                        Read Me


*******************************************************
*  Description of the program
*******************************************************

Task:
  This programming homework is to develop a simple spelling checker. The file dict.txtPreview the document contains
  25,021 frequently used words, each on a separate line in lowercase. Read the file, and insert the words into a hash
  table with 1373 buckets. Remember to move dict.txt to the csegrid. Then run the command dos2unix dict.dat (to remove
  those pesky /r's created by Windows)

 Outline
 =======
  - describe(), failCount +=  assertInt() - Simple Test Suite Functions
  - test() Unit Testing
  - main(), which includes a call to test() and demo



*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   main.cpp contains a simple set of function for unit testing, unit
   tests, and a demo.

   test() contains unit tests

   main() calls test() then runs a demo of the program

Name:  Dictionary.cpp
   Implementation file for Dictionary class
   Dictionary class stores string using a hash
   table and can access them quickly

Name:  Dictionary.h
   Declaration file for Dictionary class
   Dictionary class stores string using a hash
   table and can access them quickly

Name:  CustomerEventType.h
   Declaration file for CustomerEventType enum
   CustomerEventType is an enum that represents a state of
    either: DEPARTURE or ARRIVAL

Name:  LinkedList.hpp
   Decalration/Implementation file for a LinkedList
   FROM Object Oriented assignment six
   This is used by the Dictionary class

Name:  Node.hpp
   Decalration/Implementation file for a Node
   FROM Object Oriented assignment six
   This is used by the LinkedList class

Name:  Simulation.h
   Declartion file for Simulation funciton
   simulate() accepts a priority_queue of ARRIVAL
   events, simulates the bank line, and returns
   a SimulationResult object containing output
   and statistics

Name:  StrUtil.cpp
   Implementation file for string utilities functions
   scrub() and toLower() help process strings as
   they are entered and checked in the dictionary

Name:  StrUtil.h
   Declartion file for string utilities functions
   scrub() and toLower() help process strings as
   they are entered and checked in the dictionary

Name:  check.txt
    text file provided by the assignment
    these are the words to check for misspellings
    using the dictionary

Name:  dict.txt
    text file provided by the assignment
    these are all the words the assignment
    considers to be spelled correctly

Name:  short.txt
    obselete test file
    contains the first few entries of dict.txt

Name:  makefile
    c++ makefile to build the project


*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.

   The program was developed and tested on CLion on OSX.  It was
   compiled, run, and tested on csegrid.ucdenver.pvt.

