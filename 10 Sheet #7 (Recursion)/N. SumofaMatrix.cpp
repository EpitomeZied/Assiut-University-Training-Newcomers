#include <bits/stdc++.h>
using namespace std;
#define Zied cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
#define lli long long int
#define ll long long
vector<int> v1, v2, v3;
void rec(int j){
    if(j >= v1.size()){return;}
    rec(j+1);
    v3.push_back(v1[j]+v2[j]);
}
int main() {
    Zied
    int x, y, z, k, c; cin>> x >> y;
    for (int i = 0; i < x*y; ++i) {cin >> z; v1.push_back(z);}
    for (int i = 0; i <x*y ; ++i) {cin >>z; v2.push_back(z);}
    rec(0);
    c= y;
    k=v3.size()-1;
    for (int i = 0; i < x; ++i) {
        c=y;
        while (c--){
            cout << v3[k] << " ";
            k--;
        }
        cout << endl;
    }
}