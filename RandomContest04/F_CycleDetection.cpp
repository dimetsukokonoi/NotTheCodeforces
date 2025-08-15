#include <bits/stdc++.h>
using namespace std;

#define         fastIO   ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout.precision(numeric_limits<double>::max_digits10);
#define           int    long long
#define          all(v)   v.begin(), v.end()
#define         rall(v)   v.rbegin(), v.rend()
#define           pb      push_back
#define          sz(a)    (int)a.size()
#define           nl      "\n"
#define          yes      cout << "YES\n"
#define           no      cout << "NO\n"
#define      isEven(l)    ((l) % 2 == 0)
#define       gcd(a,b)    __gcd(a,b)

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

const int mx = 200005;
vector<vector<int>> adj;
vector<int> vis;
bool cyc;

void dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (vis[v] == 0) {
            dfs(v);
            if (cyc) return;
        } else if (vis[v] == 1) {
            cyc = true;
            return;
        }
    }
    vis[u] = 2;
}

void solve() {
    int n, m;
    cin >> n >> m;
    adj.assign(n + 1, {});
    vis.assign(n + 1, 0);
    cyc = false;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
        if (cyc) break;
    }
    if (cyc) yes;
    else no;
}

int32_t main() {
    fastIO;
    // int t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }
    solve();
    return 0;
}
