//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2016 __Pearson Education__. All rights reserved.
//Modified by TAA to remove Template and Inheritance

/** @file ArrayBag.cpp */

#include "ArrayBag.h"


ArrayBag::ArrayBag() : itemCount(0), maxItems(DEFAULT_BAG_SIZE) {
}  // end default constructor


int ArrayBag::getCurrentSize() const {
    return itemCount;
}  // end getCurrentSize


bool ArrayBag::isEmpty() const {
    return itemCount == 0;
}  // end isEmpty


bool ArrayBag::add(const ItemType &newEntry) {
    bool hasRoomToAdd = (itemCount < maxItems);
    if (hasRoomToAdd) {
        items[itemCount] = newEntry;
        itemCount++;
    }  // end if

    return hasRoomToAdd;
}  // end add


bool ArrayBag::remove(const ItemType &anEntry) {
    int locatedIndex = getIndexOf(anEntry);
    bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
    if (canRemoveItem) {
        itemCount--;
        items[locatedIndex] = items[itemCount];
    }  // end if

    return canRemoveItem;
}  // end remove


void ArrayBag::clear() {
    itemCount = 0;
}  // end clear


int ArrayBag::getFrequencyOf(const ItemType &anEntry) const {
    int frequency = 0;
    int searchIndex = 0;
    while (searchIndex < itemCount) {
        if (items[searchIndex] == anEntry) {
            frequency++;
        }  // end if

        searchIndex++;
    }  // end while

    return frequency;
}  // end getFrequencyOf


bool ArrayBag::contains(const ItemType &anEntry) const {
    return getIndexOf(anEntry) > -1;
}  // end contains

// private

int ArrayBag::getIndexOf(const ItemType &target) const {
    bool found = false;
    int result = -1;
    int searchIndex = 0;
    // if the ArrayBag is empty, itemCount is zero, so loop is skipped
    while (!found && (searchIndex < itemCount)) {
        if (items[searchIndex] == target) {
            found = true;
            result = searchIndex;
        } else {
            searchIndex++;
        }  // end if
    }  // end while

    return result;
}  // end getIndexOf
