#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define ii pair<int,int>

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
const char move[] = {'D','R','U','L'};
const ll mod = 998244353;
void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n),dp(n,0);
    vector<vector<ll>> factor(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        ll a = v[i];
        for(ll y = 2; y * y <= a; ++y){
            if(a % y == 0){
                factor[i].pb(y);
                while(a % y == 0) a /= y;
            }
        }
        if(a > 1) factor[i].pb(a);
    }
    vector<ll> dp_cnt(1e6 + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        ll sz = factor[i].size();
        vector<ll> ffactor;
        for(ll y = 1; y < (1LL << sz); y++){
            ll bits = 0;
            ll sum = 1;
            for(int q = 0; q < sz; ++q){
                if(y & (1LL << q)){
                    ++bits;
                    sum = sum * factor[i][q];
                }
            }
            ffactor.pb(sum);
            if(bits & 1) dp[i] = (dp[i] + dp_cnt[sum]) % mod;
            else  dp[i] = (dp[i] - dp_cnt[sum] + mod) % mod;
        }
        for(ll x : ffactor){
            dp_cnt[x] = (dp_cnt[x] + dp[i]) % mod;
        }
    }
    cout << dp[n - 1] % mod << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    while (tc--) {
        solve();
    }
    return 0;
}