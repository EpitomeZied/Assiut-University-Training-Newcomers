#include<bits/stdc++.h>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define pi 3.14159265359
#define eps 1e-9


using namespace std;

pair<int, int> p[1002];
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int ook = 0;
    for(int i = 1; i <= n; ++i)
    {
        cin >> p[i].fi >> p[i].se;
        if(p[i].fi != p[i].se)
            ook = 1;
    }
    if(!ook)
    {
        for(int i = 1; i < n; ++i)
            if(p[i].fi < p[i+1].fi)
            {
                cout << "unrated";
                return 0;
            }
        cout << "maybe";
    }
    else
        cout << "rated";
    return 0;

}
