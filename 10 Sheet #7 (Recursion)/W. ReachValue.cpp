#include <bits/stdc++.h>
using namespace std;

long long int n, x;
bool rec(long long int j, long long int x){
    if(j > x){return false;}
    else if(j==x){return true;}
    if(rec(j*10, x)){return true;}
    if(rec(j*20, x)){return true;}
    return false;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if(rec(1, x))
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}