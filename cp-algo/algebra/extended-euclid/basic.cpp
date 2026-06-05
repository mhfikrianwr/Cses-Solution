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

/*
extended euclid : for a number a,b with their gcd being g, we can find a number x,y
such that ax + by = g
*/

ll gcd(ll a,ll b,ll &x,ll &y){
    if(b == 0) {
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
void solve() {
    ll a = 6, b = 12;
    ll x,y;
    cout << gcd(a,b,x,y) << "\n";
    cout  << a * x + b * y << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}