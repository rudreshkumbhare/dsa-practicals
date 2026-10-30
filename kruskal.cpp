
#include <iostream>
using namespace std;

#define MAXV 10
#define MAXE 45

struct Edge {
    int u, v, w;
};

int parent[MAXV], rnk[MAXV];

int findSet(int x) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void unite(int a, int b) {
    a = findSet(a);
    b = findSet(b);

    if (a == b) return;

    if (rnk[a] < rnk[b])
        parent[a] = b;
    else if (rnk[a] > rnk[b])
        parent[b] = a;
    else {
        parent[b] = a;
        rnk[a]++;
    }
}

// Print the current Disjoint Set structure
void displayDSU(int V) {
    for(int i = 0; i < V; i++) {
        cout << parent[i] << " ";
    }
    cout << endl;
}

// Sort by weight, then smaller endpoint, then larger endpoint

bool shouldSwap(Edge a, Edge b) {
    if (a.w > b.w) return a.w > b.w;

    int a1 = a.u, a2 = a.v;
    int b1 = b.u, b2 = b.v;

    if (a1 > a2) {
        int t = a1;
        a1 = a2;
        a2 = t;
    }
    if (b1 > b2) {
        int t = b1;
        b1 = b2;
        b2 = t;
    }
    if (a1 != b1) return a1 > b1;
    return a2 > b2;
}

int main() {
    int V, E;
    Edge edges[MAXE];

    cout << "Enter number of villages and roads: ";
    cin >> V >> E;

    cout << "Enter roads (u v cost):\n";

    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // bubble
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (shouldSwap(edges[j], edges[j + 1])) {
                Edge t = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = t;
            }
        }
    }

    cout << "\nRoads sorted by cost:\n";
    cout << "Road\tCost\n";

    for (int i = 0; i < E; i++)
        cout << edges[i].u << " - " << edges[i].v
             << "\t" << edges[i].w << endl;

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rnk[i] = 0;
    }

    cout << "\nInitial DSU state:\n";
    displayDSU(V);

    int total = 0;
    int chosen = 0;
    int rejected = 0;

    cout << "\nRoads selected by Kruskal's algorithm:\n";

    for(int i=0; i<V; i++) {
        int a = findSet(edges[i].u);
        int b = findSet(edges[i].v);

        if (a != b && chosen < V-1) {
            unite(a, b);
            cout << edges[i].u << " - " << edges[i].v << " : " << edges[i].w << endl;
            total += edges[i].w;
            chosen++;
        } else if (a == b) {
            rejected++;
            cout << "Rejected road: " << edges[i].u << " - " << edges[i].v << " (formed a loop)\n";
        }
    }

    cout << "\nTotal repair cost = " << total << endl;
    cout << "Roads selected = " << chosen << endl;
    cout << "Roads rejected due to loops = " << rejected << endl;

    if (chosen != V - 1) cout << "All villages cannot be connected.\n";
    else cout << "All villages are connected.\n";

    return 0;
}
