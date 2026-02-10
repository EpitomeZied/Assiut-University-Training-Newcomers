#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define dl double long
#define speed std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define tcase int t;cin>>t;while(t--)
#define cin(v) for(auto &i : v) cin>>i
#define cout(v) for(auto &i : v)  cout<<i<<' '; cout<<endl;
#define bs(v,x) binary_search(v.begin(),v.end(),x)
#define pr(x,y) pair<x,y>
#define yn(x) if(x)cout<<"CHAT WITH HER!"<<endl;else cout<<"IGNORE HIM!"
#define low(x) transform(x.begin(),x.end(),x.begin(),::tolower)
#define up(x) transform(x.begin(),x.end(),x.begin(),::toupper)

void solve() {
    int n, sum = 0;
    cin >> n;
    char c;
    cin >> c;
    string x;
    while (n--) {
        int k = 0, flag = 1;
        cin >> x;
        set<char> s{x.begin(), x.end()};
        if (s.size() < c - '0' + 1) continue;
        for (auto i: s) {
            if (i != k + '0') {
                flag = 0;
                break;
            }
            if (i == c) break;
            k++;
        }
        if (flag) sum++;
    }
    cout << sum << endl;
}

int main() {
    speed;
    // tcase
    solve();
}