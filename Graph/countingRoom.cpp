#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
const string dz[] = {"D","R","U","L"};
int ans = INT_MAX;

void solve(){
    int n,m; cin >> n >> m;
    string inp[n];
    int ix = 0, iy = 0;
    pair<int,int> A,B;
    for(int i = 0; i < n; i++){
        cin >> inp[i];
        for(int y = 0; y < m; y++){
            if(inp[i][y] == 'A'){
                A = {i,y};
            }
            if(inp[i][y] == 'B'){
                B = {i,y};
            }
        }
    }
    vector<vector<int>> prev_step(n,vector<int>(m)); // step sebelum sebelum sampai ke 
    queue<pair<int,int>> pr;
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    visited[A.fr][A.sc] = true;
    pr.push(A);
    while(!pr.empty()){
        pair<int,int> cur = pr.front();
        pr.pop();
        if(cur == B) break;
        for(int i = 0; i < 4; i++){ // visit the neighbour
            pair<int,int> nb = mp(cur.fr + dx[i],cur.sc + dy[i]);
            if(nb.fr < 0 || nb.fr >= n || nb.sc < 0 || nb.sc >=m || visited[nb.fr][nb.sc] || inp[nb.fr][nb.sc] == '#'){
                continue;
            }
            visited[nb.fr][nb.sc] = true;
            pr.push(nb);
            prev_step[nb.fr][nb.sc] = i;
        }
    }
    if(visited[B.fr][B.sc]){
        cout << "YES\n";
        vector<int> steps;
        while(A != B){
            steps.pb(prev_step[B.fr][B.sc]);
            B = {B.fr - dx[prev_step[B.fr][B.sc]] ,B.sc - dy[prev_step[B.fr][B.sc]]};
        }
        reverse(steps.begin(),steps.end());
        cout << steps.size() << "\n";
        for(auto x : steps){
            cout << dz[x];
        }
        
    }else{
        cout << "NO\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
