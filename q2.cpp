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
        int dist[MAX], visited[MAX], parent[MAX];
        
        for(int i=0; i<V; i++) {
            dist[i] = INF;
            visited[i] = 0;
            parent[i] = -1;
        }
        dist[src] = 0;

        for(int count=0; count<V; count++) {
            int u = -1, min = INF;
            for(int i=0; i<V; i++) {
                if(!visited[i] && dist[i] < min) {
                    min = dist[i];
                    u = i;
                }
            }
            if (u == -1) break;
            visited[u] = 1;

            for(int v=0; v<V; v++) {
                if(!visited[v] && cost[u][v] == 1 && dist[u]+cost[u][v] < dist[v]) {
                    dist[v] = dist[u] + cost[u][v];
                    parent[v] = u;
                }
            }
        }

        for(int i=0; i<V; i++) {
            cout << "To: " << i << ": ";
            if (i == INF) cout << "unreachable.\n";
            else {
                cout << "distance = " << dist[i] << ", path = ";
                int path[MAX], n = 0, x = i;
                while(x!=-1) {
                    path[n++] = x;
                    x = parent[x];
                }
                for(int j=n-1; j>=0; j--) {
                    cout << path[j] << (j ? " -> " : "\n");
                }
            } 
        }
    }

    void countEdges() {
        for(int i=0; i<V; i++) {
            int count = 0;

            for(int j=0; j<V; j++) {
                if (i!=j && cost[i][j]!=INF) {
                    count++;
                }
            }
            cout << "Island " << i << ": "
                << count << " ferry services\n";
        }
    }
};