#include <bits/stdc++.h>
using namespace std;

#define         fastIO   ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout.precision(numeric_limits<double>::max_digits10);
#define           ll     long long
#define          all(v)  v.begin(), v.end()
#define         rall(v)  v.rbegin(), v.rend()
#define           pb     push_back
#define          sz(a)   (int)a.size()
#define           nl     "\n"
#define          yes     cout << "YES\n"
#define           no     cout << "NO\n"
#define      isEven(l)   ((l) % 2 == 0)
#define          gcd(a,b) __gcd(a,b)

const ll cons = 1e18;

struct Edge {
    int v;
    ll w;
};

int32_t main() {
    fastIO;
    int n, m;
    cin >> n >> m;

    vector<int> u(m), v(m);
    vector<ll> w(m);
    for (int i = 0; i < m; i++) cin >> u[i];
    for (int i = 0; i < m; i++) cin >> v[i];
    for (int i = 0; i < m; i++) cin >> w[i];

    vector<vector<Edge>> g(n + 1);
    for (int i = 0; i < m; i++) g[u[i]].pb({v[i], w[i]});

    vector<vector<ll>> dist(n + 1, vector<ll>(3, cons));
    priority_queue<array<ll,3>, vector<array<ll,3>>, greater<>> pq;

    dist[1][2] = 0;
    pq.push({0, 1, 2});

    while (!pq.empty()) {
        auto [d, u, last] = pq.top(); pq.pop();
        if (d != dist[u][last]) continue;

        for (auto [to, wght] : g[u]) {
            int prty = wght % 2;
            if (last == 2 || prty != last) {
                if (dist[to][prty] > d + wght) {
                    dist[to][prty] = d + wght;
                    pq.push({dist[to][prty], to, prty});
                }
            }
        }
    }
    ll ans = min(dist[n][0], dist[n][1]);
    cout << (ans == cons ? -1 : ans) << nl;
    return 0;
}
