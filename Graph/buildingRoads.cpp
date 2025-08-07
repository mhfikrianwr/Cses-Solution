#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define ii pair<int,int>

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
const char move[] = {'D','R','U','L'};
const int mx = INT_MAX;
const int mn = INT_MIN;
void dfs(int i, vector<int> adj[],vector<bool> &visited){
    if(visited[i]) return;
    visited[i] = true;
    for(auto x : adj[i]){
        dfs(x, adj, visited);
    }
}
void solve() {
    int n,m; cin >> n >> m;
    vector<int> adj[n + 1];
    for(int i = 0; i <m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a); 
    }
    vector<bool> visited(n + 1, false);
    int ans = 0;
    vector<int> v;
    for(int i = 1; i<=n; i++){
        if(visited[i]) continue;
        else{
            dfs(i,adj,visited);
            ans++;
            v.pb(i);
        }
    }
    cout << v.size() - 1 << "\n";
    for(int i = 0; i < v.size() - 1; i++){
        cout << v[i] << " " << v[i + 1] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}