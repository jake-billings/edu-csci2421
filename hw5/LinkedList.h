/**
 * ======================== Update =========================
 * This implementation is locked by project requirements
 * to use a pre-written header file. This header file
 * contains a full Node object as the head instead of
 * just a head pointer. It also doesn't use generic typing.
 * A better LinkedList example is available at this link:
 *
 * https://github.com/jake-billings/edu-csci2312/tree/master/hw06
 */

#include <iostream>
using namespace std;

struct Node
{
      char data;
      Node* nextPtr;
};

class LinkedList
{
private:
	Node n;
public:	
	LinkedList();
	~LinkedList();
	bool insertAtFront(char value);
	bool insertBeforePosition(char value, int index);  
		//first Node after headptr is 1
		//false if pos zero or out of range
	bool insertAtBack(char value);
	bool deleteAtFront();
	bool deletePosition(int index); 
		//first Node after headptr is 1
		//false if pos zero or out of range
	bool deleteAtBack();
	//false if empty
	friend ostream& operator << (ostream &out, LinkedList *list);
};
