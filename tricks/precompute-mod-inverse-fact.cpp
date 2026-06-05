#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define ii pair<int,int>

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
const char move[] = {'D','R','U','L'};

ll gcd(ll a,ll b,ll &x,ll &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll x1,y1;
    ll d = gcd(b, a % b,x1, y1);

    x = y1;
    y = x1 - y1 * (a / b);

    return d;
}

ll inverse(ll a,ll mod){
    ll x,y;
    ll g = gcd(a,mod,x,y);

    if(g != 1) return -1;

    x %= mod;
    if(x < 0) x+=mod;

    return x;
}
const ll maxn = 3e5;
vector<ll> invfact(3e5 + 1, 1);
const ll mod = 1e9 + 7;
int main() {
    for(int i = 1; i <= maxn; ++i){
        invfact[i] = i * invfact[i - 1] % mod;
    }

    invfact[maxn] = inverse(invfact[maxn],mod);
    for(int i = maxn - 1; i >= 1; ++i){
        invfact[i] = invfact[i + 1] * (i + 1) % mod;
    }
}