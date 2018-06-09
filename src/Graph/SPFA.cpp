// find negative cycle / SSSP
// worst: O(VE) 
// O(kE) k == 2
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

bool inq[MAXN];
queue<int> q;
int d[MAXN], cnt[MAXN];

bool spfa() {
    memset(cnt, 0, sizeof(cnt));
    fill_n(d, MAXN, INF);
    while (!q.empty()) q.pop();

    d[1] = 0;
    q.push(1);
    inq[1] = true;
    cnt[1]++;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        inq[u] = false;

        for (int i = head[u]; i; i = es[i].next) {
            int v = es[i].v, w = es[i].w;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                if (!inq[v]) {
                    cnt[v]++;

                    // found negative cycle
                    if (cnt[v] > n) {
                        return false;
                    }
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }
    return true;
}
