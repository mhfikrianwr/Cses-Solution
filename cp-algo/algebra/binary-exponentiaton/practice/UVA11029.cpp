#include <bits/stdc++.h>
using namespace std;


#define int long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define ll long long

ll binex(ll a, ll b,ll c){
  ll result = 1;
  while(b > 0){
    if(b & 1) result = result * a % c;

    a = a * a % c;
    b>>=1;
  }
  return result;
}
void solve(){
  ll a,b;
  cin >> a >> b;
  ll trail = binex(a,b,1e3);
  double power = (double)b * log10(a);
  ll leading = pow(10,power - floor(power)) * 100.0;
  cout << leading << "..." << setw(3) << setfill('0') << trail << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);   
  int tc;
  cin >> tc;
  while(tc--) solve();
}
