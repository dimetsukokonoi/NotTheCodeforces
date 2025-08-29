#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    double prob;
};

double maxProbability(int N, vector<vector<Edge>>& adj, int start, int end) {
    vector<double> maxProb(N, 0.0); 
    maxProb[start] = 1.0;
    priority_queue<pair<double,int>> pq;
    pq.push({1.0, start});

    while(!pq.empty()) {
        auto [prob, u] = pq.top(); pq.pop();
        if(u == end) return prob;

        for(auto &e: adj[u]) {
            double newProb = prob * e.prob;
            if(newProb > maxProb[e.to]) {
                maxProb[e.to] = newProb;
                pq.push({newProb, e.to});
            }
        }
    }

    return 0.0; 
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<Edge>> adj(N);

    for(int i = 0; i < M; i++) {
        int u, v;
        double p;
        cin >> u >> v >> p;          
        adj[u].push_back({v, p}); 
        adj[v].push_back({u, p});
    }

    int start, end;
    cin >> start >> end;

    cout << fixed << setprecision(6)
         << maxProbability(N, adj, start, end) << "\n";

    return 0;
}
