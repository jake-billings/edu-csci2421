/*
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 */
#include "test_support.h"

//---------Poor Man's Testing Suite----------
/**
 * describe()
 *
 * Used to make the style look similar to mocha javascript tests;
 *  All this function really does is print a string followed by "..."
 *
 * @param expectString A string describing what a test is expecting
 */
void describe(const std::string expectString) {
    std::cout << expectString << "...";
}

/**
 * failCount +=  assertInt()
 *
 * Prints "Passed" or "Failed" with appropriate messages bassed on if expected==got.
 *
 * @param expected The value we expect got to equal
 * @param got The actual function value
 * @return int 1 if the test failed; 0 if it didn't
 */
int assertInt(int expected, int got) {
    if (expected == got) {
        std::cout << "Passed.";
    } else {
        std::cout << "Failed. Expected " << expected << "; Got " << got << ".";
    }
    std::cout << std::endl;

    return expected != got;
}

/**
 * failCount +=  assertLong()
 *
 * Prints "Passed" or "Failed" with appropriate messages bassed on if expected==got.
 *
 * @param expected The value we expect got to equal
 * @param got The actual function value
 * @return int 1 if the test failed; 0 if it didn't
 */
long assertLong(long expected, long got) {
    if (expected == got) {
        std::cout << "Passed.";
    } else {
        std::cout << "Failed. Expected " << expected << "; Got " << got << ".";
    }
    std::cout << std::endl;

    return expected != got;
}

/**
 * failCount +=  assertFloat()
 *
 * Prints "Passed" or "Failed" with appropriate messages bassed on if expected==got.
 *
 * @param expected The value we expect got to equal
 * @param got The actual function value
 * @return int 1 if the test failed; 0 if it didn't
 */
int assertFloat(float expected, float got) {
    if (expected == got) {
        std::cout << "Passed.";
    } else {
        std::cout << "Failed. Expected " << expected << "; Got " << got << ".";
    }
    std::cout << std::endl;

    return expected != got;
}

/**
 * assertString()
 *
 * Prints "Passed" or "Failed" with appropriate messages bassed on if expected==got.
 *
 * @param expected The value we expect got to equal
 * @param got The actual function value
 * @return int 1 if the test failed; 0 if it didn't
 */
int assertString(std::string expected, std::string got) {
    if (expected == got) {
        std::cout << "Passed.";
    } else {
        std::cout << "Failed. Expected \"" << expected << "\"; Got \"" << got << "\".";
    }
    std::cout << std::endl;

    return expected != got;
}