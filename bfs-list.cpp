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

public:
    Graph() {
        for(int i = 0; i < MAX; i++)
            head[i] = NULL; 
    }

    void input() {
        int E;
        cout << "Enter vertices and edges: ";
        cin >> V >> E;

        cout << "Enter edges(u v):\n";
        for(int i=0; i<E; i++) {
            int u, v;
            cin >> u >> v;
            addOne(u, v);
            addOne(v, u);
        }
    }

    void bfs(int start) {
        int q[MAX], front = 0, rear = -1;

        for(int i = 0; i < V; i++) {
            visited[i] = 0;
        }
        q[++rear] = start;
        visited[start] = 1;

        while(front <= rear) {
            int u = q[front++];
            cout << u << " ";
            
            for(Node* p = head[u]; p != NULL; p = p->next) {
                if(!visited[p->to]) {
                    q[++rear] = p->to;
                    visited[p->to] = 1;
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g;
    g.input();
    int s;
    cout << "Enter start: ";
    cin >> s;
    g.bfs(s);
}   