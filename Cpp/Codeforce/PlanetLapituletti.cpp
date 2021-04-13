#include <bits/stdc++.h>

using namespace std;

#define FOR(n) for(int i = 0; i < int(n); ++i)
#define RFOR(n) for(int i = n; ~i; --i)
#define NL '\n'

bool check(int v) {
    return v == 0 || v == 1 || v == 2 || v == 5 || v == 8;
}

bool isValidHour(int curHour, int hour, int minute) {
    if(!check(curHour / 10) || !check(curHour % 10))
        return false;
    int t = (curHour % 10);
    if(t == 5) t = 2;
    else if(t == 2) t = 5;
    int tt = (curHour / 10);
    if(tt == 5) tt = 2;
    else if(tt == 2) tt = 5;
    int v = t * 10 + tt;
    return minute > v;
}

bool isValidMin(int curMin, int hour, int minute) {
    if(!check(curMin / 10) || !check(curMin % 10))
        return false;
    int t = (curMin % 10);
    if(t == 5) t = 2;
    else if(t == 2) t = 5;
    int tt = (curMin / 10);
    if(tt == 5) tt = 2;
    else if(tt == 2) tt = 5;
    int v = t * 10 + tt;
    return hour > v;
}

string toString(int h, int m) {
    string s;
    if(h < 10)
        s += "0" + to_string(h);
    else
        s += to_string(h);
    s += ":";
    if(m < 10)
        s += "0" + to_string(m);
    else
        s += to_string(m);
    return s;
}

void solve() {
    int hour, minute;
    string curTime;
    cin >> hour >> minute >> curTime;
    int curHour = stoi(curTime.substr(0, 2));
    int curMin = stoi(curTime.substr(3, 4));
    //cout << "curHour : " << curHour << "\tcurMin : " << curMin << endl;
    if(isValidHour(curHour, hour, minute) && isValidMin(curMin, hour, minute)) {
        cout << toString(curHour, curMin) << NL;
        return;
    }
    while(true) {
   // for(int i = 0; i <= hour * minute; ++i) {
        curMin++;
        if(curMin >= minute) {
            curMin = 0;
            ++curHour;
        }
        if(curHour >= hour)
            curHour = 0;
        if(isValidHour(curHour, hour, minute) && isValidMin(curMin, hour, minute)) {
            cout << toString(curHour, curMin) << NL;
            return;
        }
    }
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testCase = 1;
    cin >> testCase;
    for(int t = 0; t < testCase; ++t) 
       solve();

    return 0;
}