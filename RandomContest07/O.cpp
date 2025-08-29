#include <bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define nl "\n"

struct Edge {
    int to;
};
int main() {
    fastIO;

    int N, M, S, D;
    cin >> N >> M >> S >> D;
    S--; D--; 

    vector<int> u(M), v(M);
    for(int i = 0; i < M; i++) cin >> u[i];
    for(int i = 0; i < M; i++) cin >> v[i];
    for(int i = 0; i < M; i++) u[i]--; 
    for(int i = 0; i < M; i++) v[i]--;

    vector<ll> weight(N);
    for(int i = 0; i < N; i++) cin >> weight[i];

    vector<vector<int>> adj(N);
    for(int i = 0; i < M; i++) {
        adj[u[i]].pb(v[i]);
        adj[v[i]].pb(u[i]);
    }
    const ll INF = 1e18;
    vector<ll> dist(N, INF);
    dist[S] = weight[S];
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({dist[S], S});

    while(!pq.empty()) {
        auto [cost, node] = pq.top(); pq.pop();
        if(cost > dist[node]) continue;

        for(int to : adj[node]) {
            ll new_cost = cost + weight[to];
            if(new_cost < dist[to]) {
                dist[to] = new_cost;
                pq.push({new_cost, to});
            }
        }
    }

    ll ans = (dist[D] == INF ? -1 : dist[D]);
    cout << ans << nl;
    return 0;
}
