#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  bool visited[n + 1];
  memset(visited,false, sizeof(visited));
  int prev[n + 1];
  memset(prev,0,sizeof(prev));

  for(int i = 0; i < m; ++i){
    int a,b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  queue<int> q;
  q.push(1);
  visited[1] = true;
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    for(int x : adj[cur]){
      if(visited[x]) continue;
      prev[x] = cur;
      visited[x] = true;
      q.push(x);
    }
  }
  vector<int> ans;
  int cur = n;
  if(prev[cur] == 0){
    cout << "IMPOSSIBLE";
    return 0;
  }
  while(cur != 0){
    ans.push_back(cur);
    cur = prev[cur];
  }
  reverse(ans.begin(),ans.end());
  cout << ans.size() << "\n";
  for(int  x : ans) cout << x << " ";
}
