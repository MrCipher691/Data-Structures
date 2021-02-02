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
    cout<<"Case 1"<<endl;
}

void List::display() {
    cout<<"Case 2"<<endl;
}

int main () {
    int con, ch;
    List LL;
    do {
        cout<<"Enter Choice:\n1 - Create\n2 - Display\nHere: ";
        cin>>ch;
        switch (ch) {
            case 1:
                LL.create();
                break;
            case 2:
                LL.display();
                break;
        }
        cout<<"Press 1 Continue, Else Press Anything."<<endl;
        cin>>con;
    } while (con == 1);
    
    return 0;
}