#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class SLL {
    Node* head;

public:
    SLL() {
        head = NULL;
    }

    void insertFront(int x) {
        Node* n = new Node;
        n->data = x;
        n->next = head;
        head = n;
    }

    void insertEnd(int x) {
        Node* n = new Node;
        n->data = x;
        n->next = NULL;

        if(head == NULL) {
            head = n;
            return;
        }

        Node* temp = head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = n;
    }

    void deleteNode(int x) {
        if(head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        while(temp != NULL && temp->data != x) {
            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL) {
            cout << "Not found\n";
            return;
        }

        if(temp == head)
            head = head->next;
        else
            prev->next = temp->next;

        delete temp;
        cout << "Deleted\n";
    }

    void search(int x) {
        Node* temp = head;
        int pos = 1;

        while(temp != NULL) {
            if(temp->data == x) {
                cout << "Found at position " << pos << endl;
                return;
            }

            temp = temp->next;
            pos++;
        }

        cout << "Not found\n";
    }

    void display() {
        Node* temp = head;

        if(head == NULL) {
            cout << "List is empty\n";
            return;
        }

        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void sortList() {
        if(head == NULL)
            return;

        for(Node* i = head; i->next != NULL; i = i->next) {
            for(Node* j = i->next; j != NULL; j = j->next) {
                if(i->data > j->data) {
                    int temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }
        }
    }
};