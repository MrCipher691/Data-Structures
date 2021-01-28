#include <stdio.h>
#include <iostream>
using namespace std;

class Node {
    public:
        string data;
        Node *next;
};

void printer(Node *n) {
    while (n != NULL) {
        cout<<n->data<<endl;
        n = n->next;
    }
}

int main () {
    Node *header = NULL;
    Node *first = NULL;
    Node *second = NULL;
    Node *third = NULL;
    Node *fourth = NULL;
    Node *fifth = NULL;

    header = new Node();
    first = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();
    fifth = new Node();

    header->next = first;  
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    int ch = 0;
    cout<<"OPTIONS:"<<endl<<"1. Press - 0 For Default Strings"<<endl<<"2. Press - 1 To Enter Strings"<<endl<<"Enter: ";
    cin>>ch;
    if (ch==0) {
        first->data = "Violet";
        second->data = "Blue";
        third->data = "Green";
        fourth->data = "Orange";
        fifth->data = "Red";

        cout<<endl<<"FINAL OUTPUT"<<endl;
        printer(header);
    }
    else if (ch==1) {
        cout<<"Taking Inputs:\n";
        cout<<"Enter 1st string: ";
        cin>>ws;
        getline(cin, first->data);
        cout<<"Enter 2nd string: ";
        getline(cin, second->data);
        cout<<"Enter 3rd string: ";
        getline(cin, third->data);
        cout<<"Enter 4th string: ";
        getline(cin, fourth->data);
        cout<<"Enter 5th string: ";
        getline(cin, fifth->data);

        cout<<endl<<"FINAL OUTPUT"<<endl;
        printer(header);
    }
    else {
        cout<<"INVALID INPUT"<<endl;
    }

    delete header;
    delete first;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}