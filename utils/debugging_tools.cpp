/*
 * Debugging Tools for Competitive Programming
 * Purpose: Macros and utilities for debugging
 * Usage: Include at top of solution, compile with -DDEBUG flag
 */

#include <bits/stdc++.h>
using namespace std;

// ==================== DEBUG MACROS ====================

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << (x) << endl
#define debug2(x, y)                                                           \
  cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#define debug3(x, y, z)                                                        \
  cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z       \
       << " = " << (z) << endl
#define debugArr(arr, n)                                                       \
  {                                                                            \
    cerr << #arr << " = [";                                                    \
    for (int i = 0; i < n; i++) {                                              \
      cerr << arr[i];                                                          \
      if (i < n - 1)                                                           \
        cerr << ", ";                                                          \
    }                                                                          \
    cerr << "]" << endl;                                                       \
  }
#define debugVec(v)                                                            \
  {                                                                            \
    cerr << #v << " = [";                                                      \
    for (size_t i = 0; i < v.size(); i++) {                                    \
      cerr << v[i];                                                            \
      if (i < v.size() - 1)                                                    \
        cerr << ", ";                                                          \
    }                                                                          \
    cerr << "]" << endl;                                                       \
  }
#define debugPair(p)                                                           \
  cerr << #p << " = (" << p.first << ", " << p.second << ")" << endl
#define debugMap(m)                                                            \
  {                                                                            \
    cerr << #m << " = {";                                                      \
    for (auto &p : m) {                                                        \
      cerr << p.first << ": " << p.second << ", ";                             \
    }                                                                          \
    cerr << "}" << endl;                                                       \
  }
#define debugSet(s)                                                            \
  {                                                                            \
    cerr << #s << " = {";                                                      \
    for (auto &x : s) {                                                        \
      cerr << x << ", ";                                                       \
    }                                                                          \
    cerr << "}" << endl;                                                       \
  }
#define trace(msg) cerr << ">>> " << msg << endl
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define debugArr(arr, n)
#define debugVec(v)
#define debugPair(p)
#define debugMap(m)
#define debugSet(s)
#define trace(msg)
#endif

// ==================== PRINT UTILITIES ====================

// Print vector
template <typename T>
void printVector(const vector<T> &v, const string &separator = " ") {
  for (size_t i = 0; i < v.size(); i++) {
    cout << v[i];
    if (i < v.size() - 1)
      cout << separator;
  }
  cout << endl;
}

// Print 2D vector
template <typename T> void print2D(const vector<vector<T>> &matrix) {
  for (const auto &row : matrix) {
    for (const auto &elem : row) {
      cout << elem << " ";
    }
    cout << endl;
  }
}

// Print array
template <typename T>
void printArray(const T arr[], int n, const string &separator = " ") {
  for (int i = 0; i < n; i++) {
    cout << arr[i];
    if (i < n - 1)
      cout << separator;
  }
  cout << endl;
}

// Print pair
template <typename T1, typename T2> void printPair(const pair<T1, T2> &p) {
  cout << "(" << p.first << ", " << p.second << ")" << endl;
}

// Print map
template <typename K, typename V> void printMap(const map<K, V> &m) {
  for (const auto &p : m) {
    cout << p.first << ": " << p.second << endl;
  }
}

// Print set
template <typename T> void printSet(const set<T> &s) {
  for (const auto &x : s) {
    cout << x << " ";
  }
  cout << endl;
}

// ==================== INPUT UTILITIES ====================

// Read vector
template <typename T> void readVector(vector<T> &v) {
  for (auto &x : v)
    cin >> x;
}

// Read 2D vector
template <typename T> void read2D(vector<vector<T>> &matrix) {
  for (auto &row : matrix) {
    for (auto &elem : row) {
      cin >> elem;
    }
  }
}

// Read array
template <typename T> void readArray(T arr[], int n) {
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
}

// ==================== TIMING UTILITIES ====================

class Timer {
private:
  chrono::time_point<chrono::high_resolution_clock> start_time;

public:
  Timer() { start(); }

  void start() { start_time = chrono::high_resolution_clock::now(); }

  double elapsed() {
    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end_time - start_time;
    return diff.count();
  }

  void printElapsed(const string &message = "Time elapsed") {
    cerr << message << ": " << elapsed() << " seconds" << endl;
  }
};

// ==================== ASSERTION UTILITIES ====================

#ifdef DEBUG
#define assert_equal(a, b)                                                     \
  {                                                                            \
    if ((a) != (b)) {                                                          \
      cerr << "Assertion failed: " << #a << " != " << #b << " (" << (a)        \
           << " != " << (b) << ")" << endl;                                    \
      exit(1);                                                                 \
    }                                                                          \
  }
#define assert_true(condition)                                                 \
  {                                                                            \
    if (!(condition)) {                                                        \
      cerr << "Assertion failed: " << #condition << " is false" << endl;       \
      exit(1);                                                                 \
    }                                                                          \
  }
#define assert_false(condition)                                                \
  {                                                                            \
    if (condition) {                                                           \
      cerr << "Assertion failed: " << #condition << " is true" << endl;        \
      exit(1);                                                                 \
    }                                                                          \
  }
#else
#define assert_equal(a, b)
#define assert_true(condition)
#define assert_false(condition)
#endif

// ==================== RANDOM UTILITIES ====================

// Random integer in range [min, max]
int randomInt(int min, int max) {
  static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<int> dist(min, max);
  return dist(rng);
}

// Random double in range [min, max]
double randomDouble(double min, double max) {
  static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  uniform_real_distribution<double> dist(min, max);
  return dist(rng);
}

// Generate random vector
vector<int> randomVector(int n, int min, int max) {
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    v[i] = randomInt(min, max);
  }
  return v;
}

// ==================== TEST CASE UTILITIES ====================

// Compare output with expected
bool compareOutput(const string &output, const string &expected) {
  return output == expected;
}

// Run test case
template <typename Func>
void runTest(Func solve, const string &input, const string &expected) {
  // Redirect cin to read from string
  istringstream iss(input);
  streambuf *old_cin = cin.rdbuf(iss.rdbuf());

  // Redirect cout to write to string
  ostringstream oss;
  streambuf *old_cout = cout.rdbuf(oss.rdbuf());

  // Run solution
  solve();

  // Restore cin and cout
  cin.rdbuf(old_cin);
  cout.rdbuf(old_cout);

  // Compare output
  string output = oss.str();
  if (compareOutput(output, expected)) {
    cerr << "✓ Test passed" << endl;
  } else {
    cerr << "✗ Test failed" << endl;
    cerr << "Expected: " << expected << endl;
    cerr << "Got:      " << output << endl;
  }
}

// ==================== USAGE EXAMPLE ====================

/*
// Compile with debug mode:
// g++ -std=c++17 -DDEBUG solution.cpp -o solution

void solve() {
    Timer timer;

    int n;
    cin >> n;
    vector<int> arr(n);
    readVector(arr);

    debug(n);
    debugVec(arr);

    // Your solution here

    timer.printElapsed("Solution time");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
*/
