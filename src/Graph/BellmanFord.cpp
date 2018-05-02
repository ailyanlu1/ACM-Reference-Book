// O(V * E)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

struct Edge {
    int from, to, cost;
};

const int MAXE = 1e3;
const int MAXV = 1e3;

Edge es[MAXE];
int d[MAXV];
int V, E;

void BellmanFord(int s) {
    fill_n(d, V+5, INF);
    d[s] = 0;
    while (true) {
        bool f = false;
        for (int i = 0; i < E; i++) {
            Edge e = es[i];
            if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                f = true;
            }
        }
        if (!f) break;
    }
}

bool negative_loop() {
    memset(d, 0, sizeof(d));

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < E; j++) {
            Edge e = es[j];
            if (d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;

                if (i == V-1) return true;
            }
        }
    }
    return false;
}
