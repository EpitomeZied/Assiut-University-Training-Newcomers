#include <bits/stdc++.h>
using namespace std;
#define lol long long int
#define endl '\n'

bool check(string str1, string str2) {
    if (str1.size() > str2.size())
        return false;

    for (int i = 0, j = 0; i < str2.size(); i++) {
        if (str2[i] == str1[j])
            j++;

        if (j == str1.size())
            return true;
    }

    return false;
}


int main() {
    int tests;
    cin >> tests;

    while (tests--) {
        string str1, str2, help;
        string minStr, maxStr, result = "";

        cin >> str1 >> str2 >> help;

        if (!check(str1, str2)) {
            cout << "NO" << endl;
            continue;
        }

        maxStr = str2;
        minStr = str1;

        int x = 0;

        for (int i = 0; i < maxStr.size(); i++) {
            if (maxStr[i] == minStr[x] && x != minStr.size()) {
                result.push_back(maxStr[i]);
                x++;
                continue;
            }
            int index = help.find(maxStr[i]);
            if (index != string::npos) {
                help[index] = '?';
                result.push_back(maxStr[i]);
            } else
                goto end;
        }

        // cout << "result = " << result << endl;

        if (result == maxStr)
            cout << "YES" << endl;
        else
        end:
            cout << "NO" << endl;
    }
}
