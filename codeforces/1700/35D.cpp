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
void solve() {
    ll n,x;
    cin >> n >> x;
    vector<ll> v(n);
    for(int i = 0; i < n; i++){
        ll a; cin >> a;
        v[i] = a * (n - i);
    }
    
    vector<ll> dp(x + 1, -1);
    ll ans = 0;
    dp[0] = 0;
    for(ll i = 0; i < n; i++){
        for(ll y = x - v[i]; y >= 0; --y){
            if(dp[y] != -1) {
                dp[y + v[i]] = max(dp[y] + 1, dp[y + v[i]]);
                ans = max(ans,dp[y + v[i]]);
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    solve();
    return 0;
}