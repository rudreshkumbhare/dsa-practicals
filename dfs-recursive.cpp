#include <iostream>
using namespace std;

#define MAX 10

class Graph {
    int graph[MAX][MAX], visited[MAX], V;

public:
    void input() {
        int E;
        cout << "Enter number of vertices and edges: ";
        cin >> V >> E;

        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                graph[i][j] = 0;
            }
        }

        cout << "Enter edges (u v): ";
        for(int i=0; i<E; i++) {
            int u, v;
            cin >> u >> v;
            graph[u][v] = graph[u][v] = 1;
        }
    }

    void dfs(int u) {
        visited[u] = 1;
        cout << u << " ";

        for(int v=0; v<V; v++) {
            if(graph[u][v] && !visited) {
                dfs(v);
            }
        }
    }

    void run(int start) {
        for(int i=0; i<V; i++) {
            visited[i] = 0;
        }
        dfs(start);
        cout << endl;
    }
};

int main() {
    Graph g;
    g.input();

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;
    g.run(start);
    return 0;
}