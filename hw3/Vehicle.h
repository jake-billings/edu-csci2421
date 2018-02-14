/**
 * Name: Jake Billings
 * Date: 02/14/2018
 * Class: CSCI 2421
 * Description: class function definitions Vehicle class
 * Status: compiles and runs on csegrid
 */
#ifndef EDU_C_DEMO_VEHICLE_H
#define EDU_C_DEMO_VEHICLE_H

//Include strings and io for the purpose of implementing methods later
#include <string>
#include <iostream>

//Use the standard namespace
using namespace std;

/**
 * Define the Vehicle class to hold all of the data needed to represent a vehicle
 */
class Vehicle {
private:
    /**
     * make - the string make of vehicle
     */
    string make;

    /**
     * model - the string model of vehicle
     */
    string model;

    /**
     * year - the unsigned int year of vehicle
     */
    unsigned int year;
public:
    /**
     * Define an empty constructor
     */
    Vehicle();

    /**
     * Define a complete constructor
     *
     * @param iMake The make of the vehicle
     * @param iYear The year of the vehicle
     * @param iPrice The price of the vehicle
     */
    Vehicle(unsigned int iYear, string iMake, string iModel);

    //Define setters
    void setMake(string input);
    void setModel(string input);
    void setYear(unsigned int input);

    //Define getters
    string getMake();
    string getModel();
    unsigned int getYear();

    /**
     * Define the << operator as a method to serialize this object
     *
     * Contains cout/cin specific content for the purpose of user input.
     *
     * @param out The output stream to serialize to
     * @param car1 The vehicle to serialize to out
     * @return out
     */
    friend ostream& operator<<(ostream &out, Vehicle &car1);

    /**
     * Define the >> operator as a method to deserialize this object
     *
     * Contains cout/cin specific content for the purpose of user input.
     *
     * @param out The input stream to read from
     * @param car1 The vehicle to dump the incoming data to
     * @return out (input)
     */
    friend istream& operator>>(istream &out, Vehicle &car1);
};


#endif //EDU_C_DEMO_VEHICLE_H