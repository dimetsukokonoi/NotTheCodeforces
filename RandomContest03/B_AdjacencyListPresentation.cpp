#include <bits/stdc++.h>
using namespace std;

#define         fastIO   ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout.precision(numeric_limits<double>::max_digits10);
#define           int    long long
#define          all(v)   v.begin(), v.end()
#define         rall(v)   v.rbegin(), v.rend()
#define           pb      push_back
#define          sz(a)    (int)a.size()
#define           nl      "\n"
#define          yes      cout << "YES\n"
#define           no      cout << "NO\n"
#define      isEven(l)    ((l) % 2 == 0)
#define       gcd(a,b)    __gcd(a,b)

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> u(m), v(m), w(m);
    for (int i = 0; i < m; ++i) cin >> u[i];
    for (int i = 0; i < m; ++i) cin >> v[i];
    for (int i = 0; i < m; ++i) cin >> w[i];
    vector<vector<pair<int, int>>> arr(n + 1);
    for (int i = 0; i < m; ++i) {
        pair<int, int> eg;
        eg.first = v[i];
        eg.second = w[i];
        arr[u[i]].pb(eg);
    }
    for (int i = 1; i <= n; ++i) {
        cout << i << ":";
        for (int j = 0; j < arr[i].size(); ++j) {
            cout << " (" << arr[i][j].first << "," << arr[i][j].second << ")";
        }
        cout<<nl;
    }

}

int32_t main() {
    fastIO;
    // int t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }
    solve();
    return 0;
}