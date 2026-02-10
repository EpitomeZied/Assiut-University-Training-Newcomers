#include <bits/stdc++.h>
using namespace std;
#define Zied cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
#define lli long long int
#define ll long long
lli a, b, c=1, x, y, z;
lli arr[31][31];
void gen(){
    for (int i = 0; i < 31; ++i) {
        arr[i][0] =1;
    }
    for (int i = 1; i < 31; ++i) {
        for (int j = 1; j < 31; ++j) {
            arr[i][j] = arr[i-1][j]+ arr[i-1][j-1];
        }
    }
}



void rec(lli j){
    if(j<=1){
        return;
    }
    rec(j-1);
    c *= j;
}
int main() {
    Zied
    cin >> a >> b;
    gen();
    cout << arr[a][b];
}