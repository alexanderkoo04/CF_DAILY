#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<ll> comb(n);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            if (!i) cin >> comb[j];
            else {
                int num;
                cin >> num;
                comb[j] -= num;
            }
        }
    }
    sort(comb.begin(), comb.end());
    int l = 0, r = n - 1;
    ll sol = 0;
    while (l < r) {
        ll sum = comb[l] + comb[r];
        if (sum > 0) {
            sol += r - l;
            r--;
        }
        else {
            l++;
        }
    }
    cout << sol << endl;
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