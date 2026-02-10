#include <bits/stdc++.h>
using namespace std;

int n;
double s;
void rec(int *arr,int j){
    if(j>= n){
        return;
    }
    rec(arr,j+1);
    s += arr[j];
}
int main() {
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; ++i) {cin >> arr[i];}
    rec(arr,0);
    cout << setprecision(6) << fixed << (s/n) <<endl;
}