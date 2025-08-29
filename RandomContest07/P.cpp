#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18;

struct Edge {
    int to;
    ll w;
};

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
    vector<ll> dist(N + 1, INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;

    if (S == K || D == K) {
        cout << -1 << "\n";
        return 0;
    }

    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u]) continue;
        if (u == D) break; 
        for (auto &e : adj[u]) {
            if (e.to == K) continue; 
            if (dist[e.to] > dist[u] + e.w) {
                dist[e.to] = dist[u] + e.w;
                pq.push({dist[e.to], e.to});
            }
        }
    }

    if (dist[D] == INF) cout << -1 << "\n";
    else cout << dist[D] << "\n";

    return 0;
}
