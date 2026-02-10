/*
 * Competitive Programming Template
 * Author: Your Name
 * Purpose: Standard template for quick problem solving
 */

#include <bits/stdc++.h>
using namespace std;

// Type definitions
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<string> vs;

// Macros
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for(int i = a; i < b; i++)
#define per(i, a, b) for(int i = a; i >= b; i--)

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-9;

// Utility functions
template<typename T>
void print(const vector<T>& v) {
    for(const auto& x : v) cout << x << " ";
    cout << endl;
}

template<typename T>
void read(vector<T>& v) {
    for(auto& x : v) cin >> x;
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

ll power(ll base, ll exp, ll mod = MOD) {
    ll result = 1;
    while(exp > 0) {
        if(exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

bool isPrime(ll n) {
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(ll i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// ==================== SOLUTION ====================

void solve() {
    // Your solution here
    
}

// ==================== MAIN ====================

int main() {
    fastio;
    
    int t = 1;
    // cin >> t;  // Uncomment for multiple test cases
    
    while(t--) {
        solve();
    }
    
    return 0;
}
