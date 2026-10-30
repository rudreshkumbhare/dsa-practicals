#include <iostream>
using namespace std;

# define MAX 10
# define INF 99999
class Node {
public:
    int to, w;
    Node* next;
};

class Graph {
    Node* head[MAX];
    int V;

    void addOne(int u, int v, int w) {
        Node* n = new Node;
        n->to = v;
        n->w = w;
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
        cout << "Enter number of vertices and edges: ";
        cin >> V >> E;

        cout << "Enter edges(u v weight):\n";
        for(int i=0; i<E; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            addOne(u, v, w);
            addOne(v, u, w);
        }
    }

    void prim() {
        int key[MAX], parent[MAX], used[MAX];

        for(int i = 0; i < V; i++) {
            key[i] = INF;
            parent[i] = -1;
            used[i] = 0;
        }
        key[0] = 0;
        int total = 0;

        for(int count = 0; count < V; count++) {
            int u = -1, min = INF;
            for(int i = 0; i < V; i++) {
                if(!used[i] && key[i] < min) {
                    min = key[i];
                    u = i;
                }
            }
            if (u == -1) return;
            used[u] = 1;

            if (parent[u] != -1) {
                cout << parent[u] << " - " << u << " : " << key[u] << endl;
                total += key[u];
            }

            for(Node* p = head[u]; p != NULL; p = p->next) {
                if(!used[p->to] && p->w < key[p->to]) {
                    key[p->to] = p->w;
                    parent[p->to] = u;
                }
            }
        }
        cout << "Total MST weight = " << total << endl;
    }
};

int main() {
    Graph g;
    g.input();
    g.prim();
    return 0;
}