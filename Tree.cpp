#include <iostream>
#include <stack>
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
        binary_tree() {
            root = NULL;
        }

        void create();
        void addNode();
        void preOrder(node *t);
        void inOrder(node *t);
        void postOrder(node *t);
        void preOrderNonRecursive(node *head);
        void inOrderNonRecursive(node *head);
        void postOrderNonRecursive(node *head);

        node *enterNewNode() {
            int x;
            cout << "\nEnter Data: ";
            cin >> x;
            node *temp = new node(x);
            return temp;
        }
};

void binary_tree::create() {
    int ch;
    while (true) {
        addNode();
        cout << "ADD ANOTHER NODE? 1 - YES | 0 - NO: ";
        cin >> ch;
        if (ch != 1)
            break;
    }
}

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
            if (tolower(ch[0]) == 'l') {
                if (temp->left == NULL) {
                    temp->left = newNode;
                    break;
                }
                temp = temp->left;
            }
            else if (tolower(ch[0]) == 'r') {
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
    cout << t->data << " ";
    preOrder(t->left);
    preOrder(t->right);
}

void binary_tree::inOrder(node *t) {
    if (t == NULL)
        return;
    preOrder(t->left);
    cout << t->data << " ";
    preOrder(t->right);
}

void binary_tree::postOrder(node *t) {
    if (t == NULL)
        return;
    preOrder(t->left);
    preOrder(t->right);
    cout << t->data << " ";
}

void binary_tree::preOrderNonRecursive(node *head) {
    if (head == NULL)
        return;
    stack<node *> s;
    s.push(head);
    while (s.empty() == false) {
        node *temp = s.top();
        cout << temp->data << " ";
        s.pop();
        if (temp->right)
            s.push(temp->right);
        else if (temp->left)
            s.push(temp->left);
    }
}

void binary_tree::inOrderNonRecursive(node *head) {
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
        cout << temp->data << " ";
        temp = temp->right;
    }
}

void binary_tree::postOrderNonRecursive(node *head) {
    stack<node *> s1;
    stack<node *> s2;

    s1.push(head);
    node *temp;
    while (s1.empty() == false) {
        temp = s1.top();
        s1.pop();
        s2.push(temp);

        if (temp->left)
            s1.push(temp->left);
        else if (temp->right)
            s1.push(temp->right);
    }

    while (s1.empty() == false) {
        node *temp = s1.top();
        s2.pop();
        cout << temp->data << " ";
    }
}

int main() {
    binary_tree tree;
    int con = 1;
    do {
        int ch;
        cout << "\n| -------------- MENU -------------- |" << endl;
        cout << "1 - Create Tree" << endl;
        cout << "2 - Pre-Order Traversal Recursive" << endl;
        cout << "3 - In-Order Traversal Recursive" << endl;
        cout << "4 - Post-Order Traversal Recursive" << endl;
        cout << "5 - Pre-Order Traversal Non-Recursive" << endl;
        cout << "6 - In-Order Traversal Non-Recursive" << endl;
        cout << "7 - Post-Order Traversal Non-Recursive" << endl;
        cout << "Enter Choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                tree.create();
                break;
            case 2:
                cout << "\nPRE ORDER TRAVERSAL: ";
                tree.preOrder(tree.root);
                break;
            case 3:
                cout << "\nIN ORDER TRAVERSAL: ";
                tree.inOrder(tree.root);
                break;
            case 4:
                cout << "\nPOST ORDER TRAVERSAL: ";
                tree.postOrder(tree.root);
                break;
            case 5:
                cout << "\nPRE ORDER TRAVERSAL (NON-RECURSIVE): ";
                tree.preOrderNonRecursive(tree.root);
                break;
            case 6:
                cout << "\nIN ORDER TRAVERSAL (NON-RECURSIVE): ";
                tree.inOrderNonRecursive(tree.root);
                break;
            case 7:
                cout << "\nPOST ORDER TRAVERSAL (NON-RECURSIVE): ";
                tree.postOrderNonRecursive(tree.root);
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