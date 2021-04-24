#include <bits/stdc++.h>

using namespace std;

void normalize(vector<int>& nums) {
    nums.push_back(0);
    for(int i = 0; i < nums.size() - 1; ++i) {
        if(nums[i] < 0) {
            int borrow = (abs(nums[i]) + 9) / 10;
            nums[i + 1] -= borrow;
            nums[i] += borrow * 10;
        } else {
            nums[i + 1] += (nums[i] / 10);
            nums[i] %= 10;
        }
    }
    while(nums.size() > 1 && nums.back() == 0) {
        nums.pop_back();
    }
}

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    vector<int> c(a.size() + b.size() + 1, 0);
    for(int i = 0; i < a.size(); ++i) {
        for(int j = 0; j < b.size(); ++j) {
            c[i + j] += a[i] * b[j];
        }
    }
    normalize(c);
    return c;
}

// a += b * (10^k)
void addTo(vector<int>& a, const vector<int>& b, int k) {
    int newSize = max(a.size(), b.size() + k);
    while(a.size() != newSize) {
        a.push_back(0);
    }
    for(int i = 0; i < b.size(); ++i) {
        a[i + k] += b[i];
    }
    normalize(a);
}

//a.size() >= b.size()
void subFrom(vector<int>& a, const vector<int>& b) {
    for(int i = 0; i < b.size(); ++i) {
        a[i] -= b[i];
    }
    normalize(a);
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
    if(a.size() < b.size()) {
        return karatsuba(b, a);
    }
    int an = a.size();
    int bn = b.size();
    if(an <= 50) {
        return multiply(a, b);
    }
    if(an == 0 || bn == 0) {
        return vector<int>();
    }
    int half = an / 2;
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min((int)b.size(), half));
    vector<int> b1(b.begin() + min((int)b.size(), half), b.end());
    
    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);

    addTo(a0, a1, 0);
    addTo(b0, b1, 0);

    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);

    vector<int> result;
    addTo(result, z0, 0);
    addTo(result, z1, half);
    addTo(result, z2, half * 2);

    return result;
}

void solve() {
    string numA, numB;
    cin >> numA >> numB;

    int an = numA.size();
    int bn = numB.size();

    vector<int> a(an);
    vector<int> b(bn);
    for(int i = 0; i < an; ++i) {
        a[an - i - 1] = numA[i] - '0';
    }
    for(int i = 0; i < bn; ++i) {
        b[bn - i - 1] = numB[i] - '0';
    }
    vector<int> result = karatsuba(a, b);
    for(int i = result.size() - 1; ~i; --i) {
        cout << result[i];
    }
    cout << '\n';
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}