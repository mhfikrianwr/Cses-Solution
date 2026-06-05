#include <bits/stdc++.h>
using namespace std;

#define ll long long


const ll mod = 1e9 + 7;
int main(){
  ll n,m,k;
  cin >> n >> m >> k;
  n;
  vector<vector<bool>> forb(m, vector<bool>(m, false));
  vector<ll> dp(m); 
  for(int i = 0; i < k; i++){
    string a; cin >> a;
    int fr,sc;
    if(a[0] >= 'a' && a[0] <= 'z'){
      fr = a[0] - 97;
    }else{
      fr = a[0] - 39;
    }

    if(a[1] >= 'a' && a[1] <= 'z'){
      sc = a[1] - 97;
    }else{
      sc = a[1] - 39;
    }
    forb[fr][sc] = true;
  }
  for(int i = 0; i < m; ++i) dp[i] = 1;
  long long ans = 0;
  while(n > 0){
    if(n & 1){
      for(int i = 0; i < m; ++i) {
        ans = ans + dp[i] % mod;
      };
    }
    for(int i = 0; i < m; i++){
      cout << dp[i] << " ";
    }
    cout << "\n";
    for(int i = 0; i < m; ++i){
      for(int y = 0; y < m; ++y){
        if(!forb[y][i]) dp[i] = dp[i] + dp[y] % mod;
      }
    }
    n >>= 1;
  }
  cout << ans % mod;
}
