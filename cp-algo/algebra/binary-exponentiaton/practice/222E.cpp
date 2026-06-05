#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9 + 7;


int main(){
  ll n,m,k;
  cin >> n >> m >> k;
  vector<vector<ll>> dp(m,vector<ll>(m,0)),mat(m,vector<ll>(m,1));
  for(int i = 0; i < k; ++i){
    string a;
    cin >> a;
    int fr,sc;
    if(a[0] >= 'a' && a[0] <= 'z'){
      fr = a[0] - 'a';
    }else{
      fr = a[0] - 'A' + 26;
    }

    if(a[1] >= 'a' && a[1] <= 'z'){
      sc = a[1]  - 'a';
    }else{
      sc = a[1] - 'A' + 26;
    }
    mat[fr][sc] = 0;
  }
  for(int i = 0; i < m; ++i){
    dp[i][i] = 1;
  }

  --n;
  while(n > 0){
    if(n & 1){
      vector<vector<ll>> tempMatriks(m,vector<ll>(m,0));
      for(int i = 0; i < m; ++i){
        for(int y = 0; y < m; ++y){
          for(int z = 0; z < m; ++z){
            tempMatriks[i][y] = (tempMatriks[i][y] + mat[i][z] * dp[z][y]) % mod;
          }
        }
      }

      for(int i = 0; i < m; ++i){
        for(int y = 0; y < m; ++y){
          dp[i][y] = tempMatriks[i][y];
        }
      }
    }

    vector<vector<ll>> tempMatriks(m,vector<ll>(m,0));
    for(int i = 0; i < m; ++i){
      for(int y = 0; y < m; ++y){
        for(int z = 0; z < m; ++z){
          tempMatriks[i][y] = (tempMatriks[i][y] + mat[i][z] * mat[z][y]) % mod;
        }
      }
    }
    for(int i = 0; i < m; i++){
      for(int y = 0; y < m; ++y){
        mat[i][y] = tempMatriks[i][y];
      }
    }
    n >>=1;
  }
  ll ans = 0;
  for(int i = 0; i < m; i++)
    for(int y = 0; y < m; ++y) ans = ans + dp[i][y] % mod;
  cout << ans % mod;
}
