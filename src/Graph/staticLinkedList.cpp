struct E {
    int v, w, next;
} es[MAXN];

int head[MAXN], tot;

void add(int u, int v, int w) {
    es[tot].v = v;
    es[tot].w = w;
    es[tot].next = head[u];
    head[u] = tot++;
}

int main(void) {
    tot = 1;
    memset(head, 0, sizeof(head));

    add(u, v, w);

    // find all edges coming from u
    for (int i = head[u]; i; i = es[i].next) {
    }
}
