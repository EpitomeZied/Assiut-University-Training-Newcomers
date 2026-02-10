#include <bits/stdc++.h>
using namespace std;
#define lol long long int
#define endl '\n'
char letters[] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
    'x', 'y', 'z'
};

int main() {
    int size, distinct;
    cin >> size >> distinct;

    for (int i = 0; i < size; i++)
        cout << (char) ('a' + i % distinct);
}
