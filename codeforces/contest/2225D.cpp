#include <bits/stdc++.h>
using namespace std;

#define gg ios::sync_with_stdio(false); cin.tie(nullptr);

// output pair with cout 
// usage example cout << p; with p as a pair
template<typename A, typename B>
ostream& operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')';
}

// print container 
template<typename T_container,
         typename T = typename enable_if<
             !is_same<T_container, string>::value,
             typename T_container::value_type
         >::type>
ostream& operator<<(ostream &os, const T_container &v) {
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}

// debug printing 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}

// debug macro, enable the local to use
//#define LOCAL
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

// dtypes
#define ll long long
#define ld long double

// vectors
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vl> 
#define vpl vector<pair<ll, ll>>
#define pb push_back
#define fr first
#define sc second

// maps
#define ml map<ll,ll>
#define mc map<char,ll>

// sort
#define ALL(x) x.begin(), x.end()
#define SORT(x) sort(ALL(x));
#define RSORT(x) sort(x.rbegin(),x.rend());

// edges
const ll INF = LLONG_MAX;
const ll NINF = LLONG_MIN;

// output
#define endl "\n"
#define en "\n"
#define cen cout << "\n"

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
const char move[] = {'D','R','U','L'};

const ll mod = 998244353;
ll mul_mod(ll a, ll b) {
    return (ll)((__int128)a * b % mod);
}

void solve() {
    ll n, x;
    cin >> n >> x;

    ll ans = 0;

    if (x == 1) {
        ans = (((n - 1LL) / 2LL) + 1LL) / 2LL % mod;
    }
    else if (x == n) {
        if (x & 1LL) ans = ((x / 2LL + 1LL) / 2LL) % mod;
        else ans = 0;
    }
    else if (x & 1LL) {
        ll l = x / 2LL;
        ll r = (n - x) / 2LL;

        ll l_gen = l / 2LL;
        ll l_gan = l - l_gen;
        ll r_gen = r / 2LL;
        ll r_gan = r - r_gen;
        if (l & 1LL) ++l_gen;
        else ++l_gan;
        ans = (
            mul_mod(l_gen % mod, r_gen % mod) +
            mul_mod(l_gan % mod, r_gan % mod) +
            (l_gen % mod)
        ) % mod;
    }
    else {
        ll l = (x - 1LL) / 2LL;
        ll r = (n - x + 1LL) / 2LL;

        ll l_gen = l / 2LL;
        ll l_gan = l - l_gen;
        ll r_gen = r / 2LL;
        ll r_gan = r - r_gen;

        if (l & 1LL) ++l_gen;
        else ++l_gan;

        ans = (
            mul_mod(l_gen % mod, r_gen % mod) +
            mul_mod(l_gan % mod, r_gan % mod) +
            (r_gen % mod)
        ) % mod;
    }

    cout << ans << '\n';
}

int main() {
  gg;
  int t = 1;
  cin>>t;
  while(t--)solve();
}
