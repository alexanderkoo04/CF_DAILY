#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> states(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        // 0 = ignore
        // 1 = assign
        // 2 = use
        cin >> states[i];
    }
    unordered_map<int, vector<int>> adj_list;
    for (int i = 0; i < m; i++) {
        int from, to;
        if (states[to] != 1) {
            adj_list[from].push_back(to);
        }
    }
    vector<int> sol(n, 0);
    queue<int> q;
    
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}