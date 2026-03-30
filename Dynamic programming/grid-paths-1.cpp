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
#define cen "\n";
 
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
const char move[] = {'D','R','U','L'};
 
const ll mod = 1e9 + 7;
void solve(){
  ll n;
  cin >> n;
  vector<string> v(n);
  for(auto &x : v) cin >> x;
  vector<vector<ll>> dp(n,vector<ll>(n, 0));
  if(v[0][0] != '*') dp[0][0] = 1;
  for(ll i = 0; i < n; i++){
    for(ll y = 0; y < n; y++){
      if(v[i][y] == '*') continue;
      ll mx1 = 1e9;
      if(i - 1 >= 0 && v[i - 1][y] != '*') dp[i][y] = (dp[i][y] + dp[i - 1][y]) % mod;
      if(y - 1 >= 0 && v[i][y - 1] != '*') dp[i][y] = (dp[i][y] + dp[i][y - 1]) % mod;
    }
  }
  cout << dp[n - 1][n - 1] % mod;
}
 
int main() {
  gg;
  int t = 1;
  
  while(t--)solve();
}