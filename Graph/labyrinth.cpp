#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m;
char s[N][N];
bool vis[N][N];
char ch[N][N];
pair<int,int> parent[N][N];

const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
const char mv[4] = {'D','R','U','L'};

int main(){
  cin >> n >> m;

  pair<int,int> start, target;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> s[i][j];
      if(s[i][j] == 'A') start = {i,j};
      if(s[i][j] == 'B') target = {i,j};
    }
  }

  queue<pair<int,int>> q;
  q.push(start);
  vis[start.first][start.second] = true;

  while(!q.empty()){
    auto cur = q.front(); q.pop();

    for(int i = 0; i < 4; i++){
      int x = cur.first + dx[i];
      int y = cur.second + dy[i];

      if(x >= 0 && y >= 0 && x < n && y < m &&
         s[x][y] != '#' && !vis[x][y]){

        vis[x][y] = true;
        ch[x][y] = mv[i];
        parent[x][y] = cur;
        q.push({x,y});
      }
    }
  }

  if(!vis[target.first][target.second]){
    cout << "NO\n";
  } else {
    cout << "YES\n";

    string ans = "";
    auto cur = target;

    while(cur != start){
      ans += ch[cur.first][cur.second];
      cur = parent[cur.first][cur.second];
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    cout << ans << "\n";
  }
}
