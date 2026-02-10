#include <bits/stdc++.h>
using namespace std;
#define lol long long int

int main() {
    lol eye, mouth, body;
    cin >> eye >> mouth >> body;

    if (eye == 0 || body == 0) {
        cout << 0;
        return 0;
    }

    if (eye <= mouth && eye <= body) {
        cout << eye;
        return 0;
    }
    if (body <= mouth && body <= eye) {
        cout << body;
        return 0;
    }


    lol result = 0;
    if (eye >= mouth && body >= mouth) {
        if (mouth <= body)
            result += mouth;

        eye -= mouth;
        body -= mouth;

        eye /= 2;
        if (eye <= body)
            result += eye;
        else
            result += body;
        cout << result;
        return 0;
    }
}
