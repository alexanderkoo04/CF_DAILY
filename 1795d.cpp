#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;

const int MOD = 998244353;
const int MAX = 3 * 1e5 + 5;

ll fact[MAX];
ll inv_fact_arr[MAX];

ll power_mod(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while(b > 0){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for(int i = 1; i < MAX; i++) {
        fact[i] = fact[i-1] * i % MOD;
    }
    // inv_fact[n] = (fact[n])^{-1} mod MOD
    inv_fact_arr[MAX-1] = power_mod(fact[MAX-1], MOD-2, MOD);
    for(int i = MAX-2; i >=0; i--){
        inv_fact_arr[i] = inv_fact_arr[i+1] * (i+1) % MOD;
    }
}

ll comb(ll n, ll k){
    if(n < k || k < 0) return 0;
    return fact[n] * inv_fact_arr[k] % MOD * inv_fact_arr[n - k] % MOD;
}
void solve() {
    precompute();

    int n;
    cin >> n;
    ll sol = 1;
    for (int i = 0; i < n / 3; i++) {
        vector<ll> v(3, 0);
        for (int j = 0; j < 3; j++) {
            cin >> v[j];
        }
        vector<ll> m;
        for (int k = 0; k < v.size(); k++) {
            for (int l = k + 1; l < v.size(); l++) {
                m.push_back(v[k] + v[l]);
            }
        }
        sort(m.begin(), m.end());
        int k = m.size() - 1;
        int count = 1;
        k--;
        while (m[k] == m[k + 1]) {
            count++;
            k--;
        }
        sol = sol * count % MOD;
    }
    ll first = n / 3;
    ll second = n / 6;
    ll comb_val = comb(first, second);
    sol = sol * comb_val % MOD;
    cout << sol << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}