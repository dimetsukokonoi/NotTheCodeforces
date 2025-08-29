#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18;

struct Edge {
    int to;
    ll w;
};

vector<ll> dijkstra(int start, const vector<vector<Edge>>& adj) {
    int n = adj.size() - 1;
    vector<ll> dist(n + 1, INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) continue;

        for (auto &e : adj[u]) {
            if (dist[e.to] > dist[u] + e.w) {
                dist[e.to] = dist[u] + e.w;
                pq.push({dist[e.to], e.to});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, S, D, K;
    cin >> N >> M >> S >> D >> K;

    vector<int> U(M), V(M);
    for (int i = 0; i < M; i++) cin >> U[i];
    for (int i = 0; i < M; i++) cin >> V[i];
    vector<ll> W(M);
    for (int i = 0; i < M; i++) cin >> W[i];

    vector<vector<Edge>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        adj[U[i]].push_back({V[i], W[i]});
        adj[V[i]].push_back({U[i], W[i]});
    }
    vector<ll> distS = dijkstra(S, adj);
    vector<ll> distK = dijkstra(K, adj);

    ll ans = INF;
    if (distS[K] != INF && distK[D] != INF) {
        ans = distS[K] + distK[D];
    }
    if (ans == INF) cout << -1 << "\n";
    else cout << ans << "\n";

    return 0;
}
