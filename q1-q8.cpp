#include <iostream>
using namespace std;

#define MAX 10
#define INF 99999

class Graph {
    int cost[MAX][MAX], V;

public:
    void input() {
        int E;
        cout << "Enter number of vertices and edges: ";
        cin >> V >> E;

        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                cost[i][j] = (i == j ? 0 : INF);
            }
        }

        cout << "Enter edges (u v weight): ";
        for(int i=0; i<E; i++) {
            int u, v, w;
            cin >> u >> v >> w;

            cost[u][v] = cost[v][u] = w;
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
                cout << parent[u] << " - " << u << " : " << cost[parent[u]][u] << endl;
                total += cost[parent[u]][u];
            }

            for(int v=0; v<V; v++) {
                if (!used[v] && cost[u][v] < key[v]) {
                    key[v] = cost[u][v];
                    parent[v] = u;
                }
            }
        }
        cout << "Total MST weight = " << total << endl;
    }

    void countEdges() {
        int degree[MAX] = {0};
        int edges = 0;

        for(int i=0; i<V; i++) {
            for(int j=i+1; j<V; j++) {
                if (cost[i][j]!=INF && cost[i][j]!=0) {
                    degree[i]++;
                    degree[j]++;
                    edges++;
                }
            }
        }
        cout << "Total edges = " << edges << endl;

        int maxDegree = degree[0];
        int vertex = 0;

        for(int i=1; i<V; i++) {
            if(degree[i] > maxDegree) {
                maxDegree = degree[i];
                vertex = i;
            }
        }
        cout << "Vertex with max edges = " << vertex << endl;
        cout << "No. of edges = " << maxDegree << endl;
    }

    void cheapestEdge() {
        for(int i=0; i<V; i++) {
            int min = INF;
            for(int j=0; j<V; j++) {
                if(i!=j && cost[i][j] < min) {
                    min = cost[i][j];
                }
            }

            if(min == INF) cout << "Vertex " << i << ": No edge" << endl;
            else cout << "Vertex " << i << ": " << min << endl;
        }
    }
};

int main() {
    Graph g;
    g.input();

    g.countEdges();
    g.cheapestEdge();
    g.prim();
    return 0;
}