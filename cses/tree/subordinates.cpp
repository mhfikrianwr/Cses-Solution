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
ll dfs(ll cur,vector<bool> &vis, vector<vector<ll>> & adj,vector<ll> &sz){
    if(vis[cur]) return sz[cur];
    vis[cur] = true;
    for(ll a : adj[cur]){
        if(vis[a]) sz[cur] += 1 + sz[a];
        else{
            sz[cur] += 1 + dfs(a,vis,adj,sz);
        }
    }
    return sz[cur];
}
void solve() {
    ll n;
    cin >> n;
    vector<vector<ll>> adj(n + 1);
    for(int i = 2; i <= n; i++){
        ll a;
        cin >> a;
        adj[a].push_back(i);
    }
    vector<ll> sz(n + 1, 0);
    vector<bool> vis(n + 1, false);
    for(int i = 0; i < n; i++){
        if(!vis[i + 1]){
            dfs(i + 1,vis,adj,sz);
        }
        cout << sz[i + 1] << " ";
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