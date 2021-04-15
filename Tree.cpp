#include <stdlib.h>
#include <iostream>
#include <stack>
#define COUNT 10
using namespace std;

class node {
    public:
        int data;
        node *left, *right;
        node(int t) {
            data = t;
            left = NULL;
            right = NULL;
        }
};

class binary_tree {
    public:
        node *root;
        node *enterNewNode() {
            int x;
            cout<<"Enter Data: ";
            cin>>x;
            node *temp = new node(x);
            return temp;
        }

        binary_tree() {
            root = NULL;
        }

        void addNode();
        void preOrder(node *t);
        void inOrder(node *t);
        void postOrder(node *t);
        void preOrderIterative(node *head);
        void inOrderIterative(node *head);
        void postOrderIterative(node *head);

        void print2DUtil(node *root, int space);
        void print2D(node *root);
};

void binary_tree::addNode() {
    node *newNode = enterNewNode();
    if (root == NULL)
        root = newNode;
    else {
        string ch;
        node *temp = root;
        while (true) {
            cout << "PUT NODE ON THE LEFT OR RIGHT OF " << temp->data << " (L OR R): ";
            cin >> ch;
            if (tolower(ch[0]) == 'l' || tolower(ch[0]) == '1') {
                if (temp->left == NULL) {
                    temp->left = newNode;
                    break;
                }
                temp = temp->left;
            }
            else if (tolower(ch[0]) == 'r' || tolower(ch[0]) == '2') {
                if (temp->right == NULL) {
                    temp->right = newNode;
                    break;
                }
                temp = temp->right;
            }
        }
    }
}

void binary_tree::preOrder(node *t) {
    if (t == NULL)
        return;
    cout<<t->data<<"  ";
    preOrder(t->left);
    preOrder(t->right);
}

void binary_tree::inOrder(node *t) {
    if (t == NULL)
        return;
    inOrder(t->left);
    cout<<t->data<<"  ";
    inOrder(t->right);
}

void binary_tree::postOrder(node *t) {
    if (t == NULL)
        return;
    postOrder(t->left);
    postOrder(t->right);
    cout<<t->data<<"  ";
}

void binary_tree::preOrderIterative(node *head) {
    if (head == NULL)
        return;
    stack<node *> s;
    s.push(head);
    while (s.empty() == false) {
        node *temp = s.top();
        cout<<temp->data<<"  ";
        s.pop();
        if (temp->right)
            s.push(temp->right);
        if (temp->left)
            s.push(temp->left);
    }
}

void binary_tree::inOrderIterative(node *head) {
    node *temp = head;
    stack<node *> s;
    while (true) {
        while (temp != NULL) {
            s.push(temp);
            temp = temp->left;
        }
        if (s.empty())
            break;
        temp = s.top();
        s.pop();
        cout<<temp->data<<"  ";
        temp = temp->right;
    }
}

void binary_tree::postOrderIterative(node *head) {
    if (head == NULL)
        return;
    
    stack<node *> s1, s2;

    s1.push(head);
    node *temp;

    while (s1.empty() == false) {
        temp = s1.top();
        s1.pop();
        s2.push(temp);

        if (temp->left)
            s1.push(temp->left);
        if (temp->right)
            s1.push(temp->right);
    }

    while (s2.empty() == false) {
        temp = s2.top();
        s2.pop();
        cout<<temp->data<<"  ";
    }
}

void binary_tree::print2DUtil(node *root, int space) { 
    if (root == NULL) 
        return; 
    space += COUNT; 
    // Process right child first 
    print2DUtil(root->right, space); 
    // Print current node after space 
    // count 
    cout<<endl; 
    for (int i = COUNT; i < space; i++) 
        cout<<" "; 
    cout<<root->data<<"\n"; 
    // Process left child 
    print2DUtil(root->left, space); 
} 
  
// Wrapper over print2DUtil() 
void binary_tree::print2D(node *root) { 
    // Pass initial space count as 0 
    print2DUtil(root, 0); 
}

int main() {
    binary_tree tree;
    int con = 1;
    do {
        int ch;
        cout<<"| -------------- MENU -------------- |"<<endl;
        cout<<"1 - Create Tree"<<endl;
        cout<<"2 - Pre-Order Traversal Recursive"<<endl;
        cout<<"3 - In-Order Traversal Recursive"<<endl;
        cout<<"4 - Post-Order Traversal Recursive"<<endl;
        cout<<"5 - Pre-Order Traversal Iterative"<<endl;
        cout<<"6 - In-Order Traversal Iterative"<<endl;
        cout<<"7 - Post-Order Traversal Iterative"<<endl;
        cout<<"8 - Display"<<endl;
        cout<<"Enter Choice: ";
        cin>>ch;

        switch (ch) {
            case 1:
                int x;
                cout<<"Enter no. of Nodes: ";
                cin>>x;
                while(x) {
                    tree.addNode();
                    x--;
                }
                break;
            case 2:
                tree.preOrder(tree.root);
                break;
            case 3:
                tree.inOrder(tree.root);
                break;
            case 4:
                tree.postOrder(tree.root);
                break;
            case 5:
                tree.preOrderIterative(tree.root);
                break;
            case 6:
                tree.inOrderIterative(tree.root);
                break;
            case 7:
                tree.postOrderIterative(tree.root);
                break;
            case 8:
                tree.print2D(tree.root);
                break;
            default:
                cout << "DEFAULT CASE" << endl;
                break;
        }
        cout << "\nPress 1 Continue, Else Press Anything: ";
        cin >> con;
    } while (con == 1);
    return 0;
}