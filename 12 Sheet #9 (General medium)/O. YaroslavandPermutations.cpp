#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, counter = 0, maxx = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        counter++;
        if (arr[i] != arr[i + 1]) {
            if (maxx < counter)
                maxx = counter;
            counter = 0;
        }
    }

    if (n % 2 == 0) {
        if (maxx > (n / 2))
            cout << "NO";
        else
            cout << "YES";
    } else {
        if (maxx > (n + 1) / 2)
            cout << "NO";
        else
            cout << "YES";
    }


    return 0;
}
