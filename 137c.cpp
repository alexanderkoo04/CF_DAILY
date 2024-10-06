#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n); // start, end
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    int large = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (v[i].second < large) ans++;
        large = max(large, v[i].second);
    }
    cout << ans << endl;
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