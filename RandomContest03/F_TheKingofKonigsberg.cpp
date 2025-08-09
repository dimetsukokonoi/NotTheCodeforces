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
    int n, x, y; cin>>n>>x>>y;
    vector<pair<int, int>> v;
    int x1[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int y1[] = {0, 0, -1, 1, -1, 1, -1, 1};
    for (int i = 0; i < 8; i++) {
        int currX = x + x1[i];
        int currY = y + y1[i];
        if (currX >= 1 && currX <= n && currY >= 1 && currY <= n) {
            v.pb({currX, currY});
        }
    }
    sort(all(v));
    cout<<v.size()<<nl;
    for (auto a : v) {
        cout<<a.first<<" " <<a.second << nl;
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