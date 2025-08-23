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
    vector<int> indx(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        adj[A].pb(B);
        indx[B]++;
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (indx[i] == 0) q.push(i);
    }

    vector<int> ordr;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ordr.pb(u);

        for (int v : adj[u]) {
            indx[v]--;
            if (indx[v] == 0) q.push(v);
        }
    }

    if (sz(ordr) != N) {
        cout << -1 << nl;
    } else {
        for (int x : ordr) cout << x << " ";
        cout << nl;
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
