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
void solve(){
    ll n,e;
    cin >> n >> e;
    vector<vector<pair<ll,ll>>> adj(n + 1);

    for(int i = 0; i < e; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        adj[a].pb({b,c});
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    vector<ll> weight(n + 1, -1);
    weight[1] = 0;
    pq.push({0,1});
    while(!pq.empty()){
        ll cur = pq.top().sc;
        ll cur_w = pq.top().fr;
        pq.pop();
        if(cur_w > weight[cur] && weight[cur] != -1) continue;

        for(auto x : adj[cur]){
            ll node = x.fr, node_w = x.sc;

            if(weight[node] == -1 || weight[cur] + node_w < weight[node]){
                weight[node] = weight[cur] + node_w;
                pq.push({weight[node],node});
            }
        }
    }
   for(ll i = 1; i <= n; i++){
     cout << weight[i] << " ";
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}