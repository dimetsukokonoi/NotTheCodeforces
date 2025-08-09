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
    int n,m,k; cin>>n>>m>>k;
    vector<vector<bool>> f(n + 1, vector<bool>(m + 1, false));
    vector<pair<int, int>> kngt(k);

    for (int i = 0; i < k; i++) {
        cin >> kngt[i].first >> kngt[i].second;
        f[kngt[i].first][kngt[i].second] = true;
    }
    int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[] = {-1,  1, -2,  2, -2, 2, -1, 1};
    for (auto a : kngt) {
        int x = a.first, y = a.second;
        for (int i = 0; i < 8; i++) {
            int currX = x + dx[i];
            int currY = y + dy[i];
            if (currX >= 1 && currX <= n && currY >= 1 && currY <= m) {
                if (f[currX][currY]){
                    yes;
                    return;
                }
            }
        }
    }
    no;
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