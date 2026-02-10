#include <bits/stdc++.h>

using namespace std;
int main() {
    int size;
    string word;
    cin >> size >> word;
    string result = "";
    int i = 0;
    while (size) {
        if (size % 2 == 0) {
            result = word[i] + result;
        } else {
            result = result + word[i];
        }
        i++;
        size--;
    }
    cout << result;
}
