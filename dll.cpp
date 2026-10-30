#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *prev, *next;
};

class DLL {
    Node *head, *tail;

public:
    DLL() {
        head = tail = NULL;
    }

    void insertFront(int x) {
        Node* n = new Node;
        n->data = x;
        n->prev = NULL;
        n->next = head;

        if(head != NULL)
            head->prev = n;
        else
            tail = n;

        head = n;
    }

    void insertEnd(int x) {
        Node* n = new Node;
        n->data = x;
        n->next = NULL;
        n->prev = tail;

        if(tail != NULL)
            tail->next = n;
        else
            head = n;

        tail = n;
    }

    void insertPosition(int x, int pos) {
        if(pos <= 1) {
            insertFront(x);
            return;
        }

        Node* temp = head;

        for(int i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;

        if(temp == NULL || temp == tail) {
            insertEnd(x);
            return;
        }

        Node* n = new Node;
        n->data = x;

        n->next = temp->next;
        n->prev = temp;

        temp->next->prev = n;
        temp->next = n;
    }

    void deleteNode(int x) {
        Node* temp = head;

        while(temp != NULL && temp->data != x)
            temp = temp->next;

        if(temp == NULL) {
            cout << "Not found\n";
            return;
        }

        if(temp == head)
            head = temp->next;
        else
            temp->prev->next = temp->next;

        if(temp == tail)
            tail = temp->prev;
        else
            temp->next->prev = temp->prev;

        delete temp;
        cout << "Deleted\n";
    }

    void search(int x) {
        Node* temp = head;

        while(temp != NULL) {
            if(temp->data == x) {
                cout << "Found\n";
                return;
            }

            temp = temp->next;
        }

        cout << "Not found\n";
    }

    void displayForward() {
        Node* temp = head;

        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void displayBackward() {
        Node* temp = tail;

        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->prev;
        }

        cout << endl;
    }
};