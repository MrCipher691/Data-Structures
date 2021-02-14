#include <stdlib.h>
#include <iostream>
using namespace std;

int len = 0;

class Node {
    public:
        int data;
        Node *next;
};

class List:public Node {
    Node *listptr, *temp;
    public:
    List() {
        listptr = NULL;
        temp = NULL;
    }
    void create();
    void display();
    void insertBeg();
    void insertMid();
};

void List::create() {
    Node *nextNode = new Node();
    cout<<"Enter Data: ";
    cin>>nextNode->data;
    nextNode->next = NULL;
    if(listptr == NULL) {
        nextNode->next = NULL;
        listptr = nextNode;
        temp = nextNode;
    }
    else {
        temp->next = nextNode;
        temp = nextNode;
    }
}

void List::display() {
    cout<<"- LINKED LIST DISPLAY -"<<endl;
    if (listptr == NULL)
        cout<<"Lmao Nothing Here";
    else {
        Node *traverser = listptr;
        while (traverser != NULL) {
            cout<<traverser->data<<" -> ";
            traverser = traverser->next;
        }
        cout<<endl;
    }
    cout<<"Number of elements in linked list is "<<len<<endl;
}

void List::insertBeg() {
    Node *nextNode = new Node();
    cout<<"Enter Data: ";
    cin>>nextNode->data;
    if(listptr == NULL) {
        nextNode->next = NULL;
        listptr = nextNode;
        temp = nextNode;
    }
    else {
        nextNode->next = listptr;
        listptr = nextNode;
    }
}

void List::insertMid() {
    Node *nextNode = new Node();
    cout<<"Enter Data: ";
    cin>>nextNode->data;
    if(listptr == NULL) {
        nextNode->next = NULL;
        listptr = nextNode;
        temp = nextNode;
    }
    else if (len == 1) {
        nextNode->next = NULL;
        temp->next = nextNode;
        temp = nextNode;
    }
    else {
        int pos = (len/2) + 1;
        Node *address = listptr;
        for (int i = 1; i < (pos - 1); i++)
            address = address->next;
        nextNode->next = address->next;
        address->next = nextNode;
    }
}

int main () {
    int con, ch, cnt;
    List ll;
    do {
        cout<<"Enter Choice:\n1 - Create\n2 - Display\n3 - Insert at Start\n4 - Insert at Middle\n5 - Insert at End\nHere: ";
        cin>>ch;
        switch (ch) {
            case 1:
                cout<<"Enter no. of nodes: ";
                cin>>cnt;
                len += cnt;
                while(cnt != 0) {
                    ll.create();
                    cnt--;
                }
                break;
            case 2:
                ll.display();
                break;
            case 3:
                ll.insertBeg();
                len += 1;
                break;
            case 4:
                ll.insertMid();
                len += 1;
                break;
            case 5:
                ll.create();
                len += 1;
        }
        cout<<"Press 1 Continue, Else Press Anything."<<endl;
        cin>>con;
    } while (con == 1);
    return 0;
}