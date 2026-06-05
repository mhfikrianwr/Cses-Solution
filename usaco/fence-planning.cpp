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
void dfs(ll cur,vector<pair<ll,ll>> &v,vector<vector<ll>> &adj,vector<bool> &vis,ll &minx,ll &maxx,ll &miny,ll &maxy){
    if(vis[cur]) return;
    vis[cur] = true;
    minx = min(minx,v[cur - 1].fr);
    maxx = max(maxx,v[cur - 1].fr);
    miny = min(miny,v[cur - 1].sc);
    maxy = max(maxy,v[cur - 1].sc);
    for(ll x : adj[cur]){
        if(!vis[x]) dfs(x,v,adj,vis,minx,maxx,miny,maxy);
    }
}
void solve(){
    ll n,m;
    cin >> n >> m;
    vector<pair<ll,ll>> v;
    for(int i = 0; i < n; i++){
        ll a,b;
        cin >> a >> b;
        v.pb({a,b});
    }
    vector<vector<ll>> adj(n + 1);
    vector<bool> vis(n + 1, false);
    for(int i = 0; i < m; i++){
        ll a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    ll ans = -1;
    for(ll i = 1 ; i <= n; ++i){
        if(!vis[i]){
            ll minx = v[i - 1].fr, miny = v[i -1].sc, maxx = v[i - 1].fr, maxy = v[i - 1].sc;
            dfs(i,v,adj,vis,minx,maxx,miny,maxy);
            if(ans == -1){
                ans = 2 * (maxx - minx + maxy - miny);
            }else{
                ans = min(ans,2 * (maxx - minx + maxy - miny));
            }
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    int tc;
    tc = 1;
    while (tc--) {
        solve();
    }
    return 0;
}