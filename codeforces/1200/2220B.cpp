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
    ll n,x; cin >> n >> x;
    ll mx = -1;
    ll cnt = 0;
    vector<ll> v(n);
    for(ll i = 0 ; i < n; i++){
        cin >> v[i];
        if(i == 0){
            cnt = 1;
        }else{
            if(v[i] == v[i - 1]) ++cnt;
            else{
                mx = max(cnt,mx);
                cnt = 1;
            }
        }
    }
    mx = max(cnt,mx);
    if(mx < x) cout << "YES\n";
    else cout << "NO\n";
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