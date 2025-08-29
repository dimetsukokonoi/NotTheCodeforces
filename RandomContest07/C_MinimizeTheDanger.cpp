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

const int cons = 1e9;

int N,M;

void solve() {
    cin>>N>>M;
    vector<vector<pair<int,int>>> g(N+1);
    for(int i=0;i<M;i++){
        int u,v,w;cin>>u>>v>>w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    vector<int> dist(N+1,cons);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    dist[1]=0; pq.push({0,1});
    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        if(d!=dist[u]) continue;
        for(auto [v,w]:g[u]){
            int nd=max(dist[u],w);
            if(nd<dist[v]){
                dist[v]=nd;
                pq.push({nd,v});
            }
        }
    }
    for(int i=1;i<=N;i++){
        if(dist[i]==cons) cout<<-1<<(i==N?nl:" ");
        else cout<<dist[i]<<(i==N?nl:" ");
    }
}

int32_t main() {
    fastIO;
    solve();
    return 0;
}
