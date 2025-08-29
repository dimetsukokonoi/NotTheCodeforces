#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,int>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int,int>>> adj(N+1);
    for(int i=0;i<M;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w}); 
    }
    const ll INF = 1e18;
    vector<ll> dist(N+1, INF);
    dist[1]=0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0,1});

    while(!pq.empty()){
        auto [d,u] = pq.top(); pq.pop();
        if(d>dist[u]) continue;
        for(auto [v,w]: adj[u]){
            if(dist[v] > dist[u]+w){
                dist[v] = dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
    unordered_map<ll, vector<int>> mp;
    for(int i=2;i<=N;i++){
        if(dist[i]<INF) mp[dist[i]].push_back(i);
    }

    bool found=false;
    for(auto &p: mp){
        if(p.second.size()>1){
            found=true;
            sort(p.second.begin(), p.second.end());
            for(int node: p.second) cout << node << "\n";
        }
    }
    if(!found) cout << -1 << "\n";
    return 0;
}
