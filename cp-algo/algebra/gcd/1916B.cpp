#include <bits/stdc++.h>
using namespace std;
int main(){
  int tc;
  cin >> tc;
  while(tc--){
    long long a,b;
    cin >> a >> b;
    long long ans = (a * b) / gcd(a,b);
    if(ans == b) cout << ans * (b / a) << "\n";
    else cout << ans << "\n";
  }
}
