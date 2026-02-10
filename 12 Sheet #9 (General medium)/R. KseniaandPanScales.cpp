#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int main() {
    string x, y;
    cin >> x >> y;
    int idx;
    for (int i = 0; i < x.size(); ++i) {
        if (x[i] == '|') {
            idx = i;
            break;
        }
    }
    int left = idx, right = x.size() - idx - 1;
    if (abs(left - right) > y.size() || (abs(left - right) % 2 != y.size() % 2)) {
        cout << "Impossible";
        return 0;
    }
    int w = y.size() + left + right, p = 0;
    w /= 2;
    while (left++ != w) cout << (char) y[p++];
    cout << x;
    while (right++ != w) cout << (char) y[p++];
    return 0;
}
