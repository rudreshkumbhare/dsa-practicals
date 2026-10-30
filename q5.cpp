#include <iostream>
using namespace std;

#define MAXV 10
#define MAXE 45

struct Edge {
    int u, v, w;
};

int parent[MAXV], rnk[MAXV];

int findSet(int x) {
    while(parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
} 

void unite(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a == b) return;

    if (rnk[a] < rnk[b]) parent[a] = b;
    else if (rnk[a] > rnk[b]) parent[b] = a; 
    else {
        parent[b] = a;
        rnk[a]++;
    }
}

int main() {
    Edge edges[MAXE];
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    // bubble
    for(int i = 0; i < E; i++) {
        for(int j = 0; j < E-i-1; j++) {
            if(edges[j].w > edges[j+1].w) {
                Edge t = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = t;
            }
        }
    }

    for(int i = 0; i < V; i++) {
        parent[i] = i;
        rnk[i] = 0;
    }

    int total = 0, chosen = 0;
    for(int i = 0; i < E && chosen != V-1; i++) {
        int a = findSet(edges[i].u);
        int b = findSet(edges[i].v);
        if (a != b) {
            unite(a, b);
            cout << edges[i].u << " - " << edges[i].v << " : " << edges[i].w << endl;
            total += edges[i].w;
            chosen++;
        }
    }

    if (chosen != V-1) {
        cout << "Cant find MST." << endl;
    } else {
        cout << "Total cost MST = " << total << endl;
    }
}