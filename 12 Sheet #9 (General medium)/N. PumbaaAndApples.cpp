#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <tuple>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
#define ll long long int

void Zied() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
}

int main() {
    Zied();
    ll rows, cols, cases;
    cin >> rows >> cols >> cases;

    ll **arr = new ll *[rows];
    for (ll i = 0; i < rows; i++) {
        arr[i] = new ll[cols];
    }
    for (ll i = 0; i < rows; i++) {
        for (ll x = 0; x < cols; x++) {
            cin >> arr[i][x];
        }
    }

    ll *arrR = new ll[rows];
    ll *arrC = new ll[cols];
    for (ll i = 0; i < rows; i++) {
        arrR[i] = i;
    }
    for (ll i = 0; i < cols; i++) {
        arrC[i] = i;
    }
    char chr;
    ll n1, n2, r, c;

    while (cases--) {
        cin >> chr;

        cin >> n1 >> n2;
        n1--, n2--;
        if (chr == 'g') {
            r = arrR[n1];
            c = arrC[n2];
            cout << arr[r][c] << "\n";
        } else if (chr == 'r') {
            swap(arrR[n1], arrR[n2]);
        } else {
            swap(arrC[n1], arrC[n2]);
        }
    }
}
