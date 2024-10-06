#include <bits/stdc++.h>
#include <iostream>

typedef long long ll;
using namespace std;

void solve() {
    ll n;
    cin >> n;
    ll sum = 0;
    vector<ll> v(n, -1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    ll half = ceil((double)sum / 2.0);
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        cur += v[i];
        if (cur >= half) {
            cout << i + 1 << endl;
            return;
        }
    }
}

int main() {
    solve();
}