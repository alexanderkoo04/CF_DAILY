#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void solve() {
    int cashiers;
    cin >> cashiers;
    vector<int> customer_items(cashiers, -1);
    vector<int> costs(cashiers, -1);
    for (int i = 0 ; i < cashiers; i++) {
        cin >> customer_items[i];
    }
    for (int i = 0; i < cashiers; i++) {
        int curr_cost = 0;
        for (int j = 0; j < customer_items[i]; j++) {
            int items;
            cin >> items;
            curr_cost += items * 5;
        }
        curr_cost += customer_items[i] * 15;
        costs[i] = curr_cost;
    }
    cout << *min_element(costs.begin(), costs.end()) << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}