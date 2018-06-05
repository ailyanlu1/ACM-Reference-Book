// Single Sourced Shortest Paths
// Positive weight
// Directed && bi-directed
// O(E*log(V)) - E << V^2
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define pb push_back
#define fi first
#define se second
const int maxn = 1e3;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> P;
priority_queue<P, vector<P>, greater<P> > q; // (cur_weight, vertex)
vector<P> G[maxn]; // edges, (to, weight)
int dis[maxn];
int vis[maxn];
int n = 5;
// int p[maxn]; // path

void add_edge(int u, int v, int w) {
    G[u].pb(P(v, w));
    G[v].pb(P(u, w));
}

void Dijkstra(int s) {
    fill_n(dis, n, INF);
    memset(vis, false, sizeof(vis));
    while (!q.empty()) q.pop();

    dis[s] = 0;
    q.push(P(0, s));
    while (!q.empty()) {
        P cur = q.top(); q.pop();
        int u = cur.se;

        if (vis[u]) continue;
        vis[u] = true;
        for (unsigned int i = 0; i < G[u].size(); i++) {
            int v = G[u][i].fi;
            int w = G[u][i].se;

            if (!vis[v] && dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                //p[v] = G[u][i];
                q.push(P(dis[v], v));
            }
        }
    }
}

int main(void) {
    for (int i = 0; i < n; i++) G[i].clear();
    //add_edge(0, 1, 10);
    Dijkstra(0);
    return 0;
}

