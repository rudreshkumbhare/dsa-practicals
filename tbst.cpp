#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    int lth, rth;

    Node() {
        left = right = NULL;
        lth = rth = 1;
    }
};

class TBST {
public:
    Node *head, *root;

    TBST() {
        head = new Node();
        head->data = 2147483647;

        head->left = NULL;
        head->right = head;
        head->lth = 0;
        head->rth = 1;

        root = NULL;
    }

    // search
    Node* search(int key) {
        Node* curr = root;

        while (curr != NULL && curr != head) {
            if (curr->data == key) return curr;

            if (key < curr->data) {
                if (curr->lth == 0) curr = curr->left;
                else break;
            }
            else {
                if (curr->rth == 0) curr = curr->right;
                else break;
            }
        }
        return NULL;
    }

    // insert
    void insert(int val) {
        Node* n = new Node();
        n->data = val;

        //empty
        if (root == NULL) {
            n->left = head;
            n->right = head;

            root = n;
            head->left = root;
            return;
        }

        Node* curr = root;
        while (true) {
            if (val == root->data) {
                delete n;
                return;
            }

            if (val < root->data) {
                if (curr->lth == 0) {
                    curr = curr->left;
                } else {
                    n->left = curr->left;
                    n->right = curr;

                    curr->left = n;
                    curr->lth = 0;
                }
            } else {
                if (curr->rth == 0) {
                    curr = curr->right;
                } else {
                    n->right = curr->right;
                    n->left = curr;

                    curr->right = n;
                    curr->rth = 0;
                }
            }
        }
    }

    Node* inorderSuccessor(Node* curr) {
        if (curr->rth == 1) return curr->right;
        curr = curr->right;

        while (curr->lth == 0)
            curr = curr->left;

        return curr;
    }

    void inorder() {
        if (root == NULL) {
            cout << "Tree is empty\n";
            return;
        }

        Node* curr = root;
        while (curr->lth == 0) {
            curr = curr->left;
        }

        while (curr != head) {
            cout << curr->data << endl;

            curr = inorderSuccessor(curr);
        }
    }

    void preorder() {
        Node* curr = root;

        while (curr != NULL && curr != head) {
            cout << curr->data << " ";

            if (curr->lth == 0) {
                curr = curr->left;
            }
            else if (curr->rth == 0) {
                curr = curr->right;
            }
            else {
                while (curr != head && curr->rth == 1)
                    curr = curr->right;

                if (curr != head)
                    curr = curr->right;
                else
                    curr = NULL;
            }
        }
    }

    int countThreads() {
        if (root == NULL) return 0;

        int count = 0;
        Node* curr = root;

        while (curr->lth == 0)
            curr = curr->left;

        while (curr != head) {
            if (curr->lth == 1) count++;
            if (curr->rth == 1) count++;

            curr = inorderSuccessor(curr);
        }

        return count;
    }
};

int main() {
    TBST t;
    int choice, value;

    do {
        cout << "\n1.Insert 2.Search 3.Inorder 4.Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key and value: ";
            cin >> value;
            t.insert(value);
            break;
        case 2: {
            cout << "Enter key: ";
            cin >> value;

            Node* result = t.search(value);

            if (result != NULL)
                cout << result->data << endl;
            else
                cout << "Not found\n";
            break;
        }
        case 3:
            t.inorder();
            break;
        }
    } while (choice != 4);

    return 0;
}
