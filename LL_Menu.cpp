#include <stdlib.h>
#include <iostream>
using namespace std;

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
            cout<<traverser->data<<endl;
            traverser = traverser->next;
        }
    }
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

int main () {
    int con, ch, cnt;
    List ll;
    do {
        cout<<"Enter Choice:\n1 - Create\n2 - Display\n3 - Insert at Start\nHere: ";
        cin>>ch;
        switch (ch) {
            case 1:
                cout<<"Enter no. of nodes: ";
                cin>>cnt;
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
                break;
        }
        cout<<"Press 1 Continue, Else Press Anything."<<endl;
        cin>>con;
    } while (con == 1);
    
    return 0;
}