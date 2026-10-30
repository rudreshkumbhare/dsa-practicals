#include <iostream>
using namespace std;

# define MAX 10

class Graph {
    int graph[MAX][MAX], visited[MAX], V;
public:
    void input() {
        int E;
        cout << "Enter vertices and edges: ";
        cin >> V >> E;

        for(int i=0; i<V; i++) {
            for(int j=0; i<V; i++) {
                graph[i][j] = 0;
            }
        }

        cout << "Enter edges(u v):\n";
        for(int i=0; i<E; i++) {
            int u, v;
            cin >> u >> v;
            graph[u][v] = graph[v][u] = 1;
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
            
            for(int v = 0; v < V; v++) {
                if(graph[u][v] && !visited[v]) {
                    q[++rear] = v;
                    visited[v] = 1;
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