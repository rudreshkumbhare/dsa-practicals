#include <iostream>
using namespace std;

# define MAX 10

class Node {
public:
    int to;
    Node* next;
};

class Graph {
    Node* head[MAX];
    int visited[MAX], V;

    void addOne(int u, int v) {
        Node* n = new Node;
        n->to = v;
        n->next = head[u];
        head[u] = n;
    }

    bool isFriend(int u, int v) {
        for(Node* p = head[u]; p != NULL; p = p->next) {
            if(p->to == v)
                return true;
        }
        return false;
    }

public:
    void input() {
        int E;
        cout << "Enter number of vertices and edges: ";
        cin >> V >> E;

        cout << "Enter edges (u v):\n";
        for(int i=0; i<E; i++) {
            int u, v;
            cin >> u >> v;
            addOne(u, v);
            addOne(v, u);
        }
    }

    void bfs(int start) {
        int q[MAX];
        int rear = -1, front = 0;

        for(int i=0; i<V; i++) {
            visited[i] = 0;
        }
        q[++rear] = start;
        visited[start] = 1;

        while(front <= rear) {
            int u = q[front++];
            cout << u << " ";

            for(Node* p=head[u]; p!=NULL; p=p->next) {
                if(!visited[p->to]) {
                    q[++rear] = p->to;
                    visited[p->to] = 1;
                }
            }
        }
        cout << endl;
    }

    void listFriends() {
        int maxFriends = -1, maxUser = 0;

        for(int i=0; i<V; i++) {
            int count = 0;
            cout << "Friends of: " << i << ": ";

            for(Node* p=head[i]; p!=NULL; p=p->next) {
                cout << p->to << " ";
                count++;
            }
            cout << endl;

            if(count > maxFriends) {
                maxFriends = count;
                maxUser = i;
            }
        }
        cout << "User with most friends: " << maxUser << endl;
        cout << "No. of friends: " << maxFriends << endl;
    }

    void bfsLevels(int start) {
        int level[MAX], q[MAX];
        int front = 0, rear = -1;

        for(int i=0; i<V; i++) {
            level[i] = -1;
        }
        level[start] = 0;
        q[++rear] = start;

        while(front <= rear) {
            int u = q[front++];

            for(Node* p=head[u]; p!=NULL; p=p->next) {
                if(level[p->to] = -1) {
                    level[p->to] = level[u]+1;
                    q[++rear] = p->to;
                }
            }
        }

        for(int i = 0; i < V; i++) {
            if(level[i] == -1) cout << i << ": unreachable" << endl;
            else cout << i << ": level " << level[i] << endl;
        }
    }
};