#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
const char mv[4] = {'D','R','U','L'};
int main(){
  int n,m;
  cin >> n >> m;
  vector<string> s(n);
  for(string &x : s) cin >> x;
  vector<vector<int>> vis(n,vector<int>(m,0));
  vector<vector<bool>> visited(n,vector<bool>(m,false));
  vector<pair<int,int>>escape;
  vector<vector<pair<int,int>>> par(n,vector<pair<int,int>>(m));
  vector<vector<char>> ch(n,vector<char>(m));
  queue<pair<int,int>> q;
  pair<int,int> starts;
  for(int i = 0; i < n; i++){
    for(int y = 0; y < m; ++y){
      if(s[i][y] == 'M'){
        q.push({i,y});
        visited[i][y] = true;
      }else if((i == 0 || i == n - 1 || y == m - 1 || y == 0)){
        escape.push_back({i,y});
      }
      if(s[i][y] == 'A') starts = {i,y};
    }
  }
  while(!q.empty()){
    pair<int,int> cur = q.front();
    q.pop();
    for(int i = 0; i < 4; i++){
      int x = cur.first + dx[i];
      int y = cur.second + dy[i];
      if(x < 0) continue;
      if(y < 0) continue;
      if(x >= n) continue;
      if(y >= m) continue;
      if(visited[x][y]) continue;
      if(s[x][y] == '#') continue;
      vis[x][y] = 1 + vis[cur.first][cur.second];
      visited[x][y] = true;
      q.push({x,y});
    }
  }
  par[starts.first][starts.second] = {-1,-1};
  vector<vector<int>> vis2(n,vector<int>(m,0));
  vector<vector<bool>> visited2(n,vector<bool>(m,false));
  visited2[starts.first][starts.second] = true;
  q.push(starts);
  while(!q.empty()){
    pair<int,int> cur = q.front();
    q.pop();
    for(int i = 0; i < 4; ++i){
      int x = cur.first + dx[i];
      int y = cur.second + dy[i];
      if(x < 0) continue;
      if(x >= n) continue;
      if(y >= m) continue;
      if(y < 0) continue;
      if(visited2[x][y]) continue;
      if(s[x][y] == '#') continue;
      int cost = vis2[cur.first][cur.second] + 1;
      if(cost >= vis[x][y] && visited[x][y]) continue;
      vis2[x][y] = cost;
      q.push({x,y});
      visited2[x][y] = true;
      par[x][y] = {cur.first,cur.second};
      ch[x][y] = mv[i];
    }
  }
  for(auto x : escape){
    if(visited2[x.first][x.second]){
      pair<int,int> cur = {x.first,x.second};
      vector<char> ans;
      while(cur.first != -1 && cur.second != -1){
        ans.push_back(ch[cur.first][cur.second]);
        cur = par[cur.first][cur.second];
      }
      cout << "YES\n";
      cout << ans.size() - 1 << "\n";
      reverse(ans.begin(),ans.end());
      for(int i = 1; i < ans.size(); ++i) cout << ans[i];
      return 0;
    }
  }
  cout << "NO";
}
