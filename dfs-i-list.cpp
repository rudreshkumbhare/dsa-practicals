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
        for(int i=0; i<MAX; i++) {
            head[i] = NULL;
        }
    }

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

    void DFSiterative(int start) {
        int st[MAX * MAX]; 
        int top = -1;

        for (int i=0; i<V; i++) {
            visited[i] = 0;
        }

        st[++top] = start;

        while(top != -1) {
            int u = st[top--];
            if (visited[u] == 1) continue;

            visited[u] = 1;
            cout << u << " ";
            for(Node* p = head[u]; p!=NULL; p=p->next) {
                if(!visited[p->to]) {
                    st[++top] = p->to;
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g;
    g.input();

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;
    g.DFSiterative(start);

    return 0;
}