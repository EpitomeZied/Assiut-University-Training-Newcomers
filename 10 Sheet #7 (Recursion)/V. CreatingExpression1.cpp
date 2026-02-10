#include <bits/stdc++.h>
using namespace std;
#define Zied cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
#define lli long long int
#define ll long long
lli n, x, c;
bool rec(long long *arr,lli j, lli sum){
    if(j==n){
        if(sum == x){
            return true;
        }
        return false;
    }
    if(rec(arr,j+1 , sum + arr[j])){return true;}
    if(rec(arr,j+1, sum -arr[j]))return true;

    return false;
}
int main() {
    Zied
    cin >> n >> x;
    long long int arr[n];
    for (int i = 0; i < n; ++i) {cin >> arr[i];}
    if(!rec(arr, 1, arr[0])){cout <<"NO"<<endl;}
    else{cout<<"YES"<<endl;}
}