#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<int>> &adj,vector<bool> &vis,int cur,int parent,vector<int> &ans){
  vis[cur] = true;
  ans.push_back(cur);
  for(int x : adj[cur]){
    if(!vis[x]){
      if(dfs(adj,vis,x,cur,ans)) return true;
      else ans.pop_back();
    }else{
      if(x != parent){
        ans.push_back(x);
        return true;
      }
    }
  }
  return false;
}
int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  for(int i = 0; i < m; i++){
    int a,b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<bool> vis(n + 1,false);
  vector<int> ans;
  for(int i = 1; i <= n; ++i){
    if(!vis[i]){
      if(dfs(adj,vis,i,i,ans)){
        bool s = false;
        vector<int> ans2;
        for(auto x : ans){
          if(x == ans[ans.size() - 1]) s = true;
          if(s) ans2.push_back(x);
        }
        cout << ans2.size() << "\n";
        for(int x : ans2) cout << x << " ";
        return 0;
      }
    }
  }
  cout << "IMPOSSIBLE";
}
