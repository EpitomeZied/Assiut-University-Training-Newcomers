#include <bits/stdc++.h>
using namespace std;
#define Zied cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
#define lli long long int
#define ll long long
int n, m, c =0;
int rec(int sum){
    if(sum == m){c++;}
    if(sum > m){return 0;}
    rec(sum +1); rec(sum+2); rec(sum +3);
}
int main() {
    Zied
    cin >> n >>m ;
    rec(n);
    cout << c <<endl;
}