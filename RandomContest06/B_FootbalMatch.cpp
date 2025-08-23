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
int clr[mx];

void solve() {
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        adj[i].clear();
        clr[i] = -1;
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int ans = 0;

    for (int i = 1; i <= N; i++) {
        if (clr[i] == -1) {
            queue<int> q;
            q.push(i);
            clr[i] = 0;
            int cnt0 = 1, cnt1 = 0;

            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (clr[v] == -1) {
                        clr[v] = clr[u] ^ 1;
                        if (clr[v] == 0) cnt0++;
                        else cnt1++;
                        q.push(v);
                    }
                }
            }
            ans += max(cnt0, cnt1);
        }
    }

    cout << ans << nl;
}

int32_t main() {
    fastIO;
    // int t = 1;
    // while (t--) solve();
    solve();
    return 0;
}
