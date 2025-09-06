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

struct DSU {
    vector<int> p, s;
    DSU(int n) {
        p.resize(n+1);
        s.assign(n+1,1);
        for(int i=1;i<=n;i++) p[i]=i;
    }
    int find(int x) {
        if(p[x]==x) return x;
        return p[x] = find(p[x]);
    }
    bool U(int a,int b) {
        a=find(a), b=find(b);
        if(a==b) return false;
        if(s[a]<s[b]) swap(a,b);
        p[b]=a;
        s[a]+=s[b];
        return true;
    }
};

void solve() {
    int n,m;
    cin>>n>>m;
    vector<array<int,3>> eg(m);
    for(int i=0;i<m;i++) cin>>eg[i][0]>>eg[i][1]>>eg[i][2];
    sort(all(eg), [](auto &a, auto &b){return a[2]<b[2];});

    DSU dsu(n);
    ll mCost=0;
    for(auto &e:eg) {
        if(dsu.U(e[0], e[1])) {
            mCost += e[2];
        }
    }
    cout<<mCost<<nl;
}

int32_t main() {
    fastIO;
    solve();
    return 0;
}
