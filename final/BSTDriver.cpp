/*Driver program demonstrating creating a tree, adding, finding and deleting nodes
Dr. Augustine 10/30/2017
Status: works with completed and correct BSTree.cpp
*/

/*Template Directions: #include "BSTREEInt.hpp"
but do NOT compile it (or add it to the project)*/
#include <iostream>
#include "BSTree.h"
#include "BSTree.hpp"
using namespace std;

int main()
{
	BSTree<GeneralData, int> *tree = new BSTree<GeneralData, int>;
	cout << "Adding Nodes...\n";
	GeneralData tempData;
	tempData.number = 10;
	tempData.name = "Gamma";
	tree->addNode(tempData.number, tempData);

	tempData.number = 5;
	tempData.name = "Gamma";
	tree->addNode(tempData.number, tempData);

	tempData.number = 1;
	tempData.name = "Alpha";
	tree->addNode(tempData.number, tempData);

	tempData.number = 20;
	tempData.name = "Delta";
	tree->addNode(tempData.number, tempData);

	tempData.number = 30;
	tempData.name = "Eta";
	tree->addNode(tempData.number, tempData);
	
	tempData.number = 25;
	tempData.name = "Epsilon";
	tree->addNode(tempData.number, tempData);
	
	tempData.number = 2;
	tempData.name = "Beta";
	tree->addNode(tempData.number, tempData);

	cout << "Printing in order...\n";
	tree->printInorder();

	if (tree->findNode(25) != nullptr)
		cout << "25 found\n";
	else
		cout << "25 not found\n";

	if (tree->findNode(26) != nullptr)
		cout << "26 found\n";
	else
		cout << "26 not found\n";

	cout << "After Deleting 1...\n";
	tree->deleteNode(1);
	tree->printInorder();

	cout << "After Deleting 10...\n";
	tree->deleteNode(10);
	tree->printInorder();

	cout << "After Deleting 25...\n";
	tree->deleteNode(25);
	tree->printInorder();

	cout << "After Deleting 2...\n";
	tree->deleteNode(2);
	tree->printInorder();

	cout << "After Deleting 5...\n";
	tree->deleteNode(5);
	tree->printInorder();

	cout << "After Deleting 20...\n";
	tree->deleteNode(20);
	tree->printInorder();

	cout << "After Deleting 30...\n";
	tree->deleteNode(30);
	tree->printInorder();
}