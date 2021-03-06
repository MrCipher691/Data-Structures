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
    public:
    Node *listptr, *temp;
    List() {
        listptr = NULL;
        temp = NULL;
    }
    void display();
    void create();
    void insertBeg();
    void insertMid();
    void delBeg();
    void delMid();
    void delEnd();
    void reverse();
    void concat(List ll2);
};

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
    cout<<"Number of Elements in Linked List are "<<len<<endl;
}

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
        free(temp);
        listptr = temp = NULL;
        len--;
    }
    else {
        Node *tbd;
        tbd = listptr;
        listptr = listptr->next;
        free(tbd);
        len--;
    }
}

void List::delMid() {
    if (listptr == NULL)
        cout<<"Nothing to Delete"<<endl;
    else if (len == 1) {
        free(temp);
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
        free(addressNext);
        len--;
    }
}

void List::delEnd() {
    if (listptr == NULL)
        cout<<"Nothing to Delete"<<endl;
    else if (len == 1) {
        free(temp);
        listptr = temp = NULL;
        len--;
    }
    else {
        Node *address = listptr;
        for (int i = 1; i < (len - 1); i++)
            address = address->next;
        temp = address;
        temp->next = NULL;
        len--;
    }
}

void List::reverse() {
    Node *forward, *curr, *back;
    curr = listptr;
    back = NULL;
    while(curr!=NULL) {
      forward = curr->next;
      curr->next = back;
      back = curr;
      curr = forward;
    }
    listptr = back;
}

void List::concat(List ll2) {
    temp->next = ll2.listptr;
    temp = ll2.temp;
}

int main () {
    int con, ch, cnt;
    List ll, ll2;
    do {
        cout<<"Enter Choice:\n1 - Display\n2 - Create\n3 - Insert at Start\n4 - Insert at Middle\n5 - Insert at End\n6 - Delete at Start\n7 - Delete at Middle\n8 - Delete at End\n9 - Reverse\n10 - Concatenation\nHere: ";
        cin>>ch;
        switch (ch) {
            case 1:
                ll.display();
                break;
            case 2:
                cout<<"Enter no. of nodes: ";
                cin>>cnt;
                if (cnt <= 0)
                    cout<<"Please Enter a Positive Non Zero Integer"<<endl;
                else {
                    len += cnt;
                    while(cnt != 0) {
                        ll.create();
                        cnt--;
                    }
                    ll.display();
                }
                break;
            case 3:
                ll.insertBeg();
                len += 1;
                ll.display();
                break;
            case 4:
                ll.insertMid();
                len += 1;
                ll.display();
                break;
            case 5:
                ll.create();
                len += 1;
                ll.display();
                break;
            case 6:
                ll.delBeg();
                ll.display();
                break;
            case 7:
                ll.delMid();
                ll.display();
                break;
            case 8:
                ll.delEnd();
                ll.display();
                break;
            case 9:
                ll.reverse();
                ll.display();
                break;
            case 10:
                int temp;
                cout<<"Enter no. of elements in 2nd list: ";
                cin>>temp;
                len += temp;
                while(temp != 0) {
                    ll2.create();
                    temp--;
                }
                ll.concat(ll2);
                cout<<"| -- LIST AFTER CONCATENATION -- |"<<endl;
                ll.display();
                break;
            default:
                cout<<"INVLAID INPUT"<<endl;
                break;
        }
        cout<<"Press 1 Continue, Else Press Anything: ";
        cin>>con;
    } while (con == 1);
    return 0;
}