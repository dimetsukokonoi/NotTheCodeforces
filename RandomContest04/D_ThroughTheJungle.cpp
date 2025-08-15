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

vector<int> bfs(int strt, int end, const vector<vector<int>>& adj) {
    int n = sz(adj) - 1;
    vector<int> dist(n + 1, -1), prnt(n + 1, -1);
    queue<int> q;
    dist[strt] = 0;
    q.push(strt);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                prnt[v] = u;
                q.push(v);
            }
        }
    }

    if (dist[end] == -1) return {};

    vector<int> path;
    for (int cur = end; cur != -1; cur = prnt[cur]) path.pb(cur);
    reverse(all(path));
    return path;
}

void solve() {
    int N, M, S, D, K;
    cin >> N >> M >> S >> D >> K;
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    if (S == D && D == K) {
        cout << 0 << nl << S << nl;
        return;
    }
    vector<int> dir = bfs(S, K, adj);
    if (dir.empty()) {
        cout << -1 << nl;
        return;
    }
    vector<int> dir2 = bfs(K, D, adj);
    if (dir2.empty()) {
        cout << -1 << nl;
        return;
    }
    vector<int> fDir = dir;
    fDir.insert(fDir.end(), dir2.begin() + 1, dir2.end());
    cout << sz(fDir) - 1 << nl;
    for (int i = 0; i < sz(fDir); i++) {
        cout << fDir[i] << (i + 1 < sz(fDir) ? ' ' : '\n');
    }
}

int32_t main() {
    fastIO;
    // int t; cin>>t;
    // while (t--) {
    //     solve();
    // }
    solve();
    return 0;
}
