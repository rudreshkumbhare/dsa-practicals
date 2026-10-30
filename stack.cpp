#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int a[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(int x) {
        if(isFull()) {
            cout << "Stack Overflow\n";
            return;
        }

        a[++top] = x;
    }

    void pop() {
        if(isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }

        cout << "Removed: " << a[top--] << endl;
    }

    void peek() {
        if(isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Top element: " << a[top] << endl;
    }

    void display() {
        if(isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }

        for(int i = top; i >= 0; i--)
            cout << a[i] << " ";

        cout << endl;
    }

    void search(int x) {
        for(int i = top; i >= 0; i--) {
            if(a[i] == x) {
                cout << "Found at position " << i << endl;
                return;
            }
        }

        cout << "Not found\n";
    }

    void getMin() {
        if(isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }

        int min = a[0];

        for(int i = 1; i <= top; i++) {
            if(a[i] < min)
                min = a[i];
        }

        cout << "Minimum = " << min << endl;
    }
};