#include <bits/stdc++.h>
using namespace std;

int n, c;
bool check = true;
void rec(int *arr,int j){
    if(j>= n/2){
        return;
    }
    rec(arr,j+1);
    if(arr[j] != arr[n-j-1]){
        check = false;
    }
}
int main() {
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; ++i) {cin >> arr[i];}
    rec(arr,0);
    if(check){cout <<"YES"<<endl;}
    else{cout << "NO"<<endl;}
}