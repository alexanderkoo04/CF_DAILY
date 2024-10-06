#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void solve() {
    int n, m, a, b;
    // n = number of rides
    // m = special tickets
    // a = cost of single ride ticket
    // b = cost of special ticket
    cin >> n >> m >> a >> b;
    if ((m * a) <= b) {
        cout << n * a << endl;
        return;
    }
    // use special ticket
    int money = 0;
    int m_count = n / m;
    money += m_count * b;
    int rem = n % m;
    if (rem * a <= b) {
        money += rem * a;
    }
    else {
        money += b;
    }
    cout << money << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}