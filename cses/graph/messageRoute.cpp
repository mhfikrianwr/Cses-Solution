#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define ii pair<int, int>

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, 01};
const char move[] = {'D', 'R', 'U', 'L'};
void solve()
{
    int mx = INT_MAX;
    int mn = INT_MIN;
    int n,r; cin >> n >> r;
    vector<int> adj[n + 1];
    for(int i = 0 ; i < r ; i++){
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int steps[n + 1];
    vector<bool> vis(n + 1,false);
    queue<int> entry;
    steps[1] = 0;
    entry.push(1);
    vis[1] = true;
    // BFS
    while(!entry.empty()){
        int cur = entry.front();
        entry.pop();
        for(auto x : adj[cur]){
            if(vis[x]) continue;
            entry.push(x);
            steps[x] = cur;
            vis[x] = true;
        }
    }
    if(!vis[n]) cout << "IMPOSSIBLE";
    else
    {
        vector<int> ans;
        int prev = n;
        while(prev != 0){
            ans.pb(prev);
            prev = steps[prev];
        }
        cout << ans.size() << "\n";
        reverse(ans.begin(),ans.end());
        for(auto x : ans){
            cout << x << " ";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}