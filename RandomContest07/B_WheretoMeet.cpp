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

const ll cons = 1e18;
int N,M,S,T;

vector<ll> djk(int src, vector<vector<pair<int,int>>> &g) {
    vector<ll> dist(N+1, cons);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    dist[src]=0; pq.push({0,src});
    while(!pq.empty()) {
        auto [d,u]=pq.top(); pq.pop();
        if(d!=dist[u]) continue;
        for(auto [v,w]:g[u]) {
            if(dist[u]+w<dist[v]) {
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}

void solve() {
    cin>>N>>M>>S>>T;
    vector<vector<pair<int,int>>> g(N+1);
    for(int i=0;i<M;i++){
        int u,v,w;cin>>u>>v>>w;
        g[u].pb({v,w});
    }
    auto da=djk(S,g);
    auto db=djk(T,g);
    ll gd=cons; int node=-1;
    for(int i=1;i<=N;i++){
        if(da[i]==cons||db[i]==cons) continue;
        ll m =max(da[i],db[i]);
        if(m <gd||(m ==gd&&i<node)){
            gd=m ; node=i;
        }
    }
    if(node==-1) cout<<-1<<nl;
    else cout<<gd<<" "<<node<<nl;
}

int32_t main() {
    fastIO;
    solve();
    return 0;
}
