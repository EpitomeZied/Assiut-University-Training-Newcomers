/*
 * Common Algorithms Library
 * Purpose: Reusable algorithm implementations
 * Usage: Copy needed functions to your solution
 */

#include <bits/stdc++.h>
using namespace std;

// ==================== NUMBER THEORY ====================

// Greatest Common Divisor (Euclidean Algorithm)
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }

// Least Common Multiple
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }

// Extended Euclidean Algorithm
long long extGCD(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long x1, y1;
  long long d = extGCD(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return d;
}

// Modular Exponentiation
long long modPow(long long base, long long exp, long long mod) {
  long long result = 1;
  base %= mod;
  while (exp > 0) {
    if (exp & 1)
      result = (result * base) % mod;
    base = (base * base) % mod;
    exp >>= 1;
  }
  return result;
}

// Modular Inverse
long long modInv(long long a, long long mod) {
  return modPow(a, mod - 2, mod); // Works when mod is prime
}

// Factorial with modulo
long long factorial(int n, long long mod) {
  long long result = 1;
  for (int i = 2; i <= n; i++) {
    result = (result * i) % mod;
  }
  return result;
}

// Check if number is prime
bool isPrime(long long n) {
  if (n <= 1)
    return false;
  if (n <= 3)
    return true;
  if (n % 2 == 0 || n % 3 == 0)
    return false;

  for (long long i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0)
      return false;
  }
  return true;
}

// Sieve of Eratosthenes
vector<bool> sieve(int n) {
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;

  for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
  return is_prime;
}

// Prime factorization
vector<pair<long long, int>> primeFactors(long long n) {
  vector<pair<long long, int>> factors;

  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      int count = 0;
      while (n % i == 0) {
        n /= i;
        count++;
      }
      factors.push_back({i, count});
    }
  }

  if (n > 1)
    factors.push_back({n, 1});
  return factors;
}

// Count divisors
int countDivisors(long long n) {
  int count = 0;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      count += (i * i == n) ? 1 : 2;
    }
  }
  return count;
}

// Sum of divisors
long long sumDivisors(long long n) {
  long long sum = 0;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      sum += i;
      if (i * i != n)
        sum += n / i;
    }
  }
  return sum;
}

// ==================== COMBINATORICS ====================

// Binomial coefficient (n choose k)
long long binomial(int n, int k) {
  if (k > n)
    return 0;
  if (k == 0 || k == n)
    return 1;

  long long result = 1;
  for (int i = 0; i < k; i++) {
    result = result * (n - i) / (i + 1);
  }
  return result;
}

// Binomial coefficient with modulo
long long binomialMod(int n, int k, long long mod) {
  if (k > n)
    return 0;
  if (k == 0 || k == n)
    return 1;

  vector<long long> fact(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
  }

  return (fact[n] * modInv(fact[k], mod) % mod * modInv(fact[n - k], mod)) %
         mod;
}

// ==================== STRING ALGORITHMS ====================

// Check if string is palindrome
bool isPalindrome(const string &s) {
  int n = s.length();
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - 1 - i])
      return false;
  }
  return true;
}

// Reverse string
string reverseString(string s) {
  reverse(s.begin(), s.end());
  return s;
}

// Count character frequency
map<char, int> charFrequency(const string &s) {
  map<char, int> freq;
  for (char c : s)
    freq[c]++;
  return freq;
}

// ==================== ARRAY ALGORITHMS ====================

// Binary search (returns index, -1 if not found)
int binarySearch(const vector<int> &arr, int target) {
  int left = 0, right = arr.size() - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
      return mid;
    if (arr[mid] < target)
      left = mid + 1;
    else
      right = mid - 1;
  }

  return -1;
}

// Find maximum subarray sum (Kadane's Algorithm)
long long maxSubarraySum(const vector<int> &arr) {
  long long max_sum = arr[0];
  long long current_sum = arr[0];

  for (size_t i = 1; i < arr.size(); i++) {
    current_sum = max((long long)arr[i], current_sum + arr[i]);
    max_sum = max(max_sum, current_sum);
  }

  return max_sum;
}

// Prefix sum array
vector<long long> prefixSum(const vector<int> &arr) {
  int n = arr.size();
  vector<long long> prefix(n + 1, 0);

  for (int i = 0; i < n; i++) {
    prefix[i + 1] = prefix[i] + arr[i];
  }

  return prefix;
}

// ==================== SORTING ====================

// Merge two sorted arrays
vector<int> mergeSorted(const vector<int> &a, const vector<int> &b) {
  vector<int> result;
  int i = 0, j = 0;

  while (i < a.size() && j < b.size()) {
    if (a[i] <= b[j])
      result.push_back(a[i++]);
    else
      result.push_back(b[j++]);
  }

  while (i < a.size())
    result.push_back(a[i++]);
  while (j < b.size())
    result.push_back(b[j++]);

  return result;
}

// ==================== GEOMETRY ====================

struct Point {
  double x, y;

  Point(double x = 0, double y = 0) : x(x), y(y) {}

  double distance(const Point &other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    return sqrt(dx * dx + dy * dy);
  }
};

// Distance between two points
double distance(double x1, double y1, double x2, double y2) {
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// Area of circle
double circleArea(double radius) { return M_PI * radius * radius; }

// Circumference of circle
double circleCircumference(double radius) { return 2 * M_PI * radius; }

// Area of triangle (Heron's formula)
double triangleArea(double a, double b, double c) {
  double s = (a + b + c) / 2;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

// ==================== UTILITY ====================

// Check if number is power of 2
bool isPowerOfTwo(long long n) { return n > 0 && (n & (n - 1)) == 0; }

// Count set bits
int countSetBits(long long n) {
  int count = 0;
  while (n) {
    count += n & 1;
    n >>= 1;
  }
  return count;
}

// Reverse number
long long reverseNumber(long long n) {
  long long reversed = 0;
  while (n > 0) {
    reversed = reversed * 10 + n % 10;
    n /= 10;
  }
  return reversed;
}

// Check if number is palindrome
bool isNumberPalindrome(long long n) { return n == reverseNumber(n); }

// Sum of digits
int digitSum(long long n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
