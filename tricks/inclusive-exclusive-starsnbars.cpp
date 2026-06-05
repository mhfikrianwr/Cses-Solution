#include <bits/stdc++.h>
using namespace std;

#define ll long long


const ll mod = 1e9 + 7;

const ll maxn = 1e5;
vector<ll> inv(maxn + 1),fact(maxn + 1);

ll gcd(ll a,ll b, ll &x, ll &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll x1,y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll inverse(ll a,ll mod){
    ll x,y;
    ll g = gcd(a,mod,x,y);

    if(g != 1) return -1;

    x %= mod;
    if(x < 0) x += mod;
    return x;
}

ll comb(ll a,ll b){
    if(b < 0 || b > a) return 0;
    if(a > maxn) return 0;
    return fact[a] * 1LL * inv[b] * inv[a - b] % mod;
}
void solve() {

    // x1 + x2 + x3 .... + xn = p
    // 0 <= xi <= b
    ll n,b,p;
    cin >> n >> b >> p;
    ll ans = 0;
    for(int i = 0; i <= n; ++i){
        ll a;
        if(i & 1) a = -1;
        else a = 1;
        ll sum = 1;
        sum = (sum % mod * a % mod * comb(n,i) % mod * comb(p + n - 1 - (b + 1) * i,n - 1) % mod) % mod;
        ans = (ans + sum + mod) % mod;
    }
    cout << (ans + mod) % mod << "\n";
}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fact[0] = 1;
    for(int i = 1; i <= maxn; ++i){
        fact[i] = (i * fact[i - 1]) % mod;
    }

    inv[maxn] = inverse(fact[maxn],mod);
    for(int i = maxn-1; i >= 0; --i){
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
    solve();
    return 0;
}