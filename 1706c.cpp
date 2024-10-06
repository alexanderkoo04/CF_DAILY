#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
using namespace std;

ll comp(vector<ll>& v, int i) {
    return (v[i] > v[i + 1] && v[i] > v[i - 1]) ? 0 : max(v[i + 1], v[i - 1]) + 1 - v[i];
}
void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n, -1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll total = 0;
    ll ans;
    for (int i = 1; i < n - 1; i += 2) {
        total += comp(v, i);
    }
    // cout << "Total = " << total << " ";
    if (n & 1) {
        cout << total << endl;
        return;
    }
    ans = total;
    for (int i = n - 2; i > 1; i -= 2) {
        total -= comp(v, i - 1);
        total += comp(v, i);
        ans = min(total, ans);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    auto t = 0;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}