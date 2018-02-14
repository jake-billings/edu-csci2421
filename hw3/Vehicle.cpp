/**
 * Name: Jake Billings
 * Date: 02/14/2018
 * Class: CSCI 2421
 * Description: class function implementations Vehicle class
 * Status: compiles and runs on csegrid
 */

#include "Vehicle.h"


/**
 * Implement the empty vehicle constructor
 */
Vehicle::Vehicle() {};

/**
 * Implement the full vehicle constructor
 */
Vehicle::Vehicle(unsigned int iYear, string iMake, string iModel)  {
    this->setMake(iMake);
    this->setModel(iModel);
    this->setYear(iYear);
}

void Vehicle::setMake(string input) {
    this->make = input;
}

void Vehicle::setModel(string input) {
    this->model = input;
}

void Vehicle::setYear(unsigned int input) {
    this->year = input;
}

//Implement vehicle getters
string Vehicle::getMake() {
    return this->make;
}

string Vehicle::getModel() {
    return this->model;
}

unsigned int Vehicle::getYear() {
    return this->year;
}

/**
 * Implement the << operator as a method to serialize this object
 *
 * @param out The output stream to serialize to
 * @param car1 The vehicle to serialize to out
 * @return out
 */
ostream &operator<<(ostream &out, Vehicle &car1) {
    out << "Year:\t\t" << car1.getYear() << endl;
    out << "Make:\t\t" << car1.getMake() << endl;
    out << "Model:\t\t" << car1.getModel() << endl;
    return out;
}

/**
 * Implement the >> operator as a method to deserialize this object
 *
 * @param out The input stream to read from
 * @param car1 The vehicle to dump the incoming data to
 * @return out (input)
 */
istream &operator>>(istream &in, Vehicle &car1) {
    in >> car1.year;
    in.ignore();

    string make;
    string model;
    getline(in, make);
    getline(in, model);
    car1.setMake(make);
    car1.setModel(model);

    return in;
}