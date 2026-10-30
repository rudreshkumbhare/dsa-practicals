
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

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                graph[i][j] = 0;
            }
        }

        cout << "Enter edges (u v):\n";
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;

            graph[u][v] = graph[v][u] = 1;
        }
    }

    void countTunnels() {
        int count[MAX];
        int maxCount = -1, chamber = 0;

        cout << "\nTunnels connected to each chamber:\n";

        for (int i = 0; i < V; i++) {
            count[i] = 0;
            for (int j = 0; j < V; j++) {
                if (graph[i][j] == 1) count[i]++;
            }
            cout << "Chamber " << i << " : " << count[i] << " tunnels\n";

            if (count[i] > maxCount) {
                maxCount = count[i];
                chamber = i;
            }
        }

        cout << "Chamber with most tunnels: " << chamber << endl;
        cout << "Number of tunnels: " << maxCount << endl;
    }

    void DFS(int u) {
        visited[u] = 1;
        cout << u << " ";

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v]) DFS(v);
        }
    }

    void run(int start) {
        for (int i = 0; i < V; i++) {
            visited[i] = 0;
        }

        cout << "\nDFS traversal: ";
        DFS(start);
        cout << endl;

        cout << "Rule: Visit the lowest-numbered unvisited adjacent chamber first.\n";
    }
};

int main() {
    Graph g;
    g.input();

    int start;

    cout << "Enter entrance chamber: ";
    cin >> start;

    g.countTunnels();
    g.run(start);

    return 0;
}
