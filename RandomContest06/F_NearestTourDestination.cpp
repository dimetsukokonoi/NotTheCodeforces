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

void solve() {
    int N, M, S, Q;
    cin >> N >> M >> S >> Q;
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> src(S);
    for (int i = 0; i < S; i++) {
        cin >> src[i];
    }
    vector<int> destin(Q);
    for (int i = 0; i < Q; i++) {
        cin >> destin[i];
    }
    vector<int> dist(N + 1, -1);
    queue<int> q;
    for (int s : src) {
        dist[s] = 0;
        q.push(s);
    }
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int next : adj[curr]) {
            if (dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
    for (int i = 0; i < Q; i++) {
        cout << dist[destin[i]];
        if (i < Q - 1) cout << " ";
    }
    cout << nl;
}

int32_t main() {
    fastIO;
    solve();
    return 0;
}