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

int R, H;
vector<string> grd;
vector<vector<bool>> vis;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int bfs(int r, int c) {
    int dmonds = 0;
    queue<pair<int,int>> q;
    q.push({r,c});
    vis[r][c] = true;
    if (grd[r][c] == 'D') dmonds++;

    while(!q.empty()) {
        auto [x,y] = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int nX = x + dx[i];
            int nY = y + dy[i];
            if(nX>=0 && nX<R && nY>=0 && nY<H && !vis[nX][nY] && grd[nX][nY]!='#'){
                vis[nX][nY] = true;
                if(grd[nX][nY]=='D') dmonds++;
                q.push({nX,nY});
            }
        }
    }
    return dmonds;
}

void solve() {
    cin >> R >> H;
    grd.assign(R,"");
    vis.assign(R, vector<bool>(H,false));
    for(int i=0;i<R;i++) cin >> grd[i];
    int ans = 0;
    for(int i=0;i<R;i++){
        for(int j=0;j<H;j++){
            if(!vis[i][j] && grd[i][j]!='#'){
                ans = max(ans, bfs(i,j));
            }
        }
    }
    cout << ans << nl;
}

int32_t main() {
    fastIO;
    // int t; cin>>t;
    // while(t--){
    //     solve();
    // } 
    solve();
    return 0;
}
