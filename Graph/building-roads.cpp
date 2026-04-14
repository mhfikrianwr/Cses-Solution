#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &adj, int cur, vector<bool> &visited){
  if(visited[cur]) return;
  visited[cur] = true;
  for(int x : adj[cur]){
    dfs(adj,x,visited);
  }
}
int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  vector<int> ans;
  vector<bool> visited(n + 1, false);
  for(int i = 0; i < m; i++){
    int a,b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for(int i = 1; i <= n; i++){
    if(!visited[i]){
      ans.push_back(i);
      dfs(adj,i,visited);
    }
  }
  cout << (ans.size() - 1) << "\n";
  for(int i = 1; i < ans.size(); ++i) cout << ans[0] << " " << ans[i] << "\n";
    
}
