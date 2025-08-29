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

struct eg { int to; ll w; };

int32_t main() {
    fastIO;
    int n, m, S, D;
    cin >> n >> m >> S >> D;

    vector<vector<eg>> g(n+1);
    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }

    const ll cons = 1e18;
    vector<ll> dist1(n+1, cons), dist2(n+1, cons);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;

    dist1[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist2[u]) continue;

        for (auto e : g[u]) {
            ll nd = d + e.w;

            if (nd < dist1[e.to]) {
                swap(dist1[e.to], nd);
                pq.push({dist1[e.to], e.to});
            }
            if (nd > dist1[e.to] && nd < dist2[e.to]) {
                dist2[e.to] = nd;
                pq.push({dist2[e.to], e.to});
            }
        }
    }

    if (dist2[D] == cons) cout << -1 << nl;
    else cout << dist2[D] << nl;

    return 0;
}
