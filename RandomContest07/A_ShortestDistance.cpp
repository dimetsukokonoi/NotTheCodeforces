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

const ll cons = 1e18;

void solve() {
    int N, M, S, D;
    cin >> N >> M >> S >> D;
    vector<vector<pair<int,int>>> g(N+1);
    vector<int> u(M), v(M), w(M);
    for (int i = 0; i < M; i++) cin >> u[i];
    for (int i = 0; i < M; i++) cin >> v[i];
    for (int i = 0; i < M; i++) cin >> w[i];
    for (int i = 0; i < M; i++) g[u[i]].pb({v[i], w[i]});
    vector<ll> dist(N+1, cons);
    vector<int> par(N+1, -1);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    dist[S] = 0;
    pq.push({0,S});
    while(!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if(d != dist[u]) continue;
        for(auto [v,w] : g[u]) {
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                par[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    if(dist[D] == cons) {
        cout << -1 << nl;
        return;
    }
    cout << dist[D] << nl;
    vector<int> pth;
    for(int cur=D; cur!=-1; cur=par[cur]) pth.pb(cur);
    reverse(all(pth));
    for(int i=0;i<sz(pth);i++) cout << pth[i] << (i+1==sz(pth)?nl:" ");
}

int32_t main() {
    fastIO;
    solve();
    return 0;
}
