#include <stdlib.h>
#include <iostream>
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

class BST {
    public:
        node *root;
        node *enter_new_node() {
            int x;
            cout<<"Enter Data: ";
            cin>>x;
            node *temp = new node(x);
            return temp;
        }
        node *delete_node(node *head, int data) {
            if (head == NULL)
                return head;
            if (data < head->data)
                head->left = delete_node(head->left, data);
            else if (data > head->data)
                head->right = delete_node(head->right, data);
            else {
                if (head->left == NULL && head->right == NULL) {
                    delete head;
                    head = NULL;
                }
                else if (head->left == NULL) {
                    node *temp = head;
                    head = head->right;
                    delete temp;
                }
                else if (head->right == NULL) {
                    node *temp = head;
                    head = head->left;
                    delete temp;
                }
                else {
                    node *temp = find_min_node(head->right);
                    head->data = temp->data;
                    head->right = delete_node(head->right, temp->data);
                }
            }
            return head;
        }
        node *find_min_node(node *t) {
            if (t->left == NULL)
                return t;
            return find_min_node(t->left);
        }
        struct node *search(struct node *root, int data) {
            if (root == NULL || root->data == data)
                return root;
            if (root->data < data)
                return search(root->right, data);
            return search(root->left, data);
        }

        BST() {
            root = NULL;
        }

        void addNode();
        void preOrder(node *t);
        void inOrder(node *t);
        void postOrder(node *t);
        void print2DUtil(node *root, int space);
        void print2D(node *root);
};

void BST::addNode() {
    node *new_node = enter_new_node();
    if (root == NULL)
        root = new_node;
    else {
        node *temp = root;
        while (true) {
            if (new_node->data <= temp->data) {
                if (temp->left == NULL) {
                    temp->left = new_node;
                    break;
                }
                temp = temp->left;
            }
            else if (new_node->data > temp->data) {
                if (temp->right == NULL) {
                    temp->right = new_node;
                    break;
                }
                temp = temp->right;
            }
        }
    }
}

void BST::preOrder(node *t) {
    if (root == NULL) {
        cout<<"! - TREE IS EMPTY - !"<<endl;
        return;
    }
    else if (t == NULL)
        return;
    cout<<t->data<<"  ";
    preOrder(t->left);
    preOrder(t->right);
}

void BST::inOrder(node *t) {
    if (root == NULL) {
        cout<<"! - TREE IS EMPTY - !"<<endl;
        return;
    }
    else if (t == NULL)
        return;
    inOrder(t->left);
    cout<<t->data<<"  ";
    inOrder(t->right);
}

void BST::postOrder(node *t) {
    if (root == NULL) {
        cout<<"! - TREE IS EMPTY - !"<<endl;
        return;
    }
    else if (t == NULL)
        return;
    postOrder(t->left);
    postOrder(t->right);
    cout<<t->data<<"  ";
}

void BST::print2DUtil(node *root, int space) { 
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
void BST::print2D(node *root) { 
    // Pass initial space count as 0 
    print2DUtil(root, 0); 
}

int main() {
    BST tree;
    int data;
    int con = 0;
    do {
        int ch;
        cout<<endl<<"| --- MENU --- |"<<endl;
        cout<<"1 - Create Tree"<<endl;
        cout<<"2 - Search Node"<<endl;
        cout<<"3 - Delete Node"<<endl;
        cout<<"4 - TERMINATE PROGRAM"<<endl; 
        cout<<"Enter Choice: ";
        cin >> ch;
        
        switch (ch) {
            case 1: {
                int x;
                cout<<"Enter no. of Nodes: ";
                cin>>x;
                while(x) {
                    tree.addNode();
                    x--;
                }
                break;
            }
            case 2: {
                cout<<"Enter Node: ";
                cin >> data;
                node *search = tree.search(tree.root, data);
                if (search != NULL)
                    cout<<"Node with data "<<data<<" exists"<<endl;
                else
                    cout<<"! - NODE DOES NOT EXISTS - !"<<endl;
                break;
            }
            case 3: {
                cout<<"Enter Node: ";
                cin >> data;
                node *search = tree.search(tree.root, data);
                if (search != NULL) {
                    node *del = tree.delete_node(tree.root, data);
                    cout<<"Node with data "<<data<<" deleted"<<endl;
                    }
                else
                    cout<<"! - NODE DOES NOT EXISTS - !"<<endl;
                break;
            }
            case 4: {
                con = 1;
                break;
            }
            default: {
                cout<<endl<<"! ---------- QUICK REPORT ---------- !"<<endl;
                tree.print2D(tree.root);
                cout<<endl<<"PRE-ORDER RECURSIVE:\t";
                tree.preOrder(tree.root);
                cout<<endl<<"IN-ORDER RECURSIVE:\t";
                tree.inOrder(tree.root);
                cout<<endl<<"POST-ORDER RECURSIVE:\t";
                tree.postOrder(tree.root);
                break;
            }
        }
    } while (con == 0);
    return 0;
}