#include <bits/stdc++.h>
// علمكم الله ما ينفعكم و نفعكم بما تعلمتم و زادكم علما
// وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَىٰ، وَأَنَّ سَعْيَهُ سَوْفَ يُرَىٰ
using namespace std;
#define ll long long
#define int long long
#define ull unsigned long long
#define ll long long int
#define endl '\n'
#define elif else if
#define endd(s) return void(cout << s << "\n")
#define Ceil(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define fr first
#define sc second
#define X first
#define Y second
#define fixed(n) fixed << setprecision(n)
#define sz(s) int32_t(s.size())
#define debug(x) cout << #x << ": " << (x) << "\n";
#define getline(s) getline(cin >> ws, s)
#define kill return 0
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define pi  3.14159
#define all(vec) vec.begin(), vec.end()
#define rall(v) v.rbegin(),v.rend()
typedef pair<int , int> pii;
#define cin(vec) for(auto& i : vec) cin >> i
#define cout(vec) for(auto& i : vec) cout << i << " "; cout << "\n";
const int N = 50000 + 1 , M = 998244353 , OO = 0X3F3F3F3F3F3F3F3F;
const double EPS = 1e-9;

void Zied(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}

template<typename T = int> istream& operator >>(istream& in, vector<T>& v) {
    for (auto& x : v)
        in >> x;
    return in;
}
template<typename T = int> ostream& operator <<(ostream& out, const vector<T>& v) {
    for (const T& x : v)
        out << x << ' ';
    return out;
}

int dx[] = {+0, +0, -1, +1, +1, +1, -1, -1};
int dy[] = {-1, +1, +0, +0, +1, -1, +1, -1};
char di[] = {'D', 'L', 'U', 'R'};

void preprocessing(){

}

void Solve() {
    string str;
    cin >> str;
    int sz = str.size() / 2;
    if (str == "?") {
        cout << "a" << endl;
        return;
    }
    int size = str.size() / 2;
    for (int i = 0, j = str.size() - 1; i < sz; i++, j--) {
        if (!(str[i] == str[j] || (str[i] == '?' && str[j] != '?') ||
              (str[i] != '?' && str[j] == '?') || str == "?")) {
            endd(-1);
        }
    }
    for (int i = 0, j = str.size() - 1; i <= size; i++, j--) {
        if (str[i] == '?' && str[j] != '?') {
            str[i] = str[j];
        } else if (str[i] != '?' && str[j] == '?') {
            str[j] = str[i];
        } else if (str[i] == '?' && str[j] == '?') {
            str[i] = str[j] = 'a';
        }
    }
    cout << str << endl;
}

int32_t main() {
    Zied();
    preprocessing();
    int test_cases = 1;
//    freopen("box.in", "r", stdin), freopen("box.out", "w", stdout);
//    cin >> test_cases;
    for (int tc = 1; tc <= test_cases; tc++) {
        //        cout << "Case #" << tc << ": ";
        Solve();
//                cout << endl;
    }
    kill;
    //    Time
}
/*
                ,     :     ,
           '.    ;    :    ;    ,`
     '-.  `.  `-.._ .:. _..-'  ,'
  ,     '-. .:  __     __  :.-' ,
  :  :    ,  ,-'"  `. .  `"-.  ,    ;  ;
  '  `._ ,-'" `"-.  .-".  .-"` "-._ ,'  ,'
        `:.   `.  `. -  `-'  ,'  , :    ,'
  ,    .      `.  `. -  `-'  ,'  , :  '    .
       ;  `,   `.  `-..__.,-' ,  ,` '    ;
   ` . :   `,.  `-..__,,..-' ,'  ,    :    ` .
       ` .   `-.__,,..-'   ,    ,   :    ` .

*/