#include <bits/stdc++.h>
using namespace std;
#define Zied cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
#define ll long long
int rec(int f) {
    if (f/10 > 0)
    {
        rec(f/10);
    }
    cout << f%10 << " ";
}

int main() {
    Zied
     int n, f; cin >> n;
    while(n--){cin >> f ;rec(f);cout<<endl;}
}