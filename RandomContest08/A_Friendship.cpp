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
    vector<int> pr, s;
    DSU(int n) {
        pr.resize(n+1);
        s.assign(n+1,1);
        for(int i=1;i<=n;i++) pr[i]=i;
    }
    int get(int x) {
        if(pr[x]==x) return x;
        return pr[x] = get(pr[x]);
    }
    int unite(int a,int b) {
        a=get(a), b=get(b);
        if(a==b) return s[a];
        if(s[a]<s[b]) swap(a,b);
        pr[b]=a;
        s[a]+=s[b];
        return s[a];
    }
};

void solve() {
    int n,k;
    cin>>n>>k;
    DSU dsu(n);
    while(k--) {
        int a,b; cin>>a>>b;
        cout<<dsu.unite(a,b)<<nl;
    }
}

int32_t main() {
    fastIO;
    solve();
    return 0;
}
