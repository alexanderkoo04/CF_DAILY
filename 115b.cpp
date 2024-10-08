#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
using namespace std;

void solve() {
    int rows, cols;
    cin >> rows >> cols;
    vector<string> v(rows);
    ll sol = 0;
    for (int i = 0; i < rows; i++) {
        cin >> v[i];
    }
    int down = rows - 1;
    for (int i = rows - 1; i >= 0; i--) {
        down = min(down, i);
        if (v[i].find('W') != string::npos) break;
    }
    int r = 0, c = 0;
    while (r < down) {
        if (r % 2 == 0) { // right
            int cur, next;
            if (v[r].rfind('W') == string::npos) cur = -1;
            else cur = v[r].rfind('W');
            if (v[r + 1].rfind('W') == string::npos) next = -1;
            else next = v[r + 1].rfind('W');
            if (cur == -1 && next == -1) {
                // cout << "Down 1" << endl;
                r++;
                sol++;
                continue;
            }
            else {
                int target = max(cur, next);
                int dist = abs(c - max(cur, next));
                c = target;
                // cout << cur << " " << next << endl;
                // cout << "Right " << dist << endl;
                sol += dist + 1;
                // cout << "Down 1" << endl;
                // cout << endl;
                r++;
            }
        }
        else { // left
            int cur, next;
            if (v[r].find('W') == string::npos) cur = 200;
            else cur = v[r].find('W');
            if (v[r + 1].find('W') == string::npos) next = 200;
            else next = v[r + 1].find('W');
            if (cur == 200 && next == 200) {
                // cout << "Down 1" << endl;
                r++;
                sol++;
                continue;
            }
            else {
                int target = min(cur, next);
                int dist = abs(c - min(cur, next));
                // cout << cur << " " << next << endl;
                c = target;
                // cout << "Left " << dist << endl;
                sol += dist + 1;
                // cout << "Down 1" << endl;
                // cout << endl;
                r++;
            }
        }
    }
    if (down % 2 == 1) { // left
        int cur = v[down].find('W');
        if (cur != string::npos) {
            int dist = abs(c - cur);
            c = cur;
            sol += dist;
        }
    }
    else { // right
        int cur = v[down].rfind('W');
        if (cur != string::npos) {
            int dist = abs(c - cur);
            c = cur;
            sol += dist;
        }
    }
    // cout << r << " " << c << endl;
    // cout << down << endl;
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