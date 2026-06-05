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
const ll mod = 1e9 + 7;
void solve() {
    ll n,q;
    cin >> n >> q;
    vector<ll> pref(n + 1,0),prefx(n + 1,0);
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        ll a;
        cin >> a;
        prefx[i] = (prefx[i - 1] % mod + a % mod) % mod;
        pref[i] = (pref[i - 1] % mod + (a % mod * sum % mod) % mod) % mod;
        sum = (sum + a) % mod;
    }
    for(int i = 0; i < q; i++){
        ll l,r;
        cin >> l >> r;
        ll range_sum = (prefx[r] - prefx[l - 1] + mod) % mod;
        ll minus = prefx[l - 1] * range_sum % mod;
        ll ans = (pref[r] - pref[l - 1] - minus) % mod;
        if(ans < 0) ans += mod;
        cout << ans % mod << "\n";

    }
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