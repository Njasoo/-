int n, m;
int dis[N];
bool vis[N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // (cost, id);
int sum = 0;
bool prim() {
    dis[1] = 0;
    int tot = 0;
    q.push(make_pair(0, 1));
    while (!q.empty() && tot < n) {
        int d = q.top().first;
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        tot++;
        sum += d;
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].next) {
            int v = e[i].to;
            int w = e[i].cost;
            if (w < dis[v]) { // dis用来标记有无遍历过此点
                dis[v] = w;
                q.push(make_pair(dis[v], v));
            }
        }
    }
    return tot == n;
}