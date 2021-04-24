#include <bits/stdc++.h>

using namespace std;

void solve() {
    int V, E, start;
    cin >> V >> E >> start;
    --start;
    vector<int> dist(V, INT_MAX);
    vector<vector<pair<int, int>>> edges(V, vector<pair<int, int>>());
    for(int i = 0; i < E; ++i) {
        int from, to, cost;
        cin >> from >> to >> cost;
        --from;
        --to;
        edges[from].push_back({to, cost});
    }
    auto comp = [](auto& a, auto& b) {
        return a > b;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        auto [currentDist, from] = pq.top();
        pq.pop();
        if(dist[from] < currentDist) {
            continue;
        }
        for(auto [to, cost] : edges[from]) {
            if(dist[from] + cost < dist[to]) {
                dist[to] = dist[from] + cost;
                pq.push({dist[to], to});
            }
        }
    }
    for(int i = 0; i < V; ++i) {
        if(dist[i] == INT_MAX) {
            cout << "INF\n";
        } else {
            cout << dist[i] << '\n';
        }
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}