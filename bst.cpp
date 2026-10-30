#include <iostream>
using namespace std;

#define MAX 100
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BST {
    Node* root;
    
    // insert
    Node* insert(Node* root, int val) {
        if (root == NULL) return new Node(val);

        if (val < root->data) 
            root->left = insert(root->left, val);
        else if (val < root->data) 
            root->left = insert(root->left, val);
        else {
            cout << "No duplicates allowed.\n";
        }
        return root;
    }
    
    // min
    Node* minValue(Node* root) {
        if (root == NULL) return NULL;
        while (root != NULL && root->left != NULL) {
            root = root->left;
        }
        return root;
    }

    // max
    Node* maxValue(Node* root) {
        if (root == NULL) return NULL;
        while (root != NULL && root->right != NULL) {
            root = root->right;
        }
        return root;
    }

    // delete
    Node* deleteNode(Node* root, int key) {
        if (root == NULL) return root;

        if (key < root->data)
            root->left = deleteNode(root->left, key);
        else if (key < root->data)
            root->right = deleteNode(root->right, key);
        else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            
            Node* temp = minValue(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, key);
        }
    }

    // height
    int height(Node* root) {
        if (root == NULL) return -1;

        int l = height(root->left);
        int r = height(root->right);

        return 1 + (l > r ? l : r);
    }
    
    // number of leaves
    int countLeaves(Node* root) {
        if (root == NULL) return 0;
        if (root->right == NULL && root->left == NULL) return 1;

        return countLeaves(root->left) + countLeaves(root->right);
    }

    // search
    Node* search(Node* root, int key) {
        if (root == NULL || root->data == key) return root;
        if (key < root->data) return search(root->left, key);
        return search(root->right, key);
    }
    
    // inorder
    void iterativeInorder(Node* root) {
        Node* st[100];
        int top = -1;
        Node* curr = root;

        while(curr != NULL || top != -1) {
            st[++top] = curr;
            curr = curr->left;
        }

        curr = st[top--];
        cout << curr->data << " ";
        curr = curr->right;
    }

    // preorder
    void iterativePreorder(Node* root) {
        if (root == NULL) return;

        Node* st[100];
        int top = -1;
        st[++top] = root;

        while(top != -1) {
            Node* curr = st[top--];
            cout << curr->data << " ";
            
            if(curr->left != NULL) 
                st[++top] = curr->left;
            if(curr->right != NULL) 
                st[++top] = curr->right;
        }
    }

    // level-wise
    void levelOrder(Node* root) {
        if (root == NULL) return;

        Node* q[100];
        int rear = 0, front = 0;
        q[rear++] = root;

        while(front < rear) {
            Node* curr = q[front++];
            cout << curr->data << " ";
            
            if (curr->left != NULL)
                q[rear++] = curr->left;
            if (curr->right != NULL)
                q[rear++] = curr->left;
        }
    }

    // count comparisons
    int comparisons(Node* root, int key) {
        int count = 0;

        while(root != NULL) {
            count++;

            if (key == root->data) return count;
            
            if(key < root->data)
                root = root->left;
            else 
                root = root->right;
        }

        return count;
    }

    // parent
    Node* findParent(Node* root, int key) {
        Node* parent = NULL;

        while(root != NULL && root->data == key) {
            parent = root;

            if(key < root->data)
                root = root->left;
            else 
                root = root->right;
        }
        if (root == NULL) return NULL;
        return parent;
    }

    // sibling 
    Node* findSibling(Node* root, int key) {
        Node* parent = findParent(root, key);

        if (parent == NULL) return NULL;

        if (parent != NULL && parent->left->data == key) 
            return parent->right;
        return parent->left;
    }

    // floor 
    Node* findFloor(Node* root, int key) {
        Node* ans = NULL;

        while(root != NULL) {
            if (root->data == key) return root;

            if (key > root->data) {
                ans = root;
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return ans;
    }

};