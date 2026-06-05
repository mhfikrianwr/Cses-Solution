#include <bits/stdc++.h>
using namespace std;
int main(){
  int tc;
  cin >> tc;
  while(tc--){
    int n; string a;
    cin >> n >> a;
    int l = 0, r = 0;
    for(int i = 0; i < n; ++i){
      if(a[i] == '(') ++l;
      else ++r;
    }
    if(l != r) cout << "NO\n";
    else cout << "YES\n";
  }
}
