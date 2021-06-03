#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

ll mxN = 1e16;

void solve() {
    ll N, K;
    cin >> N >> K;
    ll V = 1;
    while(V < mxN) {
        V *= K;
    }
    vector<ll> a(N);
    priority_queue<ll> pq;
    for(auto& i : a) {
        cin >> i;
        if(i > 0) {
            pq.push(i);
        }
    }
    while(!pq.empty() && V > 0) {
        ll t = pq.top();
        pq.pop();
        if(t >= V) {
            t -= V;
            V /= K;
            if(t > 0) {
                pq.push(t);
            }
        } else {
            pq.push(t);
            while(V > t) {
                V /= K;
            }
        }
    }
    if(pq.empty()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCase = 1;
    cin >> testCase;
    for (int t = 0; t < testCase; ++t) {
        solve();
    }

    return 0;
}
