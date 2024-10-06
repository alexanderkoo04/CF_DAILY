#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if (k % 2 == 1) {
        int m = *max_element(v.begin(), v.end());
        for (auto& num : v) num = m - num;
    }
    else {
        for (int i = 0; i < 2; i++) {
            int m = *max_element(v.begin(), v.end());
            for (auto& num : v) num = m - num;
        }
    }
    for (auto num : v) cout << num << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    auto t = 0;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}