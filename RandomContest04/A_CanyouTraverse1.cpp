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

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> vsArr(N + 1, 0);
    vector<int> bfs;
    queue<int> q;

    vsArr[1] = 1;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        bfs.pb(u);

        for (int v : adj[u]) {
            if (!vsArr[v]) {
                vsArr[v] = 1;
                q.push(v);
            }
        }
    }
    for (int i = 0; i < sz(bfs); i++) {
        cout << bfs[i] << (i + 1 < sz(bfs) ? ' ' : '\n');
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
