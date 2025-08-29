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
int N,M,S,D;

void solve() {
    cin>>N>>M>>S>>D;
    vector<ll> w(N+1);
    for(int i=1;i<=N;i++) cin>>w[i];
    vector<vector<int>> g(N+1);
    for(int i=0;i<M;i++){
        int u,v;cin>>u>>v;
        g[u].pb(v);
    }
    vector<ll> dist(N+1,cons);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>> pq;
    dist[S]=w[S];
    pq.push({dist[S],S});
    while(!pq.empty()){
        auto [d,u]=pq.top();pq.pop();
        if(d!=dist[u]) continue;
        for(auto v:g[u]){
            if(dist[u]+w[v]<dist[v]){
                dist[v]=dist[u]+w[v];
                pq.push({dist[v],v});
            }
        }
    }
    if(dist[D]==cons) cout<<-1<<nl;
    else cout<<dist[D]<<nl;
}

int32_t main(){
    fastIO;
    solve();
    return 0;
}
