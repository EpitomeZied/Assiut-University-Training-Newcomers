#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int mn = a[0], mx = a[n - 1];
    for (int i = 0; i < n; i++) {
        if (!(i))
            cout << abs(a[i] - a[i + 1]) << " ";
        else if (i == n - 1)
            cout << abs(a[i] - a[i - 1]) << " ";
        else if (i && abs(a[i] - a[i - 1]) < abs(a[i] - a[i + 1]))
            cout << abs(a[i] - a[i - 1]) << " ";
        else
            cout << abs(a[i] - a[i + 1]) << " ";
        if (abs(mn - a[i]) > abs(mx - a[i]))
            cout << abs(mn - a[i]) << endl;
        else
            cout << abs(mx - a[i]) << endl;
    }
    return 0;
}
