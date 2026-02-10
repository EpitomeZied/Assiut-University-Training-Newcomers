/*
 * Fast I/O Template
 * Purpose: Optimized input/output for large data sets
 * Use when: Dealing with millions of input/output operations
 */

#include <bits/stdc++.h>
using namespace std;

// Fast I/O setup
inline void setupIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

// Fast integer input
inline int readInt() {
  int x = 0;
  bool neg = false;
  char c = getchar_unlocked();

  while (c != '-' && (c < '0' || c > '9')) {
    c = getchar_unlocked();
  }

  if (c == '-') {
    neg = true;
    c = getchar_unlocked();
  }

  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - '0'; // x = x*10 + c-'0'
    c = getchar_unlocked();
  }

  return neg ? -x : x;
}

// Fast long long input
inline long long readLL() {
  long long x = 0;
  bool neg = false;
  char c = getchar_unlocked();

  while (c != '-' && (c < '0' || c > '9')) {
    c = getchar_unlocked();
  }

  if (c == '-') {
    neg = true;
    c = getchar_unlocked();
  }

  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar_unlocked();
  }

  return neg ? -x : x;
}

// Fast integer output
inline void writeInt(int x) {
  if (x < 0) {
    putchar_unlocked('-');
    x = -x;
  }

  if (x > 9)
    writeInt(x / 10);
  putchar_unlocked(x % 10 + '0');
}

// Fast long long output
inline void writeLL(long long x) {
  if (x < 0) {
    putchar_unlocked('-');
    x = -x;
  }

  if (x > 9)
    writeLL(x / 10);
  putchar_unlocked(x % 10 + '0');
}

// ==================== SOLUTION ====================

void solve() {
  // Example usage:
  // int n = readInt();
  // writeInt(n);
  // putchar_unlocked('\n');
}

// ==================== MAIN ====================

int main() {
  setupIO();

  int t = 1;
  // t = readInt();  // For multiple test cases

  while (t--) {
    solve();
  }

  return 0;
}
