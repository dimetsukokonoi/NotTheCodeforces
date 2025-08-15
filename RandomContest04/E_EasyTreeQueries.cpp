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

const int mx = 200005;
vector<int> adj[mx];
int sbTr[mx];

void dfs(int u, int p) {
    sbTr[u] = 1;
    for (int a : adj[u]) {
        if (a == p) continue;
        dfs(a, u);
        sbTr[u] += sbTr[a];
    }
}
void solve(){
    int N, R;
    cin >> N >> R;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(R, -1);
    int Q;
    cin >> Q;
    while (Q--) {
        int X;
        cin >> X;
        cout << sbTr[X] <<nl;
    }
}
int main() {
    fastIO;
    // int n; cin>>n;
    // while(t--){
    //     solve();
    // }
    solve();
}
