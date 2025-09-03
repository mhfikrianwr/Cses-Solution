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
const int dy[] = {0, 1, 0, -1};
const char move[] = {'D', 'R', 'U', 'L'};
int val[] = {1,2};
void dfs(vector<int> edge[], vector<int> &team, int i,bool &ans,int parent){
    if(team[i] != -1 || !ans){
        return;
    }

        if(team[parent] == 1){
            team[i] = 2;
        }else if(team[parent] == 2){
             team[i] = 1;
        }
        for(int x : edge[i]){
            if(x != parent && team[x] != -1 && team[x] == team[i]){
                ans = false;
                return;
            }
            dfs(edge,team,x,ans,i);
        }
    
}
void solve(){
    int mx = INT_MAX;
    int mn = INT_MIN;
    int n,k; cin >> n  >> k;
    vector<int> adj[n + 1];
    for(int i = 0; i <k; i++){
        int a,b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bool ans = true;
    vector<int> team(n + 1, -1);
    team[0] = 2;
    for(int i =1; i<=n; i++){
        if(team[i] == -1){
            dfs(adj,team,i,ans,0);
        }
    }
    if(ans){
        for(int i = 1; i<=n; i++){
            cout << team[i] << " ";
        }
    }else{ 
        cout << "IMPOSSIBLE";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}