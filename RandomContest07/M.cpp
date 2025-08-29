#include <bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pb push_back
#define INF 1e18

struct Edge {
    int to;
    ll weight;
};

int main() {
    fastIO;

    int N, M, S1, S2, S3, D;
    cin >> N >> M >> S1 >> S2 >> S3 >> D;
    S1--; S2--; S3--; D--;

    vector<int> u(M), v(M);
    vector<ll> w(M);
    for(int i=0;i<M;i++) cin >> u[i];
    for(int i=0;i<M;i++) cin >> v[i];
    for(int i=0;i<M;i++) cin >> w[i];

    vector<vector<Edge>> adj(N);
    for(int i=0;i<M;i++){
        adj[u[i]-1].pb({v[i]-1, w[i]});
        adj[v[i]-1].pb({u[i]-1, w[i]});
    }

    auto dijkstra = [&](int start){
        vector<ll> dist(N, INF);
        dist[start] = 0;
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
        pq.push({0,start});

        while(!pq.empty()){
            auto [d,node] = pq.top(); pq.pop();
            if(d > dist[node]) continue;

            for(auto &e : adj[node]){
                if(dist[e.to] > dist[node] + e.weight){
                    dist[e.to] = dist[node] + e.weight;
                    pq.push({dist[e.to], e.to});
                }
            }
        }
        return dist;
    };

    vector<ll> dist1 = dijkstra(S1);
    vector<ll> dist2 = dijkstra(S2);
    vector<ll> dist3 = dijkstra(S3);

    ll result = max({dist1[D], dist2[D], dist3[D]});
    cout << result << "\n";

    return 0;
}
