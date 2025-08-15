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
    int N, M, S, D;
    cin >> N >> M >> S >> D;
    vector<vector<int>> arr(N + 1);
    vector<int> u(M), v(M);

    for (int i = 0; i < M; i++) cin >> u[i];
    for (int i = 0; i < M; i++) cin >> v[i];

    for (int i = 0; i < M; i++) {
        arr[u[i]].pb(v[i]);
        arr[v[i]].pb(u[i]);
    }

    for (int i = 1; i <= N; i++) sort(all(arr[i]));

    vector<int> dis(N + 1, -1), prnt(N + 1, -1);
    queue<int> q;

    dis[S] = 0;
    q.push(S);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int nxt : arr[node]) {
            if (dis[nxt] == -1) {
                dis[nxt] = dis[node] + 1;
                prnt[nxt] = node;
                q.push(nxt);
            }
        }
    }

    if (dis[D] == -1) {
        cout << -1 << nl;
        return;
    }

    cout << dis[D] << nl;
    vector<int> path;
    for (int cur = D; cur != -1; cur = prnt[cur]) {
        path.pb(cur);
    }
    reverse(all(path));

    for (int i = 0; i < sz(path); i++) {
        cout << path[i] << (i + 1 < sz(path) ? ' ' : '\n');
    }
}

int32_t main() {
    fastIO;
    // int t ; cin>>t;
    // while (t--) {
    //     solve();
    // }
    solve();
    return 0;
}
