#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const ll mod = 1e9 + 7;
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int main(){
  ll n;
  cin >> n;
  ll panjang = binpow(2LL,n,mod);
  ll lebar = panjang * 2 - 1;
  ll sum = (panjang * lebar % mod) - binpow(3,n,mod);
  cout << panjang << "\n";
  cout << sum << "\n";
}
