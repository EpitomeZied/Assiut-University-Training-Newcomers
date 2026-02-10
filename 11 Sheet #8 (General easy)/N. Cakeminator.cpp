#include<bits/stdc++.h>

using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    char a[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    int ans = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if (a[row][col] == '.') {
                bool inRow = false, inCol = false;
                for (int j = 0; j < m; j++) inRow |= (a[row][j] == 'S');
                for (int j = 0; j < n; j++) inCol |= (a[j][col] == 'S');
                if (inRow && inCol) continue;
                ans++;
            }
        }
    }
    cout << ans;
}