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

struct Edge {
    int u, v;
    ll w;
    bool inMST;
    Edge(int _u, int _v, ll _w) {
        u = _u; v = _v; w = _w;
        inMST = false;
    }
};

struct DSU {
    vector<int> par, rnk;
    DSU(int n) {
        par.resize(n);
        rnk.assign(n, 0);
        for (int i = 0; i < n; i++) par[i] = i;
    }
    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (rnk[a] < rnk[b]) swap(a, b);
        par[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;
        return true;
    }
};

struct LCA {
    int N, LOG;
    vector<int> depth;
    vector<vector<int>> up;
    vector<vector<ll>> mx1, mx2;
    const ll neg = LLONG_MIN/4;

    LCA(int n) {
        N = n;
        LOG = 32 - __builtin_clz(N);
        depth.assign(N, 0);
        up.assign(LOG, vector<int>(N));
        mx1.assign(LOG, vector<ll>(N, neg));
        mx2.assign(LOG, vector<ll>(N, neg));
    }

    void build(vector<vector<pair<int,ll>>>& adj) {
        vector<bool> vis(N, false);
        queue<int> q;
        vis[0] = true;
        up[0][0] = 0;
        q.push(0);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto [v, w] : adj[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    depth[v] = depth[u] + 1;
                    up[0][v] = u;
                    mx1[0][v] = w;
                    mx2[0][v] = neg;
                    q.push(v);
                }
            }
        }

        for (int k = 1; k < LOG; k++) {
            for (int v = 0; v < N; v++) {
                int mid = up[k-1][v];
                up[k][v] = up[k-1][mid];
                vector<ll> cand = {mx1[k-1][v], mx2[k-1][v], mx1[k-1][mid], mx2[k-1][mid]};
                sort(all(cand));
                ll m1 = neg, m2 = neg;
                for (int i = 3; i >= 0; i--) {
                    if (cand[i] > m1) {
                        if (cand[i] != m1) { m2 = m1; m1 = cand[i]; }
                    } else if (cand[i] != m1 && cand[i] > m2) {
                        m2 = cand[i];
                    }
                }
                mx1[k][v] = m1;
                mx2[k][v] = m2;
            }
        }
    }

    pair<ll,ll> gMxP(int u, int v) {
        ll m1 = neg, m2 = neg;
        auto r = [&](ll a, ll b, ll c, ll d) {
            vector<ll> cand = {m1, m2, a, b, c, d};
            sort(all(cand));
            ll nm1 = neg, nm2 = neg;
            for (int i = (int)cand.size()-1; i >= 0; i--) {
                if (cand[i] > nm1) {
                    if (cand[i] != nm1) { nm2 = nm1; nm1 = cand[i]; }
                } else if (cand[i] != nm1 && cand[i] > nm2) {
                    nm2 = cand[i];
                }
            }
            m1 = nm1; m2 = nm2;
        };

        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for (int k = 0; diff; k++, diff >>= 1) {
            if (diff & 1) {
                r(mx1[k][u], mx2[k][u], neg, neg);
                u = up[k][u];
            }
        }
        if (u == v) return {m1, m2};
        for (int k = LOG-1; k >= 0; k--) {
            if (up[k][u] != up[k][v]) {
                r(mx1[k][u], mx2[k][u], mx1[k][v], mx2[k][v]);
                u = up[k][u];
                v = up[k][v];
            }
        }
        r(mx1[0][u], mx2[0][u], mx1[0][v], mx2[0][v]);
        return {m1, m2};
    }
};

ll secondMST(int N, vector<Edge>& edges) {
    sort(all(edges), [](auto &a, auto &b) { return a.w < b.w; });
    DSU dsu(N);
    vector<vector<pair<int,ll>>> adjMST(N);
    ll cost = 0;
    int used = 0;

    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            e.inMST = true;
            cost += e.w;
            adjMST[e.u].pb({e.v, e.w});
            adjMST[e.v].pb({e.u, e.w});
            used++;
        }
    }
    if (used < N-1) return -1;

    LCA lca(N);
    lca.build(adjMST);

    ll ans = LLONG_MAX;
    for (auto &e : edges) {
        if (e.inMST) continue;
        auto [mx1, mx2] = lca.gMxP(e.u, e.v);
        if (mx1 <= LLONG_MIN/8) continue;

        if (e.w > mx1) {
            ll cand = cost + (e.w - mx1);
            if (cand > cost && cand < ans) ans = cand;
        } else if (e.w == mx1 && mx2 > LLONG_MIN/8) {
            ll cand = cost + (e.w - mx2);
            if (cand > cost && cand < ans) ans = cand;
        }
    }
    return (ans == LLONG_MAX ? -1 : ans);
}

void solve() {
    int N, M; cin >> N >> M;
    vector<Edge> edges;
    for (int i = 0; i < M; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        edges.pb(Edge(u-1, v-1, w));
    }
    cout << secondMST(N, edges) << nl;
}

int32_t main() {
    fastIO;
    solve();
    return 0;
}
