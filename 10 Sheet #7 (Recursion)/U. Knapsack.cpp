#include <bits/stdc++.h>
using namespace std;
#define Zied cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
#define lli long long int
#define ll long long
vector<pair<int,int>>v;
int rec(int n, int w, int j, int sum){
    if(j>= n || w <0 ){
        return sum;
    }
    if(v[j].first > w){
        return  rec(n, w, j+1, sum );
    }
    return max( v[j].second+ rec(n, w-v[j].first, j+1, sum  ), rec(n, w, j+1, sum ));
}
int main() {
    Zied
    int n, w, a, b;
    cin >> n >> w;
    for (int i = 0; i < n; ++i) {cin >> a >>b;v.push_back(make_pair(a,b));}
    cout << rec(n, w, 0, 0);
}