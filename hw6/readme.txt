*******************************************************
*  Name      : Jake Billings
*  Student ID: 105955110
*  Class     : CSCI 2421
*  Due Date  : Mar. 08, 2018
*******************************************************


                        Read Me


*******************************************************
*  Description of the program
*******************************************************

 Task:
      1. Create a dictionary class
        1a. Dictionary class should have a list of type DictEntry
        1b. Dictionary class should be able to read all words from a file
      2. Implement a main() function
        2a. Read A Dictionary object from dictionary.txt
        2b. Sort the list in the dictionary class
        2c. For each word in findwords.txt,
            2c1. search the dictionary for the word
            2c2. print the word to the screen along with the number of iterations searches in the dictionary took
            2c3. search the dictionary for the word in reverse order
            2c2. print the word to the screen along with the number of iterations searches in the dictionary took (reverse)
        2d. Print the dictionary words to revsorted.txt in reverse order
      3. Extra credit opportunity: Replace the STL List with your own implementation of a doubly linked list

 Outline
 =======
  - describe(), assertInt(), asserString() - Simple Test Suite Functions
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

Name:  SearchResult.h
   contains class definition for the SearchResult class
   the SearchResult class contains fields for index
   and iteration count; it is used to return both
   pieces of information at once after calling a search

Name:  SearchResult.cpp
   contains class implementation for the SearchResult class
   the SearchResult class contains fields for index
   and iteration count; it is used to return both
   pieces of information at once after calling a search

Name:  DictEntry.h
   contains class definition/implementation for the DictEntry class
   this was provided by the assignment, and I have not edited it

Name:  Dictionary.h
   contains class definition for the Dictionary class
   the Dictionary class wraps a DoublyLinked list of DictEntries
   and exposes the functions necessary to complete unit
   testing and demoing in main.cpp

Name:  Dictionary.cpp
   contains class implementation for the Dictionary class
   the Dictionary class wraps a DoublyLinked list of DictEntries
   and exposes the functions necessary to complete unit
   testing and demoing in main.cpp

   
*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on CLion on OSX.  It was
   compiled, run, and tested on csegrid.ucdenver.pvt.

