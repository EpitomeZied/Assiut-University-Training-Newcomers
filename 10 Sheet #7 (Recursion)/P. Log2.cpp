#include <bits/stdc++.h>
using namespace std;

long long int c=0;

void rec(long long int n){
    if(n <= 1){
        return;
    }
    c++;
    return rec(n / 2);
}
int main() {

    long long int n;
    cin >> n;
    rec(n);
    cout << c<<endl;

}