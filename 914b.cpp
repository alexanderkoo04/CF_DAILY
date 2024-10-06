#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void solve() {
    int useless;
    cin >> useless;
    unordered_map<int, int> freq;
    int num;
    for (int i = 0; i < useless; i++) {
        cin >> num;
        freq[num]++;
    }
    for (auto p : freq) {
        if (p.second % 2 != 0) {
            cout << "Conan" << endl;
            return;
        }
    }
    cout << "Agasa" << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}