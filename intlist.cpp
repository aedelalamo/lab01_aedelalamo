// intlist.cpp
// Implements class IntList
// AGUSTIN DELALAMO 1/15/2026

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    head = nullptr;
    tail = nullptr;
    if (!source.head) return;

    head = new Node{source.head->info, nullptr};
    Node* currdest = head;
    Node* currsrc = source.head->next;

    while (currsrc) {
        currdest->next = new Node{currsrc->info, nullptr};
        currdest = currdest->next;
        currsrc = currsrc->next;
    }

    tail = currdest;
}

// destructor deletes all nodes
IntList::~IntList() {
    while(head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}


// return sum of values in list
int IntList::sum() const {
    int sum = 0;
    Node* curr = head;
    while (curr) {
        sum += curr->info;
        curr = curr->next;
    }
    return sum; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* curr = head;
    while (curr) {
        if (curr->info == value) return true;
        curr = curr->next;
    }
    return false; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if (!head) return 0;
    Node* curr = head;
    int max = curr->info;
    while (curr) {
        if (curr->info > max) max = curr->info;
        curr = curr->next;
    }
    return max; // REPLACE THIS NON-SOLUTION
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (!head) return 0;
    return sum()/count(); // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
    if (!tail) tail = newNode;
}

// append value at end of list
void IntList::push_back(int value) {
    Node* newTail = new Node{value, nullptr};
    if (!head) {
        head = newTail;
        tail = newTail;
    } else {
        tail->next = newTail;
        tail = newTail;
    }
}

// return count of values
int IntList::count() const {
    int count = 0;
    Node* curr = head;
    while (curr) {
        count++;
        curr = curr->next;
    }
    return count;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (this == &source) return *this;

    // delete existing nodes
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    head = tail = nullptr;

    // copy nodes from source
    Node* currsrc = source.head;
    while (currsrc) {
        push_back(currsrc->info);
        currsrc = currsrc->next;
    }
    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    head = nullptr;
    tail = nullptr;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

