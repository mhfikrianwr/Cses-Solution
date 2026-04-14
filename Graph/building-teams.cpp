#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<int>> &adj,vector<int> &vis, int cur, int parent){
  if(vis[parent] == 1) vis[cur] = 2;
  else vis[cur] = 1;
  for(int node : adj[cur]){
    if(vis[node] == 0){
      if(dfs(adj,vis,node,cur)) return true;
    }else{
      if(vis[node] == vis[cur]) return true; 
    }
  }
  return false;
}
int main(){
  int n,m;
  cin >> n >> m;
  vector<int> vis(n + 1);
  vector<vector<int>> adj(n + 1);
  for(int i = 0; i < m; i++){
    int a,b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for(int i = 1; i <= n; i++){
    if(vis[i] == 0){
      if(dfs(adj,vis,i,i)){
        cout << "IMPOSSIBLE";
        return 0;
      }
    }
  }
  for(int i =1; i <= n; i++) cout << vis[i] << " ";
}
