#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define pb push_back
#define F first
#define S second
#define fastio ios::sync_with_stdio(false); cin.tie(0);

const int INF = 1e18;

int32_t main() {
    fastio;
    int N, M; 
    cin >> N >> M;
    
    vector<vector<pii>> g(N+1);
    for(int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
    }
    
    int S, D;
    cin >> S >> D;
    
    vector<int> dist(N+1, INF), parent(N+1, -1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    dist[S] = 0;
    pq.push({0, S});
    
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(d > dist[u]) continue;
        
        for(auto [v, w] : g[u]) {
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    
    if(dist[D] == INF) {
        cout << "Impossible\n";
        return 0;
    }
    vector<int> path;
    for(int cur = D; cur != -1; cur = parent[cur])
        path.pb(cur);
    reverse(path.begin(), path.end());
    
    cout << "Time " << dist[D] << "\n";
    cout << "Route ";
    for(int i = 0; i < path.size(); i++) {
        cout << path[i];
        if(i + 1 < path.size()) cout << "->";
    }
    cout << endl;
}
