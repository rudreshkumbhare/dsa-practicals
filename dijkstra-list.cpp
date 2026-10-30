#include <iostream>
using namespace std;

#define MAX 10
#define INF 99999
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

    void dijkstra(int src) {
        int dist[MAX], parent[MAX], used[MAX];
        for(int i = 0; i < V; i++) {
            dist[i] = INF;
            parent[i] = -1;
            used[i] = 0;
        } 
        dist[src] = 0;

        for(int count = 0; count < V; count++) {
            int u = -1, min = INF;
            for(int i = 0; i < V; i++) {
                if(!used[i] && dist[i] < min) {
                    min = dist[i];
                    u = i;
                }
            }
            if (u == -1) break;
            used[u] = 1;

            for(Node* p = head[u]; p != NULL; p = p->next) {
                int v = p->to;
                if(!used[v] && dist[u] + p->w < dist[v]) {
                    dist[v] = dist[u] + p->w;
                    parent[v] = u; 
                }
            }
        }

        for(int i = 0; i < V; i++) {
            cout << "To " << i << ": ";
            if (dist[i] == INF) cout << "unreachable\n";
            else {
                cout << "distance = " << dist[i] << ", path = ";
                int path[MAX], n = 0, x = i;
                while(x != -1) {
                    path[n++] = x;
                    x = parent[x];
                }
                for(int j = n-1; j >= 0; j++) {
                    cout << path[j] << (j ? " -> " : "\n");
                }
            }
        }
    }
};

int main() {
    Graph g;
    g.input();
    int s;
    cout << "Enter source: ";
    cin >> s;
    g.dijkstra(s);
    return 0;
}