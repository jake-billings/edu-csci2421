/**
 * Name: Jake Billings
 * Date: 02/14/2018
 * Class: CSCI 2421
 * Description: function implementations for sorting and searching vectors of Vehicle classes
 * Status: compiles and runs on csegrid
 */

#include "functions.h"

void sortByMake(vector<Vehicle> *inventoryPtr) {
    for (unsigned long i = 0; i < inventoryPtr->size(); i++) {
        for (unsigned long j = 0; j < inventoryPtr->size() - 1; j++) {
            Vehicle v = (*inventoryPtr)[j];
            if (v.getMake() > (*inventoryPtr)[j + 1].getMake()) {
                (*inventoryPtr)[j] = (*inventoryPtr)[j + 1];
                (*inventoryPtr)[j + 1] = v;
            }
        }
    }
}

void sortByModel(vector<Vehicle> *inventoryPtr) {
    for (unsigned long i = 0; i < inventoryPtr->size(); i++) {
        for (unsigned long j = 0; j < inventoryPtr->size() - 1; j++) {
            Vehicle v = (*inventoryPtr)[j];
            if (v.getModel() > (*inventoryPtr)[j + 1].getModel()) {
                (*inventoryPtr)[j] = (*inventoryPtr)[j + 1];
                (*inventoryPtr)[j + 1] = v;
            }
        }
    }
}

void sortByYear(vector<Vehicle> *inventoryPtr) {
    for (unsigned long i = 0; i < inventoryPtr->size(); i++) {
        for (unsigned long j = 0; j < inventoryPtr->size() - 1; j++) {
            Vehicle v = (*inventoryPtr)[j];
            if (v.getYear() > (*inventoryPtr)[j + 1].getYear()) {
                (*inventoryPtr)[j] = (*inventoryPtr)[j + 1];
                (*inventoryPtr)[j + 1] = v;
            }
        }
    }
}

Vehicle *_binSearchRecYear(vector<Vehicle> *inventoryPtr, unsigned int year, unsigned long left, unsigned long right) {
    const unsigned long midpoint = (right - left) / 2 + left;

    if ((*inventoryPtr)[midpoint].getYear() == year) return &(*inventoryPtr)[midpoint];

    if (left < right) {

        if ((*inventoryPtr)[midpoint].getYear() < year)
            return _binSearchRecYear(inventoryPtr, year, midpoint + 1, right);

        return _binSearchRecYear(inventoryPtr, year, left, midpoint - 1);
    }

    return nullptr;
}

Vehicle *binSearchRecYear(vector<Vehicle> *inventoryPtr, unsigned int year) {
    bool invalidOrderingExists = false;
    for (unsigned int i = 1; i < inventoryPtr->size(); i++) {
        if ((*inventoryPtr)[i - 1].getYear() > (*inventoryPtr)[i].getYear()) invalidOrderingExists = true;
    }
    if (invalidOrderingExists) {
        throw runtime_error(
                "error starting recursive binary search; incoming vector MUST be sorted in ascending order before calling search function");
    }
    return _binSearchRecYear(inventoryPtr, year, 0, inventoryPtr->size() - 1);
}

Vehicle *binSearchIterYear(vector<Vehicle> *inventoryPtr, unsigned int year) {
    bool invalidOrderingExists = false;
    for (unsigned int i = 1; i < inventoryPtr->size(); i++) {
        if ((*inventoryPtr)[i - 1].getYear() > (*inventoryPtr)[i].getYear()) invalidOrderingExists = true;
    }
    if (invalidOrderingExists) {
        throw runtime_error(
                "error starting iterative binary search; incoming vector MUST be sorted in ascending order before calling search function");
    }

    unsigned long left = 0;
    unsigned long right = inventoryPtr->size() - 1;

    Vehicle *resultPtr = nullptr;

    while (left <= right) {
        const unsigned long midpoint = (right - left) / 2 + left;

        if ((*inventoryPtr)[midpoint].getYear() == year) {
            resultPtr = &(*inventoryPtr)[midpoint];
            break;
        }

        if (left == right) {
            left++;
        } else if ((*inventoryPtr)[midpoint].getYear() < year) {
            left = midpoint + 1;
        } else {
            right = midpoint - 1;
        }
    }

    return resultPtr;
}

Vehicle *slowSearchYear(vector<Vehicle> *inventoryPtr, unsigned int year) {
    for (unsigned long i = 0; i < inventoryPtr->size(); i++) {
        if ((*inventoryPtr)[i].getYear() == year) return &(*inventoryPtr)[i];
    }

    return nullptr;
}

