#include <bits/stdc++.h>
using namespace std;
#define ll long long
void dfs(int x,int y,vector<string> &s,vector<vector<bool>> &vis,int n, int m){
  vis[x][y] = true;
  if(x  > 0 && s[x - 1][y] != '#' && !vis[x - 1][y]) dfs(x - 1,y,s,vis,n,m);
  if(x  < n - 1 && s[x + 1][y] != '#' && !vis[x + 1][y]) dfs(x + 1,y,s,vis,n,m);
  if(y  > 0 && s[x][y - 1] != '#' && !vis[x][y - 1]) dfs(x,y - 1,s,vis,n,m);
  if(y  < m - 1 && s[x][y + 1] != '#' && !vis[x][y + 1]) dfs(x,y + 1,s,vis,n,m);
}
int main(){
  ll n,m;
  cin >> n >> m;
  vector<string> s(n);
  for(auto &x : s) cin >> x;
  ll ans = 0;
  vector<vector<bool>> visited(n,vector<bool>(m,false));
  for(int i = 0; i < n; i++){
    for(int y = 0; y < m; ++y){
      if(!visited[i][y] && s[i][y] != '#'){
        ++ans;
        dfs(i,y,s,visited,n,m);
      }
    }
  }
  cout << ans << "\n";
}
