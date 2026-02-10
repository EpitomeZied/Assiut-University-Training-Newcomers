#include <bits/stdc++.h>
using namespace std;
#define Zied cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
#define ll long long
void rec(int n, int j= 1) {
    if(n) {
        for (int i = 0; i < n - 1; ++i) { cout << " "; }
        for (int i = 0; i < j; ++i) { cout << "*"; }
    }
    if(n==0){return;}
    cout << endl;
    rec(n-1, j+2);
}

int main() {
    Zied
     int n; cin >> n;
    rec(n);
}