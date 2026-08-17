#include <iostream>
using namespace std;


class StringNode
{               // A node in a list of strings
private:
    string elem;                   // element value
    StringNode *next;              // next item in the list
    friend class StringLinkedList; // provide StringLinkedList access
};

class StringLinkedList
{               // A linked list of strings
public:
    StringLinkedList();             // empty list constructor
    ~StringLinkedList();             // destructor
    bool empty() const;             // is list empty?
    const string &front() const;    // get front element
    void addFront(const string &e); // add to front of list
    void removeFront();             // remove front item list
    void print() const;             // print all list elements
private:
    StringNode *head; // pointer to the head of list
};


// constructor
StringLinkedList::StringLinkedList() 
    : head(NULL) {}

// destructor
StringLinkedList::~StringLinkedList() 
    { while (!empty()) removeFront(); }

// is list empty?
bool StringLinkedList::empty() const 
    { return head == NULL; }

// get front element
const string &StringLinkedList::front() const 
    { return head->elem; }

// add to front of list
void StringLinkedList::addFront(const string &e){
    StringNode *v = new StringNode;   // create new node
    v->elem = e;                     // store data
    v->next = head;                  // head now follows v
    head = v;                         // v is now the head
}

// remove front item
void StringLinkedList::removeFront(){    
    StringNode *old = head; // save current head
    head = old->next;     // skip over old head
    delete old;             // delete the old head
}

int main(){

    StringLinkedList myTravel;

    myTravel.addFront("BOS");
    myTravel.addFront("ATL");
    myTravel.addFront("MSP");

    myTravel.print();
    myTravel.addFront("LAX");
    cout << endl;
    myTravel.print();

    myTravel.removeFront();
    myTravel.removeFront();
    cout << endl;
    myTravel.print();

}

void StringLinkedList::print() const{
    StringNode * curr = head;
    while(curr != NULL){
        cout << curr->elem << " -> "; 
        curr=curr->next; 
    }
    cout << " (End) ";

}