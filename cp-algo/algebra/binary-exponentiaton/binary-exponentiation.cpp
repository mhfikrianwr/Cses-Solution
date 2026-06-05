#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 1e9 + 7;

ll binex(ll a, ll b){
  ll res = 1;
  while(b > 0){
    if(b & 1) res = a * a  % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
int main(){
  ll a,b;
  a = 3;
  b = 201;
  cout << binex(a,b);
}


