/*************  C++ Header Template  *************/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using v2i = vector<vi>;
using v3i = vector<v2i>;
using vb = vector<bool>;
using v2b = vector<vb>;
using vs = vector<string>;
using v2s = vector<vs>;
using vc = vector<char>;
using v2c = vector<vc>;
using vl = vector<ll>;
using v2l = vector<vl>;
using v3l = vector<v2l>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define Boost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
#define rep(i,beg,end) for(int i=beg; i<end; i++)
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
template<class T>
void sort(T& container) { sort(container.begin(), container.end()); }
template<class T1, typename T2>
void sort(T1& container, T2 cmp) { sort(container.begin(), container.end(), cmp); }
template<class T1, class T2>
istream& operator>>(istream& is, pair<T1, T2>& rhs) { is >> rhs.fi >> rhs.se; return is; }
template<class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& rhs) { os << rhs.fi << ' ' << rhs.se; return os; }
template<class T>
istream& operator>>(istream& is, vector<T>& rhs) { for (T& elem : rhs) is >> elem; return is; }
template<class T>
ostream& operator<<(ostream& os, const vector<T>& rhs) { for (const T& elem : rhs) os << elem << ' '; os << endl; return os; }
template<class T>
void resize(T& container, int _size) { container.resize(_size); }
template<class T, typename... Size>
void resize(T& container, int _size, Size... _sizes) { container.resize(_size); for (auto& elem : container) resize(elem, _sizes...); }
/*************************************************/

ll n, m;

ll Phi(ll a) {
    ull ret = a;
    ull i = 2;
    while (i * i <= a) {
        if (!(a % i)) ret = ret / i * (i - 1);
        while (!(a % i)) a /= i;
        i++;
    }
    if (a > 1) ret = ret / a * (a - 1);

    return ret;
}

ll Pow(ll x, ll y, ll mod) { // return (x ^ y) % mod
    ll ret = 1;
    x %= mod;
    while (y) {
        if (y & 1) ret = (ret * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }

    return ret;
}

ll f(ll n, ll m) {
    if (m == 1) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2 % m;
    if (n == 3) return 9 % m;
    if (n == 4) return (1 << 18) % m;

    ll div = __gcd(n, m);
    ll tmp = f(n - 1, Phi(m));

    if (div == 1) return Pow(n, tmp, m);
    return Pow(div, Phi(m), m) * Pow(n, tmp, m) % m;
}

void Solve(void) {
    cout << f(n, m) << endl;
}

void Init(void) {
    cin >> n >> m;
}

int main(void) {
    Boost;
    Init();
    Solve();
    return 0;
}