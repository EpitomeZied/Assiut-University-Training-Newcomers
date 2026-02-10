#include <bits/stdc++.h>
using namespace std;

int m;
ll rec(ll *arr, int j, ll n ) {
    if (j >= n){return 0;}
    return rec(arr,j+1, n) + ((n - m <= j) ? arr[j] : 0);
}

int main() {
    ll n; cin>>n >> m;
    ll arr[n];
    for (int i = 0; i < n; ++i) {cin >> arr[i];}
    cout << rec(arr, 0, n) <<endl;
}