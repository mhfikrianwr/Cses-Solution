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
vector<ll> getfactor(ll n){
    vector<ll> ans;
    for(ll i = 2; i * i <= n; ++i){
        if(n % i == 0){
            ans.push_back(i);
            while(n % i == 0) n/=i; 
        }
    }
    if(n > 1) ans.push_back(n);
    return ans;
}
void solve(){
    ll n,m;
    cin >> n >> m;
    ll ans = 1;
    vector<ll> v(n);
    for(auto &x : v) cin >> x;
    for(int i = 1; i < n; i++){
        if(v[i - 1] % v[i] != 0){
            cout << "0\n";
            return;
        }
    }
    for(int i = 1; i < n; i++){
        ll ways = m / v[i];
        ll x = v[i - 1] / v[i];
        vector<ll> factor = getfactor(x);
        ll sz = factor.size();
        ll total_bad = 0;
        for(ll y = 1; y < (1LL << sz); ++y){
            ll cnt = 0;
            ll sm = 1;
            for(ll q = 0; q < sz; ++q){
                if(y & (1LL << q)){
                    ++cnt;
                    sm *= factor[q];
                }
            }
            if(sm > m / v[i]) continue;
            ll bad = m / (sm * v[i]);
            if(cnt & 1) total_bad = (total_bad + bad) % mod;
            else total_bad = (total_bad - bad + mod) % mod;
        }
        ways = (ways - total_bad + mod) % mod;
        ans = (ans % mod * ways % mod) % mod;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}