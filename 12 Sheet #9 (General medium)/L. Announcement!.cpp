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
ll counts[100001] = {0};

int main() {
    ll cases;
    cin >> cases;

    vector<ll> arr;

    for (ll i = 0; i < cases; i++) {
        cin >> arr[i];

        counts[arr[i]]++;
    }
    ll counter = 0;
    for (ll i = 0; i < cases; i++) {
        if (counts[arr[i]] > 1) {
            counter += counts[arr[i]] - 1;
            counts[arr[i]] = 0;
        }
    }

    if (counter == 0) {
        cout << -1;
    } else
        cout << counter;
}
