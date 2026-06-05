#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define fr first
#define sc second
#define ii pair<int,int>

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
const char move[] = {'D','R','U','L'};

void dfs(ll cur,vector<bool> &vis,vector<vector<ll>> &adj,map<ll,ll> &mp){
    if(vis[cur]) return;
    vis[cur] = true;
    for(ll x : adj[cur]){
        if(!mp[x]) dfs(x,vis,adj,mp);
    }
}
void solve(){
    ll n,m;
    cin  >> n >> m;
    vector<vector<ll>> adj(n + 1);
    vector<bool> vis(n + 1, false);
    for(ll i = 0; i < m; ++i){
        ll a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    map<ll,ll> mp;
    for(int i = 0; i < n; i++){
        bool ans = true;
        bool dn = false;
        for(ll y = 1; y <= n; ++y){
            if(!dn && !mp[y]) {dn = true; dfs(y,vis,adj,mp);}
            if(!mp[y] && !vis[y]){
                ans = false;
                break;
            }
        }
        for(ll i = 1; i <= n; ++i) vis[i] = false;
        ll a;
        cin >> a;
        mp[a]++;
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("closing.in","r",stdin);
    //freopen("closing.out","w",stdout);


    int tc = 1;
    while (tc--) {
        solve();
    }
    return 0;
}