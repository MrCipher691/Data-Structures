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
    void delBeg();
    void delMid();
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
        cout<<"List is Empty"<<endl;
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

void List::delBeg() {
    if (listptr == NULL)
        cout<<"Nothing to Delete"<<endl;
    else if (len == 1) {
        listptr = temp = NULL;
        len--;
    }
    else {
        listptr = listptr->next;
        len--;
    }
}

void List::delMid() {
    if (listptr == NULL)
        cout<<"Nothing to Delete"<<endl;
    else if (len == 1) {
        listptr = temp = NULL;
        len--;
    }
    else {
        int pos = (len/2) + 1;
        Node *address = listptr;
        Node *addressNext = listptr;
        for (int i = 1; i < (pos - 1); i++)
            address = address->next;
        for (int i = 1; i < (pos); i++)
            addressNext = addressNext->next;
        address->next = addressNext->next;
        len--;
    }
}

int main () {
    int con, ch, cnt;
    List ll;
    do {
        cout<<"Enter Choice:\n1 - Display\n2 - Create\n3 - Insert at Start\n4 - Insert at Middle\n5 - Insert at End\n6 - Delete at Start\n7 - Delete at Middle\nHere: ";
        cin>>ch;
        switch (ch) {
            case 1:
                ll.display();
                break;
            case 2:
                cout<<"Enter no. of nodes: ";
                cin>>cnt;
                len += cnt;
                while(cnt != 0) {
                    ll.create();
                    cnt--;
                }
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
                break;
            case 6:
                ll.delBeg();
                break;
            case 7:
                ll.delMid();
                break;
            default:
                cout<<"INVLAID INPUT"<<endl;
                break;
        }
        cout<<"Press 1 Continue, Else Press Anything."<<endl;
        cin>>con;
    } while (con == 1);
    return 0;
}