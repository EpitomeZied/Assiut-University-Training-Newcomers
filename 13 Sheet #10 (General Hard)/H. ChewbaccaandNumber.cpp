#include <bits/stdc++.h>
using namespace std;
#define lol long long int

int main() {
    string num;
    cin >> num;

    for (int i = 0; i < num.size(); i++) {
        if (i == 0 && num[i] == '9') {
            cout << 9;
            continue;
        }


        if (num[i] < '5') {
            cout << num[i];
        } else {
            cout << 9 - (num[i] - '0');
        }
    }
}
