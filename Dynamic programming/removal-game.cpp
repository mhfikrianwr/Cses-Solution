#include <bits/stdc++.h>
using namespace std;


#define int long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

void solve(){
  int n;
  cin >> n;
  vector<int> v(n);
  for(auto &x : v) cin >> x;
  vector<vector<int>> dpa(n,vector<int>(n)),dpb(n,vector<int>(n));
  for(int i = 0;  i < n; i++){
    dpa[i][i] = v[i];
    dpb[i][i] = 0;
  }
  for(int i = 1; i < n; i++){
    for(int y = 0; y < n - i; ++y){
      // ngambil paling kiri
      if(v[y] + dpb[y + 1][y + i] > v[y + i] + dpb[y][y + i - 1]){
        dpa[y][i + y] = v[y] + dpb[y + 1][y + i];
        dpb[y][i + y] = dpa[y + 1][i + y];
      }else{
        dpa[y][i + y] = v[y + i] + dpb[y][y + i - 1];
        dpb[y][i + y] = dpa[y][y + i - 1];
      }

    }
  }
  cout << dpa[0][n - 1] << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);   
  int tc = 1;
  //cin >> tc;
  while(tc--) solve();
}
