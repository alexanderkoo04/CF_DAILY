#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void solve() {
    int n;
    string input;
    cin >> n >> input;
    int r1 = 0, b1 = 0, r2 = 0, b2 = 0; // out of place
    // 1 = r b r b r
    // 2 = b r b r b
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (input[i] != 'r') r1++;
            else b2++;
        }
        else {
            if (input[i] != 'b') b1++;
            else r2++;
        }
    }
    int one = min(r1, b1) + (max(r1, b1) - min(r1, b1));
    int two = min(r2, b2) + (max(r2, b2) - min(r2, b2));
    cout << min(one, two);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}