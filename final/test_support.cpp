/**
 * Name: Jake Billings
 * Date: 05/02/2018
 * Class: CSCI 2421
 * Description: implementation file for unit test support/unit testing suite
 * Status: compiles and runs on csegrid
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
int assertLong(long expected, long got) {
    if (expected == got) {
        std::cout << "Passed.";
    } else {
        std::cout << "Failed. Expected " << expected << "; Got " << got << ".";
    }
    std::cout << std::endl;

    return expected != got;
}

/**
 * failCount +=  assertNotNullLong()
 *
 * Prints "Passed" or "Failed" with appropriate messages bassed on if a value is not null
 *
 * @param expected The value we expect got to equal
 * @param got The actual function value
 * @return int 1 if the test failed; 0 if it didn't
 */
int assertNotNull(long got) {
    if (got == (long) nullptr) {
        std::cout << "Failed. Expected pointer not to be nullptr; Got " << got << ".";
        std::cout << std::endl;
        return 1;
    } else {
        std::cout << "Passed.";
        std::cout << std::endl;
        return 0;
    }
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