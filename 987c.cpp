#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n, {-1, -1});
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            if (i & 1) cin >> v[j].second;
            else cin >> v[j].first;
        }
    }
    // for (auto p : v) {
    //     cout << p.first << " " << p.second << endl;
    // }
    int globalMin = INT_MAX;
    for (int i = 1; i < n - 1; i++) {
        bool first = false;
        bool last = false;
        int curCost = 0;
        // first
        int firstNum = INT_MAX;
        for (int j = 0; j < i; j++) {
            if (v[j].first < v[i].first) {
                first = true;
                firstNum = min(firstNum, v[j].second);
            }
        }
        if (!first) continue;
        // last
        int lastNum = INT_MAX;
        for (int j = i + 1; j < n; j++) {
            if (v[j].first > v[i].first) {
                last = true;
                lastNum = min(lastNum, v[j].second);
            }
        }
        if (!last) continue;
        curCost = firstNum + v[i].second + lastNum;
        globalMin = min(globalMin, curCost);
    }
    (globalMin == INT_MAX) ? cout << "-1" << endl : cout << globalMin << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // auto t = 0;
    // std::cin >> t;
    // for (int i = 0; i < t; i++) {
    //     solve();
    // }
    solve();
}