#include <bits/stdc++.h>
using namespace std;
#define lol long long int
#define endl '\n'

int main() {
    lol validMoments = 0;
    lol size;
    cin >> size;
    lol *vec = new lol[size + 1];
    for (int i = 1; i <= size; i++) {
        cin >> vec[i];
    }

    lol current = 0;

    for (int i = 1; i <= size; i++) {
        //we store the biggest value until it equals with is index 
        current = max(vec[i], current); // 2 3 5
        if (i == current) // 2 3 4
            validMoments++;
    }
    cout << validMoments;
}
