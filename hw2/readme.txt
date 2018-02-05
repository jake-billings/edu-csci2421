*******************************************************
*  Name      : Jake Billings
*  Student ID: 105955110
*  Class     : CSCI 2421
*  Due Date  : Feb. 5, 2018
*******************************************************


                        Read Me


*******************************************************
*  Description of the program
*******************************************************


 Task: implement operators for a set using the provided
 ArrayBag class.

 Set is implemented as a subclass of ArrayBag. The
 subclass implements all operators as describe in the
 homework (+, -, <<, >>), and overrides the add()
 function of ArrayBag so as to prevent the addition of
 duplicate integers into a set.

 My implementation runs ineffciently for sets that
 contain large integers because my subclass does not
 have access to the private items array of ArrayBag. As
 a result, it uses hueristics to optimize a guess and
 check algorithm when testing what integers are in a set.
 Specifically, it assumes all numbers are relatively
 "close" to 0. It checks from 0 outwards towards the min
 and max int values. See implementation functions in
 Set.cpp. This solution is adequate for the provided test
 data.

 I implement a simple set of unit tests to validate the
 functionality of my solution in main.cpp.

 I implement validation in the ">>" set operator by
 separately parsing each string word of each line that
 the operator reads. If there is an error parsing the
 string, then the operator function throws a
 runtime_exception. A unit test and invalid text file
 verifies this functionality.

 Outline of main.cpp
 ===================
  - describe(), assertInt() - Simple Test Suite Functions
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


Name:  SetFunctions.h
   Contains the definition for the class Set.

Name: SetFunctions.cpp
   Contains implementations of the operators for the Set class
   and the overridden add() function

Name: ArrayBag.h
    The provided ArrayBag implementation we have to work with

Name: ArrayBag.cpp
    The provided ArrayBag implementation we have to work with

Name: setInput.txt
    The provided set data we have to work with

Name: setInputInvalid.txt
    Invalid set data used to verify validation functionality in a unit test

Name: validateInput.cpp
    Unused; The provided example of validation
   
   
*******************************************************
*  Status of program
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on CLion on OSX.  It was
   compiled, run, and tested on csegrid.ucdenver.pvt.

