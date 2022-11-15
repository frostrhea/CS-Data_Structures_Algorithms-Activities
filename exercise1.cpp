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
        this();
    }

    // The default constructor
    DList()
    {
        // ??? - implement this method
        head = new DLink<E>; 
        tail = new DLink<E>;
        assert(head != NULL);
        assert(tail!= NULL);

        curr = head;
        cnt = 0;

        head->nextPtr = tail;
        head->prevPtr = nullptr;
        tail->prevPtr = head;
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
        curr = head;
        clear();        //delete all elements
        curr = tail;
        delete head;
        delete curr;

    /*    while(head != NULL)
        {
           DLink<E> *tmp = head;
           head = head->nextPtr;
           delete tmp;
        }*/
    }

    // Empty the list
    void clear()
    {
       
       while(head->nextPtr != NULL && head->nextPtr != tail)
       {
           DLink<E> *tmp = head->nextPtr;
           head->nextPtr = head->nextPtr->nextPtr;
           delete tmp;
       }
        cnt = 0;
       // curr  = tail = head = new DLink<E>;

        // ??? - implement this method
        //
    }

    // Set current to first element
    void moveToStart()
    {
        curr = head -> nextPtr;   //move curr to what head is pointing which is the first element
    }

    // Set current element to end of list
    void moveToEnd()
    {
        curr = tail -> prevPtr;  //move curr to what tail is pointing which is the last element
    }

    // Advance current to the next element
    void next()
    {
        if (curr != tail) //check curr is not at tail since nothing is after tail
            curr = curr->nextPtr;   //set curr to the next element
    }

    // Return the current element
    E & getValue() const
    {
        //assert(curr->nextPtr != NULL);
        //assert(curr->nextPtr != NULL, "No value");
        //return curr->nextPtr->theElement; 
        return curr->theElement;  
        // ??? - implement this method
        //
    }

    // Insert value at current position
    void insert(const E &it)
    {
        /* this insert function works by allocating a tmp link, changing where curr and its next element are pointing
        by making them point to tmp and tmp will also point to them. Then, set the theElement of tmp by it */
        DLink<E> *tmp = new DLink<E>;      // create tmp link
        assert (tmp != NULL);              //check for errors

        tmp -> nextPtr = curr -> nextPtr;  // tmp's nextPtr set to point to where curr nextPtr is pointing
        tmp -> prevPtr = curr;             // tmp's prevPtr set to point to curr
        curr -> nextPtr = tmp;             // curr's nextPtr set to point to tmp
        curr -> nextPtr -> prevPtr = tmp; //the prevPtr of what curr nextPtr is pointing is set to tmp

        tmp -> theElement = it;     //set the element

      //  curr = tmp;
        cnt++;
    }

    // Append value at the end of the list
    void append(const E &it)
    {
        /*this append function works by allocating a tmp link, changing where tail and last element are pointing
        by making them point to tmp and tmp will also point to them. Then set the theElement of tmp by it and add count*/
        DLink<E> *tmp = new DLink<E>; // create tmp link
        assert( tmp != NULL );        // check for errors


        tmp -> nextPtr = tail;      // tmp's next pointer set to tail
        tmp -> prevPtr = tail -> prevPtr;  //tmp's prev pointer set to what tail's prevPtr is pointing
        tail -> prevPtr -> nextPtr = tmp;  //the nextPtr of what tail's prevPtr is pointing is set to temp
        tail -> prevPtr = tmp;      //tail's prevPtr is set to tmp

        tmp -> theElement = it;
        cnt++;
    }

    // Remove and return the current element
    E remove()
    {   /*this remove function works by checking curr's nextPtr is not at tail since tail cannot be remove(only elements).
        The element of the link to be remove is accessed for returning element. .... */
        if (curr->nextPtr == tail) //checking 
            return NULL;
        E it = curr -> nextPtr -> theElement; //remember value
        DLink<E>*tmp = curr -> nextPtr;     
        curr -> nextPtr -> nextPtr -> prevPtr = curr;
        curr -> nextPtr = curr -> nextPtr -> nextPtr;


        delete tmp;
        cnt--;
        return it;
    }

    // Advance current to the previous element
    void prev()
    {
        if (curr != head && cnt > 0)         //checking [[[0 or 1?]]]
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
        for (i=0; curr != temp; i++)   // [[[0 or 1?]]]
        {
            temp = temp->nextPtr;
        }
        return i;
    }

    // Set current to the element at the given position
    void moveToPos(int pos)
    {
        //assert ((pos>=0)&&(pos<=cnt), "Position out of range");
    /*   curr = head;
        for(int i=0; i<pos; i++) //<=
        {
            curr = curr->nextPtr;
        }
        // ??? - implement this method
        if ( cnt/2 <= pos)  
            curr = head;
            for(int i=0; i<pos; i++) //<=
            {
                 curr = curr->nextPtr;
            }
        else 
            curr = tail;
            for (int i=0; i<pos; i++)
            {
                curr = curr->nextPtr;
            } */
       //
            curr = head -> nextPtr;
            for(int i=0; i<pos; i++) //<=
            {
                 curr = curr->nextPtr; // segmentation fault here
            }
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
