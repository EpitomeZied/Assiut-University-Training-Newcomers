#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;

    cin >> s;
    vector<int>v(n);
    for (auto &i : v)
        cin >> i;
    int ans = INT_MAX;
    for (int i = 0; i + 1 < n; ++i)
    {
        if (s[i] == 'R' && s[i + 1] == 'L')
        {
            int x = v[i], y = v[i + 1];
            ans = min(ans, (y - x) / 2);
        }
    }
    if (ans == INT_MAX)
        cout << -1;
    else
        cout << ans;
}