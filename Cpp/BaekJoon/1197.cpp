#include <bits/stdc++.h>

using namespace std;

class Union {
public :
    vector<int> parent;
    Union(int sz) {
        parent = vector<int>(sz + 1);
        std::iota(parent.begin(), parent.end(), 0);
    }
    int find(int a) {
        if(parent[a] == a) {
            return a;
        }
        return parent[a] = find(parent[a]);
    }
    bool isSameGroup(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        return pa == pb;
    } 
    void merge(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if(pa != pb) {
            parent[pb] = pa;
        }
    }
};

class Edge {
public :
    int from;
    int to;
    int cost;
    Edge(int f, int t, int c) : from(f), to(t), cost(c) {}
};

void solve() {
    int V, E;
    cin >> V >> E;
    auto comp = [](const Edge& a, const Edge& b) {
        return a.cost > b.cost;
    };
    priority_queue<Edge, vector<Edge>, decltype(comp)> pq(comp);
    Union unions(V);
    for(int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push(Edge(a, b, c));
    }
    int cnt = 0;
    long long cost = 0;
    while(cnt < V - 1) {
        Edge e = pq.top();
        pq.pop();
        if(unions.isSameGroup(e.from, e.to)) {
            continue;
        }
        // cout << "merge From : " << (e.from) << "\tTo : " << (e.to) << endl;
        cost += e.cost;
        unions.merge(e.from, e.to);
        ++cnt;
    }
    cout << cost << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}