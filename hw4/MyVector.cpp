/**
 * Name: Jake Billings
 * Date: 02/22/2018
 * Class: CSCI 2421
 * Description: my MyVector.cpp implementation file for the provided MyVector.h file
 */
//include MyVector.h because we need it
#include "MyVector.h"
//Include malloc and free
#include <stdlib.h>
//Include memcpy
#include <cstring>
//Include runtime_error
#include <stdexcept>


//Use the standard namespace
using namespace std;
//Also use the HW4 namespace
using namespace HW4;

/**
 * MyVector()
 *
 * constructor
 *
 * because we call malloc() on every push/pop, we don't need a constructor
 */
MyVector::MyVector() {}
//We're not allowed to edit the .h file, but if we were, I'd add this:
//MyVector::~MyVector() {
//    free(this->vec);
//}

/**
 * operator[]
 *
 * accessor operator
 *
 * returns the element present in this vector at index index
 *
 * throws runtime_error if an attempt is made to access an index/memory location that is out of bounds
 *
 * @param index the index to fetch an element from
 * @return the element at said index
 */
T MyVector::operator[](int index) {
    //validate index
    if (index < 0) throw runtime_error("cannot access a negative index of MyVector");
    if (index >= this->vsize) throw runtime_error("cannot access a positive index of MyVector that is greater than or equal to its size");

    //access memory location
    return this->vec[index];
}

/**
 * pop_back()
 *
 * removes the last element of the array
 *
 * uses malloc, memcpy, and free to resize our presence in memory;
 *  as a result, this function will briefly double the vector's memory use
 */
void MyVector::pop_back() {
    if (this->vsize < 1) throw runtime_error("cannot pop_back on an array with no elements");
    T *oldvec = this->vec;
    this->vec = (T*) malloc(sizeof(T)*(vsize-1));
    memcpy(this->vec, oldvec, sizeof(T)*(vsize-1));
    free(oldvec);
    this->vsize--;
}

/**
 * push_back()
 *
 * appends an element to the end of the array
 *
 * uses malloc, memcpy, and free to resize our presence in memory;
 *  as a result, this function will briefly double the vector's memory use
 *
 * @param value the value to append to the end of the array
 */
void MyVector::push_back(T value) {
    T *oldvec = this->vec;
    this->vec = (T*) malloc(sizeof(T)*(vsize+1));
    memcpy(this->vec, oldvec, sizeof(T)*vsize);
    this->vec[vsize] = value;
    free(oldvec);
    this->vsize++;
}

/**
 * size()
 *
 * @return the number of T elements stored in the array
 */
int MyVector::size() {
    return this->vsize;
}

/**
 * empty()
 *
 * @return true if there are no elements in the array; false if there is an element in the array
 */
bool MyVector::empty() {
    return !this->size();
}

/**
 * search()
 *
 * returns the first index where Value appears in this vector
 *
 * @param Value the T value to search for
 * @return the first index at which Value appears in this vector
 */
int MyVector::search(T Value) {
    for (unsigned int i = 0; i < this->vsize; i++) {
        if ((*this)[i] == Value) {
            return i;
        }
    }
    return -1;
}
