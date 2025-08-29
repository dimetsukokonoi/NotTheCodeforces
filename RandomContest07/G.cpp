#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define pii pair<int,int>
#define F first
#define S second
#define fastio ios::sync_with_stdio(false);cin.tie(0);

const int INF = 1e18;

struct Node {
    int dist, u;
    vector<int> path;
    bool operator>(const Node &o) const {
        if (dist != o.dist) return dist > o.dist;
        return path > o.path; // ensure diff paths are considered
    }
};

int32_t main(){
    fastio;
    int n,m;
    cin>>n>>m;
    vector<int> X(m),Y(m),Z(m);
    for(int i=0;i<m;i++) cin>>X[i];
    for(int i=0;i<m;i++) cin>>Y[i];
    for(int i=0;i<m;i++) cin>>Z[i];

    vector<vector<pair<int,int>>> g(n);
    for(int i=0;i<m;i++){
        g[X[i]].pb({Y[i],Z[i]});
    }

    // store k=2 best paths
    vector<vector<pair<int,vector<int>>>> best(n);
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({0,0,{0}});

    while(!pq.empty()){
        auto cur=pq.top(); pq.pop();
        int u=cur.u, d=cur.dist;

        if(best[u].size()==2) continue;
        best[u].pb({d,cur.path});

        for(auto [v,w]:g[u]){
            auto np=cur.path;
            np.pb(v);
            pq.push({d+w,v,np});
        }
    }

    if(best[1].size()<2){
        cout<<-1<<"\n";
    }else{
        for(auto x:best[1][1].S){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
}
