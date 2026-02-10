#include <bits/stdc++.h>
using namespace std;
#define Zied cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
#define lli long long int
#define ll long long
int rec(int n){
    if(n <= 1){
        return n;
    }
    return rec(n-1) + rec(n-2);
}
int main() {
    Zied
    int n;
    cin >> n;
    cout << rec(n-1)<<endl;

}