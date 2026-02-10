#include <bits/stdc++.h>

using namespace std;
int n, s, f[50], m = INT_MAX;

int main() {
    cin >> s >> n;
    for (int i = 0; i < n; i++)
        cin >> f[i];
    sort(f, f + n);
    for (int e = 0; e <= n - s; e++) {
        int w;
        w = abs(f[e] - f[e + s - 1]);
        m = min(m, w);
    }
    cout << m;
    return 0;
}
