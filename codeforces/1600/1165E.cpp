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
void solve(){
    ll n;
    cin >> n;
    vector<ll> b(n),a(n);
    for(int i = 0; i < n; i++){
        ll v;
        cin >> v;
        ll val = v * (i + 1) * (n - i);
        a[i] = val;
    }
    for(auto &x : b) cin >> x;
    sort(b.rbegin(),b.rend());
    sort(a.begin(),a.end());
    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum = (sum + ((a[i] % mod) * (b[i] % mod) % mod)) % mod;
    }
    cout << sum << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1; 
    //cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}