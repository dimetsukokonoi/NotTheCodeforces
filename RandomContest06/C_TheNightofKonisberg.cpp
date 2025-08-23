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

const int disX[8] = {2, 2, -2, -2, 1, 1, -1, -1};
const int disY[8] = {1, -1, 1, -1, 2, -2, 2, -2};

void solve() {
    int N;
    cin >> N;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vector<vector<int>> dist(N+1, vector<int>(N+1, -1));
    queue<pair<int,int>> q;
    q.push({x1, y1});
    dist[x1][y1] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        if (x == x2 && y == y2) {
            cout << dist[x][y] << nl;
            return;
        }

        for (int i = 0; i < 8; i++) {
            int nx = x + disX[i];
            int ny = y + disY[i];

            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    cout << -1 << nl;
}

int32_t main() {
    fastIO;
    // int t = 1;
    // while (t--) solve();
    solve();
    return 0;
}
