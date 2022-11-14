//Rhea Salve Guingao 2021-2362
/*
CCC121 Laboratory Exercise No. 1
Due: November 20, 2022 (Sunday) at 11:55PM
*/

#include <iostream>
#include <assert.h>

using namespace std;

/*
The structure to be used for representing a doubly-linked link. This struct
declaration should not be modified in any way.
*/
template <class E>
struct DLink
{
    E theElement;
    DLink<E> *nextPtr;
    DLink<E> *prevPtr;
};

/*
Complete this implementation variant of the doubly-linked list. Use the same
convention as described in the slides. The DLink declaration to be used here is
just a struct and should not be modified in any way. All of the operations of
the original DLink class must be done in the methods of this class. Use
assertions to ensure the correct operation of this ADT. All memory allocations
should be checked with assertions and all discarded memory must be properly
deallocated.
*/
template <class E>
class DList
{
    DLink<E> *head;
    DLink<E> *tail;
    DLink<E> *curr;
    int cnt;

public:
    // Return the size of the list
    int length() const
    {
        return cnt;
    }

    // The constructor with initial list size
    DList(int size)
    {
        //this();
        curr  = tail = head = new DLink<E>;
        cnt = 0;
    }

    // The default constructor
    DList()
    {
        // ??? - implement this method
        head = new DLink<E>; 
        tail = new DLink<E>;
        curr = head;
        cnt = 0;

        head->nextPtr = tail;
        head->prevPtr = nullptr;
        tail->nextPtr = head;
        tail->nextPtr = nullptr;
    }

    // The copy constructor
    DList(const DList &source)
    {
        //
        // ??? - implement this method
        head = source.head;
        tail = source.tail;
        curr = source.curr;

    }

    // The class destructor
    ~DList()
    {
        // ??? - implement this method
        while(head != NULL)
        {
           DLink<E> *temp = head;
           head = head->nextPtr;
           delete temp;
        }
    }

    // Empty the list
    void clear()
    {
       // removeall();
       while(head != NULL)
       {
           DLink<E> *temp = head;
           head = head->nextPtr;
           delete temp;
       }

        curr  = tail = head = new DLink<E>;
        cnt = 0;
        // ??? - implement this method
        //
    }

    // Set current to first element
    void moveToStart()
    {
        curr = head -> nextPtr;
        // ??? - implement this method
        //
    }

    // Set current element to end of list
    void moveToEnd()
    {
        curr = tail -> prevPtr;
        // ??? - implement this method
        //
    }

    // Advance current to the next element
    void next()
    {
        if (curr != tail && cnt > 1) 
            curr = curr->nextPtr;
        // ??? - implement this method
        //
    }

    // Return the current element
    E & getValue() const
    {
        //assert(curr->nextPtr != NULL, "No value");
        return curr->nextPtr->theElement;
        // ??? - implement this method
        //
    }

    // Insert value at current position
    void insert(const E &it)
    {
        //
        // ??? - implement this method
        //
    }

    // Append value at the end of the list
    void append(const E &it)
    {
        //
        // ??? - implement this method
        DLink<E> *tmp = new DLink<E>;
        assert( tmp != NULL );

        tmp -> nextPtr = tail;
        tmp -> prevPtr = tail -> prevPtr;
        tail -> prevPtr -> nextPtr = tmp;
        tail -> prevPtr = tmp;

        tmp -> theElement = it;
    }

    // Remove and return the current element
    E remove()
    {
        //
        // ??? - implement this method
        E it = curr->nextPtr->theElement; // Remember value
        DLink<E>* ltemp = curr->nextPtr; // Remember link node

        if (tail == curr->nextPtr) // Reset tail
        {
            tail = curr;
        } 

        curr->nextPtr = curr->nextPtr->nextPtr; // Remove from list
        delete ltemp; // Reclaim space
        cnt--; // Decrement the count
        return it;
    }

    // Advance current to the previous element
    void prev()
    {
        if (curr != head && cnt > 1)         //checking 
            curr = curr->prevPtr;
        // ??? - implement this method
        //
    }

    // Return position of the current element
    int currPos() const
    {
       // DLink<E>* temp = head; //still need to fix since this is only used when head has a value
        DLink<E>* temp = head->nextPtr;
        int i;
        for (i=0; curr != temp; i++)
        {
            temp = temp->nextPtr;
        }
        return i;
    }

    // Set current to the element at the given position
    void moveToPos(int pos)
    {
    /*  assert ((pos>=0)&&(pos<=cnt), "Position out of range");
        curr = head;
        for(int i=0; i<pos; i++) 
        {
            curr = curr->nextPtr;
        }
        // ??? - implement this method
    */    //
    }
};

/*
This is the main function for testing the implementation of the DList class.
This function can be freely modified.
*/
int main(void)
{
    int i;
    DList<int> theList;

    // populate the list
    for (i = 0; i < 10; ++i)
    {
        theList.append(i);
    }
    while (i < 20)
    {
        theList.insert(i);

        ++i;
    }

    // display the contents of the list
    theList.moveToStart();
    for (i = 0; i < theList.length(); ++i)
    {
        cout << theList.getValue() << " ";

        theList.next();
    }
    cout << "\n";

    // display the contents of the list in reverse order
    theList.moveToEnd();
    for (i = 0; i < theList.length(); ++i)
    {
        theList.prev();

        cout << theList.getValue() << " ";
    }
    cout << "\n";

    // replace the contents of the list
    theList.clear();
    for (i = 0; i < 10; ++i)
    {
        theList.append(i + 100);
    }

    // display the contents of the list
    theList.moveToStart();
    for (i = 0; i < theList.length(); ++i)
    {
        cout << theList.getValue() << " ";

        theList.next();
    }
    cout << "\n";

    // remove two elements at the specified position
    theList.moveToPos(5);
    cout << theList.currPos() << "\n";

    theList.remove();
    theList.remove();

    // display the contents of the list
    theList.moveToStart();
    for (i = 0; i < theList.length(); ++i)
    {
        cout << theList.getValue() << " ";

        theList.next();
    }
    cout << "\n";

    return 0;
}
