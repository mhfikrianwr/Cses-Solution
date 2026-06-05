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

const ll mod =  998244353;
ll mult(ll a, ll b){
    return (a % mod * 1LL * b % mod);
}

void sum(ll &a,ll b){
    a = (a + b + mod) % mod;
}

void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(auto &x : v) cin >> x;
    ll total = 0;
    for(ll b = 0; b < 30; ++b){
        ll ans = 0;
        vector<ll> cnt(2, 0);
        vector<ll> prev(2, 0);
        cnt[0] = 1; // genap
        int x = 0;
        for(int i = 0; i < n; i++){
            x ^= ((v[i] >> b) & 1);
            // if odd then currently theres an even number of set bit
            // if its even the opposite
            ll cur = mult(cnt[x ^ 1], i + 1);
            sum(ans,(cur - prev[x ^ 1] + mod) % mod);

            ++cnt[x];
            sum(prev[x], i + 1);
        }
        sum(total,(1LL << b) * ans);
    }
    cout << total << "\n";
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