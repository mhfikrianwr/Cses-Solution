#include <bits/stdc++.h>
using namespace std;


#define int long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define ll long long
ll binex(ll a,ll b, ll c){
  ll result = 1;
  while(b > 0){
    if(b & 1) result = result * a % c;

    a = a * a % c;
    b >>=1;
  }
  return result;
}

void solve(ll x,ll y,ll n){
  cout << binex(x,y,n) << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);   
  ll a,b,c;
  while(cin >> a >> b >> c){
    solve(a,b,c);
  }
}
