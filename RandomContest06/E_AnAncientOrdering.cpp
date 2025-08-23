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
    int N;
    cin >> N;
    vector<string> w(N);
    for (int i = 0; i < N; i++) {
        cin >> w[i];
    }
    vector<set<char>> adj(26);
    vector<int> inD(26, 0);
    set<char> c;
    for (int i = 0; i < N - 1; i++) {
        string w1 = w[i], w2 = w[i + 1];
        if (w1.size() > w2.size() && w1.substr(0, w2.size()) == w2) {
            cout << -1 << nl;
            return;
        }
        bool diff_found = false;
        for (size_t j = 0; j < min(w1.size(), w2.size()); j++) {
            if (w1[j] != w2[j]) {
                char c1 = w1[j], c2 = w2[j];
                int idx1 = c1 - 'a', idx2 = c2 - 'a';
                if (adj[idx1].find(c2) == adj[idx1].end()) {
                    adj[idx1].insert(c2);
                    inD[idx2]++;
                }
                diff_found = true;
                break;
            }
        }
        c.insert(w1.begin(), w1.end());
        c.insert(w2.begin(), w2.end());
    }
    if (N > 0) {
        c.insert(w.back().begin(), w.back().end());
    }
    int total = c.size();
    priority_queue<char, vector<char>, greater<char>> pq;
    for (char c : c) {
        if (inD[c - 'a'] == 0) {
            pq.push(c);
        }
    }
    string res = "";
    while (!pq.empty()) {
        char curr = pq.top();
        pq.pop();
        res += curr;
        int idx = curr - 'a';
        for (char next : adj[idx]) {
            int nidx = next - 'a';
            inD[nidx]--;
            if (inD[nidx] == 0) {
                pq.push(next);
            }
        }
    }
    if (res.size() != total) {
        cout << -1 << nl;
        return;
    }
    cout << res << nl;
}

int32_t main() {
    fastIO;
    solve();
    return 0;
}