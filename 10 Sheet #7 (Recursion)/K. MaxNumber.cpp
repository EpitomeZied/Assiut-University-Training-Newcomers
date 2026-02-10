#include <bits/stdc++.h>
using namespace std;

long long c ;
void rec(long long *arr, int j , long long n) {
    if (j >= n){return;}
    rec(arr, j+1, n);
    if(arr[j] > c){
        c= arr[j];
    }
}

int main() {
    long long n;cin>>n;
    long long arr[n];
    for (int i = 0; i < n; ++i) {cin >> arr[i];}
    c = arr[0];
    rec(arr, 0, n);
    cout << c <<endl;
}