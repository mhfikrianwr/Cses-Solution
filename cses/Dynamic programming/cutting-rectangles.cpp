#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll a,b;
  cin >> a >> b;
  vector<vector<ll>> dp(a + 1, vector<ll> (b + 1, 1e9));
  for(ll i = 1; i <= a; ++i){
    for(ll y = 1; y <= b; ++y){
      if(i == y){
        dp[i][y] = 0; continue;
      }
      for(int x = 1; x < i; ++x){
        dp[i][y] = min(dp[i][y],(1 + dp[x][y] + dp[i - x][y]));
      }

      for(int x = 1; x < y; ++x){
        dp[i][y] = min(dp[i][y],(1 + dp[i][x] + dp[i][y - x]));
      }
    }
  }
  cout << dp[a][b];
}
