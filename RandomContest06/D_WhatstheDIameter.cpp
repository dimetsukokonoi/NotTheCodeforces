#include <bits/stdc++.h>
using namespace std;

#define         fastIO   ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout.precision(numeric_limits<double>::max_digits10);
#define           ll     long long
#define          all(v)   v.begin(), v.end()
#define         rall(v)   v.rbegin(), v.rend()
#define           pb      push_back
#define          sz(a)    (int)a.size()
#define           nl      "\n"
#define          yes      cout << "YES\n"
#define           no      cout << "NO\n"
#define      isEven(l)    ((l) % 2 == 0)
#define          gcd(a,b) __gcd(a,b)

pair<int,int> bfs(const vector<vector<int>>& adj, int src) {
    int n = sz(adj) - 1;
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    int far = src;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (dist[u] > dist[far]) far = u;
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return {far, dist[far]};
}

void solve() {
    int N; 
    cin >> N;
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v; 
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    auto [u, _d1] = bfs(adj, 1);
    auto [v, _d2] = bfs(adj, u);

    cout << _d2 << nl;
    cout << u << " " << v << nl;
}

int32_t main() {
    fastIO;
    // int t = 1;
    // while (t--) solve();
    solve();
    return 0;
}
