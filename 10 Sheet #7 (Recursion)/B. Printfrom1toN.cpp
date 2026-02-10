#include <bits/stdc++.h>
using namespace std;
#define Zied cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
#define ll long long
int rec(int n,int i =1) {
    if(i <= n){
        cout << i <<endl;
        i++;
        rec(n,i);
    }
}

int main() {
    Zied
    int n; cin >> n;
    rec(n);
}