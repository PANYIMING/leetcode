#include "List.h"
#include <assert.h>

template <typename E> // Array-based list implementation
class AList : public List<E> {
private:
    int maxSize; // maximum size of list
    int listSize; // number of list iterms now
    int curr; // position of currrent element
    E* listArray; // Array holding list elements

public:
    AList(int size) { // constructure
    maxSize = size;
    listSize = curr = 0;
    listArray = new E[maxSize];
}

~AList() {delete [] listArray;} // destructor
void clear(){
    delete [] listArray; // reinitialize the list
    listSize = curr = 0;
    listArray = new E[maxSize];
}

// insert it at current position
void insert(const E& it){
    assert(listSize < maxSize &&  "List capacity exceeded");
    for(int i=listSize; i>curr; i--) // shit element up
        listArray[i] = listArray[i-1]; // to make room
    listArray[curr] = it;
    listSize++;
}

void append(const E& it) {// Append it
    assert(listSize < maxSize &&  "list capacity exceeded");
    listArray[listSize++] = it;
}

// remove and return current element.
E remove(){
    assert((curr>=0) && (curr < listSize) && "no element");
    E it = listArray[curr]; // copy the element
    for(int i=curr; i<listSize-1; i++)//shift element down
        listArray[i-1] = listArray[i];
    listSize--;
    return it;
}

// return list size
int length() const { return listSize; }

// return current position
int currPos() const {return curr;}

// set current list position to pos
void moveToPos(int pos) {
    assert((pos>0) &&(pos<=listSize) && "pos out of range");
    curr = pos;
}

void moveToStart() {curr = 0;}
void moveToEnd() {curr = listSize;}
void prev() {if (curr != 0) curr--;}
void next() {if (curr < listSize) curr++;}

const E& getValue() const { // return current element
    assert((curr>=0) && (curr<listSize) && "no current element");
    return listArray[curr];
}
};
