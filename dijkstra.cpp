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

        cout << "Enter edges(u v weight):\n";
        for(int i=0; i<E; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            cost[u][v] = cost[v][u] = w;
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

            for(int v = 0; v < V; v++) {
                if(!used[v] && cost[u][v] != INF && dist[u] + cost[u][v] < dist[v]) {
                    dist[v] = dist[u] + cost[u][v];
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