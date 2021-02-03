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
};

void List::create() {
    Node *nextNode = new Node();
    cout<<"Enter Data: ";
    cin>>nextNode->data;
    nextNode->next = NULL;
    if(listptr == NULL) {
        listptr = nextNode;
        temp = nextNode;
    }
    else {
        temp->next=nextNode;
        temp = nextNode;
    }
}

void List::display() {
    cout<<"THE LIGHT"<<endl;
    if (listptr == NULL)
        cout<<"Lmao Nothing Here";
    else {
        temp = listptr;
        while (temp != NULL) {
            cout<<temp->data<<endl;
            temp = temp->next;
        }
    }
}

int main () {
    int con, ch, cnt;
    List ll;
    do {
        cout<<"Enter Choice:\n1 - Create | 2 - Display\nHere: ";
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
        }
        cout<<"Press 1 Continue, Else Press Anything."<<endl;
        cin>>con;
    } while (con == 1);
    
    return 0;
}