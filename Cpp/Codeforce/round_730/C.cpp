#include <bits/stdc++.h>

// World Best Trash Problem

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vii = vector<pii>;
using vll = vector<pll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

template <typename T>
void print(const vector<T>& v, char sp = ' ') {
    for (int i = 0; i < v.size(); ++i) {
        if (i > 0) cout << sp;
        cout << v[i];
    }
    cout << '\n';
}

template <typename T>
void print(const vector<vector<T>>& v, char sp = ' ') {
    for (auto& vv : v) print(vv, sp);
}

template <typename T>
void print(T v) {
    cout << v << '\n';
}

template <typename T>
void print(T v[], int sz, char sp = ' ') {
    for (int i = 0; i < sz; ++i) {
        if (i > 0) cout << sp;
        cout << v[i];
    }
    cout << '\n';
}

template <typename T>
void read(vector<T>& v) {
    for (auto& x : v) cin >> x;
}

template <typename T>
void read(vector<vector<T>>& v) {
    for (auto& a : v) read(a);
}

template <typename T>
void read(T a[], int sz) {
    for (int i = 0; i < sz; ++i) cin >> a[i];
}

double ans;
const double eps = 1e-12;

void dfs(vector<double> A, double v, double probability, int cnt, bool f,
         double step) {
    if (f) {
        ans += probability * step;
        return;
    }
    if (cnt == 0 || probability <= eps) return;
    for (int i = 0; i < 3; ++i) {
        if (A[i] <= eps) continue;
        double tmp = (cnt == 1) ? 0 : (min(A[i], v) / (cnt - 1));
        vector<double> newA = A;
        double newProbability = probability * A[i];
        for (int j = 0; j < 3; ++j) {
            if (j == i || newA[j] <= eps) {
                continue;
            }
            newA[j] += tmp;
        }
        if (A[i] - v <= eps) {
            newA[i] = 0;
            dfs(newA, v, newProbability, cnt - 1, i == 2, step + 1);
        } else {
            newA[i] -= v;
            dfs(newA, v, newProbability, cnt, i == 2, step + 1);
        }
    }
}

void solve() {
    vector<double> A(3);
    double v;
    read(A);
    cin >> v;
    ans = 0;
    dfs(A, v, 1.0, 3, false, 0.0);
    print(ans);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(12);
    cout << fixed;

    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
