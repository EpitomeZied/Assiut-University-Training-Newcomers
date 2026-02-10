#include <bits/stdc++.h>
using namespace std;

int c=1;
void rec(int n){
    if(n<=1){
        return;
    }
    if(n%2 !=0){
        rec(3*n +1);
    }
    else{rec(n/2);}
    c++;
}
int main() {
    int n; cin >>n;
    rec(n);
    cout << c <<endl;
}