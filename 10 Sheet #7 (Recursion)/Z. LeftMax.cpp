#include <bits/stdc++.h>
using namespace std;
#define Zied cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
#define lli long long int
#define ll long long
lli n, c, mmx;

void rec(int j, int i, lli mx, int arr[]) {
    if (j > i) {
        return;
    }
    if (mx < arr[j]) {
        mmx = arr[j];
    }
    rec(j + 1, i, mx, arr);
}

int main() {
    Zied
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) { cin >> arr[i]; }
    mmx = arr[0];
    cout << mmx << " ";
    for (int i = 1; i < n; ++i) {
        rec(i - 1, i, mmx, arr);
        cout << mmx << " ";
    }
}
