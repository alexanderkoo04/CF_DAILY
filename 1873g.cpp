#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void solve() {
    string input;
    cin >> input;
    int a_count = 0;
    int b_count = 0;
    int smallest_a_group = INT_MAX;
    int curr_a_group = 0;
    for (auto c : input) {
        if (c == 'A') {
            a_count++;
            curr_a_group++;
        }
        else {
            b_count++;
            if (curr_a_group) {
                smallest_a_group = min(smallest_a_group, curr_a_group);
                curr_a_group = 0;
            }
        }
    }
    if (curr_a_group) smallest_a_group = min(smallest_a_group, curr_a_group);
    for (int i = 0; i < input.size() - 1; i++) {
        if (input[i] == input[i + 1] && input[i] == 'B') {
            cout << a_count << endl;
            return;
        }
    }
    if (input[0] == 'B' || input[input.size() - 1] == 'B') {
        cout << a_count << endl;
    }
    else cout << a_count - smallest_a_group << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    auto t = 0;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}