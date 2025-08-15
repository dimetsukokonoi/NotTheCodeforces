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

vector<vector<int>> adjArr;
vector<int> arrvis;
vector<int> dfsOr;

void dfs(int u) {
    arrvis[u] = 1;
    dfsOr.pb(u);
    for (int v : adjArr[u]) {
        if (!arrvis[v]) {
            dfs(v);
        }
    }
}

void solve() {
    int N, M;
    cin >> N >> M;

    adjArr.assign(N + 1, {});
    arrvis.assign(N + 1, 0);

    vector<int> u(M), v(M);
    for (int i = 0; i < M; i++) cin >> u[i];
    for (int i = 0; i < M; i++) cin >> v[i];

    for (int i = 0; i < M; i++) {
        adjArr[u[i]].pb(v[i]);
        adjArr[v[i]].pb(u[i]);
    }
    dfsOr.clear();
    dfs(1);
    for (int i = 0; i < sz(dfsOr); i++) {
        cout << dfsOr[i] << (i + 1 < sz(dfsOr) ? ' ' : '\n');
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
