#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
const int INF = 1e15;

struct Edge {
    int u, v, w, id;
};

int n, m, L, s, d;
vector<Edge> edges;
vector<vector<pair<int,int>>> adj;

vector<int> dijkstra(int src, vector<Edge>& edges) {
    vector<int> dist(n, INF);
    dist[src] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});
    while(!pq.empty()) {
        auto [du,u] = pq.top(); pq.pop();
        if(du != dist[u]) continue;
        for(auto [v, id] : adj[u]) {
            int w = edges[id].w;
            if(dist[v] > du + w) {
                dist[v] = du + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> L >> s >> d;
    edges.resize(m);
    adj.assign(n, {});
    for(int i=0;i<m;i++){
        int u,v,w; cin >> u >> v >> w;
        edges[i] = {u,v,w,i};
        adj[u].push_back({v,i});
        adj[v].push_back({u,i}); 
    }
    for(auto &e : edges) if(e.w==0) e.w=1;
    auto dist = dijkstra(s, edges);
    if(dist[d] > L) {
        cout << "NO\n";
        return 0;
    }
    for(auto &e : edges) if(e.w==1 && e.id>=0) {
        if(e.w == 1) e.w = INF;
    }
    auto dist2 = dijkstra(s, edges);
    if(dist2[d] < L) {
        cout << "NO\n";
        return 0;
    }
    for(auto &e : edges) if(e.w==INF) e.w = 1;
    while(true) {
        auto dcur = dijkstra(s, edges);
        if(dcur[d] == L) break;
        vector<int> par(n,-1), peid(n,-1);
        vector<int> distp(n, INF);
        distp[s]=0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0,s});
        while(!pq.empty()){
            auto [du,u]=pq.top();pq.pop();
            if(du!=distp[u]) continue;
            for(auto [v,id]:adj[u]){
                int w=edges[id].w;
                if(distp[v]>du+w){
                    distp[v]=du+w;
                    par[v]=u; peid[v]=id;
                    pq.push({distp[v],v});
                }
            }
        }
        int need = L - distp[d];
        int cur = d;
        while(par[cur]!=-1){
            int id=peid[cur];
            if(edges[id].w==1){
                edges[id].w += need;
                break;
            }
            cur=par[cur];
        }
        for(auto &e:edges) if(e.w==1) e.w=INF;
    }

    cout << "YES\n";
    for(auto &e : edges) {
        cout << e.u << " " << e.v << " " << e.w << "\n";
    }
}
