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
ll cnt(ll x){
    vector<ll> p = {2,3,5,7};
    ll ans = 0;
    for(ll a = 0; a < 4; ++a) ans += (x / p[a]);
    for(ll a = 0; a < 4; ++a)
        for(ll b = a + 1; b < 4; ++b) ans -= (x / (p[a] * p[b]));
    for(ll a = 0; a < 4; ++a)
        for(ll b = a + 1; b < 4; ++b)
            for(ll c = b + 1; c < 4; ++c) ans += (x / (p[a] * p[b] * p[c]));

    ans -= (x / 210);
    return ans;
}

void solve() {
    ll l,r;
    cin >> l >> r;
    cout << (r - cnt(r)) - ((l - 1) - cnt(l - 1))<< "\n";
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