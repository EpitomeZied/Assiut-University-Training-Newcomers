#include <bits/stdc++.h>
using namespace std;

void rec(int *arr, int j, int n) {
    if(j >= n){
        return;
    }
    rec(arr,j+2, n);
    cout << arr[j] <<" ";
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) { cin >> arr[i];}
    rec(arr, 0, n);
}