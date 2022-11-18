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
        head = new DLink<E>; 
        tail = new DLink<E>;
        assert(head != NULL);
        assert(tail != NULL);

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
        cout << "Copy constructor" << endl;
        // ??? - implement this method
        source.head = new DLink<E>;
        source.tail = new DLink<E>;
        source.curr = new DLink<E>;
        cnt = source.cnt;

        head = new DLink<E>; 
        tail = new DLink<E>;
        assert(head != NULL);
        assert(tail != NULL);

        curr = head;
        cnt = 0;

        head->nextPtr = tail;
        head->prevPtr = nullptr;
        tail->prevPtr = head;
        tail->nextPtr = nullptr;
        DLink<E> *temp = source.head;

        while (temp->nextPtr != source.tail)
        {
            append(temp->nextPtr->theElement);
            temp = temp->nextPtr;
            if (temp == source.curr)
                curr = temp;
        }
    }
    ///need

    // The class destructor
    ~DList()
    {
        // ??? - implement this method
        clear();        //delete all elements
        delete head;
        delete tail;
        //delete curr;
    }

    // Empty the list
    void clear()
    {
        curr = head;
      // while(head->nextPtr != NULL && head->nextPtr != tail)
        moveToStart();
        while (curr->nextPtr != tail)
        {
            remove();
        }
        
      /*  while(head->nextPtr != tail) //need to modify HERE
         {
           DLink<E> *tmp = head->nextPtr;
           head->nextPtr = head->nextPtr->nextPtr;
           head->nextPtr->nextPtr->prevPtr = head; //check here
           delete tmp;
        }*/
        cnt = 0;
        
        //curr = head-> nextPtr;
        head->nextPtr = tail;
        tail->prevPtr = head;

       // curr  = tail = head = new DLink<E>;
        // dlist()??
        // ??? - implement this method
        //
    }

    // Set current to first element
    void moveToStart()
    {                   // comment remove?
        curr = head;   
        //curr = head -> nextPtr;  //move curr to what head is pointing which is the first element
    }

    // Set current element to end of list
    void moveToEnd() 
    {
        //curr = tail;  //move curr to tail, no curr link here
        curr = tail->prevPtr; 
    }

    // Advance current to the next element
    void next()
    {                   ///need to recheck here
        //if (curr != tail->prevPtr) //check curr is not at tail since nothing is after tail
        if (curr != tail)
            curr = curr->nextPtr;   //set curr to the next element
    }

    // Return the current element
    E & getValue() const
    {
        assert( curr->nextPtr != NULL);
        //if (curr->nextPtr != tail) 
        //if (curr != tail && curr != head) 
            return curr->nextPtr->theElement;  
        //return curr->theElement;
        // ??? - implement this m
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
        curr -> nextPtr -> prevPtr = tmp; //the prevPtr of what curr nextPtr is pointing is set to tmp
        curr -> nextPtr = tmp;             // curr's nextPtr set to point to tmp

        tmp -> theElement = it;     //set the element
        //curr = tmp;//
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

        tmp -> theElement = it;\
        //curr = tmp;
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
        if (curr != head->prevPtr)         //curr will not go to head
            curr = curr->prevPtr;
    }

    // Return position of the current element
    int currPos() const
    {
       // DLink<E>* temp = head; //still need to fix since this is only used when head has a value
    /*   DLink<E>* temp = head->nextPtr;
        int i;
        for (i=0; curr != temp; i++)   
        {
            temp = temp->nextPtr;
        }
        return i;  */ 

        DLink<E>* temp = curr;
        int i;
        for (i=0; temp != head -> nextPtr; i++)
        {
            temp = temp->prevPtr;
        }
        return i;
    }

    // Set current to the element at the given position
    void moveToPos(int pos)
    {
        //assert ((pos>=0)&&(pos<=cnt), "Position out of range");
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
        theList.append(i); //0 1 2 3 4 5 6 7 8 9
    }
    while (i < 20)
    {
        theList.insert(i); //19 18 17 16 15 14 13 12 11 10

        ++i;
    }

    //theList.moveToPos(10);
    //cout<<"pos10";
    //cout << theList.getValue() << " ";

    // display the contents of the list
    theList.moveToStart();
    for (i = 0; i < theList.length(); ++i) //cnt = 20
    {
        cout << theList.getValue() << " ";

        theList.next();  //19 18 17 16 15 14 13 12 11 10 0 1 2 3 4 5 6 7 8 9
    }
    cout << "\n";

    // display the contents of the list in reverse order
    theList.moveToEnd();
    for (i = 0; i < theList.length(); ++i) //cnt = 20
    {
        theList.prev(); //from tail to last element

        cout << theList.getValue() << " ";
    }                   //9 8 7 6 5 4 3 2 1 0 10 11 12 13 14 15 16 17 18
    cout << "\n";

    // replace the contents of the list
    theList.clear();   // no list
    for (i = 0; i < 10; ++i)
    {
        theList.append(i + 100); //100 101 102 103 104 105 106 107 108 109
    }

    // display the contents of the list
    theList.moveToStart();
    for (i = 0; i < theList.length(); ++i)
    {
        cout << theList.getValue() << " "; //100 101 102 103 104 105 106 107 108 109

        theList.next();
    }
    cout << "\n";

    // remove two elements at the specified position
    theList.moveToPos(5); // 105
    cout << theList.currPos() << "\n";

    theList.remove();   //remove 106
    theList.remove();   //remove 107

    // display the contents of the list
    theList.moveToStart();
    for (i = 0; i < theList.length(); ++i)
    {
        cout << theList.getValue() << " "; //100 101 102 103 104 105 108 109

        theList.next();
    }
    cout << "\n";

    return 0;
}
