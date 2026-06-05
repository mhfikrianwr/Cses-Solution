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
void dfs(vector<vector<ll>> &adj, vector<bool> &vis,ll cur,ll &ans,vector<ll> &gen){
    if(vis[cur]) return;
    vis[cur] = true;
    for(ll x : adj[cur]){
        if(vis[x]){
            if(gen[x] == gen[cur]) ans = false;
        }else{
            if(gen[cur] == 1){
                gen[x] = 0;
            }else{
                gen[x] = 1;
            }
            dfs(adj,vis,x,ans,gen);
        }
    }

}
void solve(int count) {
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    vector<bool> visited(n + 1,false);
    vector<ll> gen(n + 1, -1);
    for(ll i = 0; i < m; i++){
        ll a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    ll ans = true;
    for(ll i = 1; i <= n; i++){
        if(!visited[i]){
            gen[i] = 0;
            dfs(adj,visited,i,ans,gen);
        }
    }
    cout << "Scenario #" << count << ":\n";
    if(ans) cout << "No suspicious bugs found!\n";
    else cout << "Suspicious bugs found!\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    int count = 1;
    while (tc--) {
        solve(count);
        ++count;
    }
    return 0;
}