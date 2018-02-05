/*Dr. Augustine
 Last Updated: 09/02/2016
 This program demonstrates how to validate if input is all integer values
*/

#include <iostream>     //cout, cin
#include <sstream>      //stringstream
#include <string>
#include <fstream>      //ifstream
#include <vector>

using namespace std;

/*Pre: Input a file stream and a vector of integers that were read in from the file
  Post: True if all input in vector are ints
  Desc: validates that all items in vector are ints
*/

bool getIntsFromFile(ifstream &infile, vector<int> &vec )
//istream accepts from cin or file as a parent class
{
	stringstream ss;
	int tempInt;
	string readString;

	getline(infile, readString);
	ss << readString; //Write readString into ss
	while (!ss.eof()) //Until end of stream
	{
		ss >> tempInt; //Read in an int from ss into tempInt
		if (ss.fail()) //If it fails to to read an int data type
		{
			cout << "Input contains non-integer data\n";
			ss.clear(); //Clears state of string stream;
			return false;
		}
		vec.push_back(tempInt); //Add to the vector
	}
	return true;
}

/*Desc: Prints out all values in a vector
  Pre: Reads in a vector
  Post: void
*/
void printValues(vector<int> set)
{
	for (int i = 0; i < set.size(); i++)
	{
		cout << set[i] << " ";
	}
    cout << endl;
}


int main()
{

	ifstream infile("setInput.txt");
	vector<int> vec1, vec2;

	if ( getIntsFromFile(infile, vec1) )
		printValues(vec1);
    
    cout << endl;

	if ( getIntsFromFile(infile, vec2) )
		printValues(vec2);

    return 0;
}

