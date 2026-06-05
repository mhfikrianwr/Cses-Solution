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
void solve(int cnt) {
    ll a,b,c;
    cin >> a >> b >> c;
    // if(cnt == 903){
    //     cout  << a << b << c << '\n';
    //     return;
    // }
    ll ans = 0;
    ans += (4 * min(a,c));
    ll val = min(a,c);
    a -= val;
    c -= val;
    ans += c * 3;
    ll x = a / 2;
    val = min(x,b);
    ans += (val * 7);
    a -= (val * 2);
    b -= val;
    if(a == 1 && b > 0){
        ans += 5;
        b--;
        a--;
    }

    if(a > 1) ans += (2 * a + 1);
    else ans += a * 3;
    ans += b * 3;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    int cnt = 1;
    while (tc--) {
        solve(cnt);
        ++cnt;
    }
    return 0;
}