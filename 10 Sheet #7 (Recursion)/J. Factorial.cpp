#include <bits/stdc++.h>
using namespace std;
#define Zied cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
#define ll long long
ll c =1;
void rec(ll n) {
    if(n == 1){
        return;
    }
    rec(n-1);
    c *= n;
}

int main() {
    Zied
     ll n;cin>>n;
    rec(n);
    cout << c <<endl;
}