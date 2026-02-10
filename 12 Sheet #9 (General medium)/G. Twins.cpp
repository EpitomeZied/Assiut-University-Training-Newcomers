#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a[101], sum, r, l, d;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	r = n, l = 1, d = a[n], sum = a[1];
	while (r > l) {
		if (d > sum) {
			l++;
			sum += a[l];
		} else {
			r--;
			d += a[r];
		}
	}
	cout << n - r + 1;
}
