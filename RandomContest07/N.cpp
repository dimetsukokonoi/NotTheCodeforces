#include <bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define sz(a) (int)a.size()
#define nl "\n"

struct Edge {
    int to, color;
    ll weight;
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

    vector<ll> w(M);
    for(int i = 0; i < M; i++) cin >> w[i];

    vector<int> c(M);
    for(int i = 0; i < M; i++) cin >> c[i];

    vector<vector<Edge>> adj(N);
    for(int i = 0; i < M; i++) {
        adj[u[i]].pb({v[i], c[i], w[i]});
        adj[v[i]].pb({u[i], c[i], w[i]});
    }

    const ll INF = 1e18;
    vector<vector<ll>> dist(N, vector<ll>(2, INF));
    dist[S][0] = 0;
    priority_queue<tuple<ll,int,int>, vector<tuple<ll,int,int>>, greater<tuple<ll,int,int>>> pq;
    pq.push({0, S, 0});

    while(!pq.empty()) {
        auto [cost, node, state] = pq.top(); pq.pop();
        if(cost > dist[node][state]) continue;

        for(auto &e : adj[node]) {
            int next_state = state;
            if(state == 0) {
                if(e.color == 2) next_state = 1;
            } else {
                if(e.color == 1) continue; 
            }
            if(dist[e.to][next_state] > cost + e.weight) {
                dist[e.to][next_state] = cost + e.weight;
                pq.push({dist[e.to][next_state], e.to, next_state});
            }
        }
    }

    ll ans = min(dist[D][0], dist[D][1]);
    cout << (ans == INF ? -1 : ans) << nl;

    return 0;
}
