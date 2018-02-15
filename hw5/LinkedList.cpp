
#include "LinkedList.h"

LinkedList::LinkedList() {
    this->n.data = '\0';
    this->n.nextPtr = nullptr;
}

LinkedList::~LinkedList() {
    if (n.nextPtr != nullptr) {
        Node *targetPtr = this->n.nextPtr;
        while (targetPtr->nextPtr != nullptr) {
            Node* nextPtr = targetPtr->nextPtr;
            free(targetPtr);
            targetPtr = nextPtr;
        }
        n.nextPtr = nullptr;
    }
}

bool LinkedList::insertAtFront(char value) {
    //copy the old first node from local instance memory to the heap
    Node *heapPtr = (Node *) malloc(sizeof(Node));
    memcpy(heapPtr, &this->n, sizeof(Node));

    //instantiate a new node in local scope memory
    Node newNode;
    newNode.data = value;
    newNode.nextPtr = heapPtr;

    //store the new node to local instance memory
    this->n = newNode;

    return true;
}

bool LinkedList::insertBeforePosition(char value, int index) {
    if (index < 0) return false;
    if (index == 0) return this->insertAtFront(value);

    Node *prevPtr = nullptr;
    Node *targetPtr = &n;
    for (unsigned int i = 0; i < index; i++) {
        if (targetPtr->nextPtr == nullptr) {
            return false;
        }
        prevPtr = targetPtr;
        targetPtr = targetPtr->nextPtr;
    }

    Node *n = (Node *) malloc(sizeof(Node));
    n->data = value;
    n->nextPtr = targetPtr;

    prevPtr->nextPtr = n;

    return true;
}

bool LinkedList::insertAtBack(char value) {
    Node *targetPtr = &(this->n);
    while (targetPtr->nextPtr != nullptr) {
        targetPtr = targetPtr->nextPtr;
    }

    Node *n = (Node *) malloc(sizeof(Node));
    n->data = value;
    n->nextPtr = nullptr;

    targetPtr->nextPtr = n;

    return true;
}

bool LinkedList::deleteAtFront() {
    if (this->n.data == '\0') return false;

    this->n = *this->n.nextPtr;
    return true;
}

bool LinkedList::deletePosition(int index) {
    if (this->n.data == '\0') return false;

    if (index < 0) return false;
    if (index == 0) return this->deleteAtFront();

    Node *prevPtr = nullptr;
    Node *targetPtr = &n;
    for (unsigned int i = 0; i < index; i++) {
        if (targetPtr->nextPtr == nullptr) {
            return false;
        }
        prevPtr = targetPtr;
        targetPtr = targetPtr->nextPtr;
    }

    prevPtr->nextPtr = targetPtr->nextPtr;
    free(targetPtr);

    return true;
}

bool LinkedList::deleteAtBack() {
    if (this->n.data == '\0') return false;

    Node *prevPtr = nullptr;
    Node *targetPtr = &(this->n);
    while (targetPtr->nextPtr != nullptr) {
        prevPtr = targetPtr;
        targetPtr = targetPtr->nextPtr;
    }

    if (prevPtr != nullptr) {
        prevPtr->nextPtr = nullptr;
        free(targetPtr);

        return true;
    }

    return false;
}

ostream &operator<<(ostream &out, LinkedList *list) {
    out << list->n.data;
    Node *nextPtr = list->n.nextPtr;
    while (nextPtr != nullptr) {
        if (nextPtr->data != '\0') out << nextPtr->data;
        nextPtr = nextPtr->nextPtr;
    }
    return out;
}
