#include <bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define INF 1e18

struct Edge {
    int to;
    ll weight;
};

int main() {
    fastIO;

    int N, M, S;
    cin >> N >> M >> S;
    S--;
    vector<int> u(M), v(M);
    vector<ll> w(M);
    for(int i = 0; i < M; i++) cin >> u[i];
    for(int i = 0; i < M; i++) cin >> v[i];
    for(int i = 0; i < M; i++) cin >> w[i];

    vector<vector<Edge>> adj(N);
    for(int i = 0; i < M; i++){
        adj[u[i]-1].pb({v[i]-1, w[i]});
    }
    ll min_cycle = INF;
    for(auto &e : adj[S]){
        int neighbor = e.to;
        ll edge_weight = e.weight;

        vector<ll> dist(N, INF);
        dist[neighbor] = 0;

        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
        pq.push({0, neighbor});

        while(!pq.empty()){
            auto [d, node] = pq.top(); pq.pop();
            if(d > dist[node]) continue;

            for(auto &ne : adj[node]){
                int to = ne.to;
                ll wgt = ne.weight;
                if(node == S && to == neighbor) continue; 
                if(dist[to] > dist[node] + wgt){
                    dist[to] = dist[node] + wgt;
                    pq.push({dist[to], to});
                }
            }
        }

        if(dist[S] != INF){
            min_cycle = min(min_cycle, dist[S] + edge_weight);
        }
    }

    cout << (min_cycle == INF ? -1 : min_cycle) << "\n";

    return 0;
}
