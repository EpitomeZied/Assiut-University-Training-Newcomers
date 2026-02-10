#include <bits/stdc++.h>
using namespace std;
#define lol long long int

int main() {
    int students, subs;
    cin >> students >> subs;
    int Size = students * subs;
    vector<char> marks(Size), higherMarks(subs);
    for (int i = 0; i < Size; i++) {
        cin >> marks[i];
    }
    int index = 0;
    for (int i = 0; i < subs; i++) {
        int max = marks[i];
        for (int x = i + subs; x < Size; x += subs) {
            if (max < marks[x]) {
                max = marks[x];
            }
        }
        higherMarks[index] = max;
        index++;
    }
    int count = 0;
    for (int z = 0; z < students; z++) {
        int x = 0;
        for (int i = z * subs; i < (z + 1) * subs; i++) {
            if (marks[i] == higherMarks[x]) {
                count++;
                break;
            }
            x++;
        }
    }
    cout << count;
}
