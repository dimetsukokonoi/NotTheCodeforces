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
    vector<int> arr(n + 1, 0);
    vector<int> u(m), v(m);
    for (int i = 0; i < m; ++i) cin >> u[i];
    for (int i = 0; i < m; ++i) cin >> v[i];
    for (int i = 0; i < m; ++i) {
        arr[u[i]]++;
        arr[v[i]]++;
    }
    int oC = 0;
    for (int i = 1; i <= n; ++i) {
        if (arr[i] % 2 != 0) {
            oC++;
        }
    }

    if (oC == 0 || oC == 2) yes;
    else no;
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