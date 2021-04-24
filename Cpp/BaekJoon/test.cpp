#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the gridlandMetro function below.
int gridlandMetro(int n, int m, int k, vector<vector<int>> track) {
    unordered_map<int, vector<pair<long long , long long>>> mp;
    for(int i = 0; i < k; ++i) {
        long long r = track[i][0];
        long long c1 = track[i][1];
        long long c2 = track[i][2];
        mp[r].push_back({c1, c2});
    }
    long long ans = (long long)n * (long long)m;
    for(auto& [row, intervals] : mp) {
        sort(intervals.begin(), intervals.end());
        long long left = intervals[0].first, right = intervals[0].second;
        //cout << "==================row : " << row << endl;
        for(int i = 1; i < intervals.size(); ++i) {
            if(right < intervals[i].first) {
                ans -= (right - left + 1);
                cout << "right : " << right << "\tleft : " << left << "\tans : " << ans << endl;
                left = intervals[i].first;
                right = intervals[i].second;
            } else {
                right = max(right, intervals[i].second);
            }
        }
        ans -= (right - left + 1);
        cout << "\tright : " << right << "\tleft : " << left << "\tans : " << ans << endl;
    }
    return ans;
}

int main()
{
    string nmk_temp;
    getline(cin, nmk_temp);

    vector<string> nmk = split_string(nmk_temp);

    int n = stoi(nmk[0]);

    int m = stoi(nmk[1]);

    int k = stoi(nmk[2]);

    vector<vector<int>> track(k);
    for (int i = 0; i < k; i++) {
        track[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> track[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = gridlandMetro(n, m, k, track);

    cout << result << "\n";

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
