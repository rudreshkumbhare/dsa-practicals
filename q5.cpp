#include <iostream>
using namespace std;

#define MAXV 10
#define MAXE 45

struct Edge {
    int u, v, w;
};

class Graph {
    Edge edges[MAXE];
    int parent[MAXV], rnk[MAXV];
    int V, E;

public:
    void input() {
        cout << "Enter number of villages and roads: ";
        cin >> V >> E;

        cout << "Enter roads (u v cost):\n";

        for(int i = 0; i < E; i++) {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
        }
    }

    void sortEdges() {
        for(int i = 0; i < E - 1; i++) {
            for(int j = 0; j < E - i - 1; j++) {
                // Tie-breaking: smaller u, then smaller v
                if(edges[j].w > edges[j+1].w ||
                  (edges[j].w == edges[j+1].w &&
                   edges[j].u > edges[j+1].u) ||
                  (edges[j].w == edges[j+1].w &&
                   edges[j].u == edges[j+1].u &&
                   edges[j].v > edges[j+1].v)) {

                    Edge temp = edges[j];
                    edges[j] = edges[j+1];
                    edges[j+1] = temp;
                }
            }
        }

        cout << "\nSorted roads:\n";
        for(int i = 0; i < E; i++) {
            cout << edges[i].u << " - "
                 << edges[i].v << " : "
                 << edges[i].w << endl;
        }
    }

    void makeSet() {
        for(int i = 0; i < V; i++) {
            parent[i] = i;
            rnk[i] = 0;
        }
    }

    int findSet(int x) {
        if(parent[x] != x)
            parent[x] = findSet(parent[x]);

        return parent[x];
    }

    void unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);

        if(a == b)
            return;

        if(rnk[a] < rnk[b]) {
            parent[a] = b;
        }
        else if(rnk[a] > rnk[b]) {
            parent[b] = a;
        }
        else {
            parent[b] = a;
            rnk[a]++;
        }
    }

    void showDSU() {
        makeSet();

        cout << "\nDSU demonstration:\n";

        int merges = 0;

        for(int i = 0; i < E && merges < 3; i++) {
            int a = findSet(edges[i].u);
            int b = findSet(edges[i].v);

            if(a != b) {
                unionSet(a, b);
                merges++;

                cout << "After merging "
                     << edges[i].u << " and "
                     << edges[i].v << ": ";

                for(int j = 0; j < V; j++)
                    cout << parent[j] << " ";

                cout << endl;
            }
        }
    }

    void kruskal() {
        makeSet();

        int total = 0;
        int selected = 0;
        int rejected = 0;

        cout << "\nSelected roads:\n";

        for(int i = 0; i < E; i++) {
            int u = edges[i].u;
            int v = edges[i].v;

            if(findSet(u) != findSet(v)) {
                unionSet(u, v);

                cout << u << " - " << v
                     << " : " << edges[i].w << endl;

                total += edges[i].w;
                selected++;
            }
            else {
                rejected++;
            }
        }

        cout << "\nTotal repair cost = " << total << endl;
        cout << "Rejected roads = " << rejected << endl;

        if(selected != V - 1)
            cout << "Graph is disconnected. MST not possible.\n";
    }
};

int main() {
    Graph g;

    g.input();
    g.sortEdges();
    g.showDSU();
    g.kruskal();

    return 0;
}
