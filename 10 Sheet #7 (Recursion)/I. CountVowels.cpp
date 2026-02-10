#include <bits/stdc++.h>
using namespace std;
#define Zied cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
#define ll long long
int c =0;
void rec(string s, int j = 0) {
    if(j >= s.size()){
        return;
    }
    rec(s,j+1);
    if(s[j] == 'a' || s[j] == 'e' ||s[j] == 'i' ||s[j] == 'o' ||s[j] == 'u' ||s[j] == 'A' ||s[j] == 'E' ||s[j] == 'I' ||s[j] == 'O' ||s[j] == 'U' ){
        c++;
    }
    if(j==0)
        cout << c <<endl;
}

int main() {
    Zied
     string s; getline(cin,s);
    rec(s);
}