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
    vector<ll> sz1(n + 1, 0),sz2(n + 1,0);
    vector<bool> vis1(n + 1,false),vis2(n + 1,false),ok(n + 1, false);
    vector<vector<ll>> adj(n + 1);
    sz1[1] = 0;
    for(ll i = 0; i < n - 1; i++){
        ll a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    queue<ll> q;
    q.push(1);
    ll ans = -1e9;
    vis1[1] = true;
    while(!q.empty()){
        ll cur = q.front();
        q.pop();
        for(ll x : adj[cur]){
            if(!vis1[x]){
                sz1[x] = sz1[cur] + 1;
                vis1[x] = true;
                q.push(x);
            }
        }
    }
    q.push(x);
    vis2[x] = true;
    while(!q.empty()){
        ll cur = q.front();
        q.pop();
        for(ll p : adj[cur]){
            if(!vis2[p]){
                sz2[p] = sz2[cur] + 1;
                vis2[p] = true;
                q.push(p);
            }
        }
    }
    for(ll i = 1; i <= n; i++){
        if(sz2[i] < sz1[i]) ans = max(ans,sz1[i]);
    }
    cout << ans * 2; 
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