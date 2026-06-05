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
void solve() {
    ll n;
    cin >> n;
    string x;
    cin >> x;
    ll cnt_z = 0, cnt_o = 0, cnt_f = 0;
    for(auto c : x){
        ll num = c - '0';
        if(num == 0){
            cnt_z++;
        }else if(num == 1){
            ++cnt_o;
        }else if(num <= 5){
            ++cnt_f;
        }
    }
    for(int i = n / 4; i > 0; i--){
        ll a = cnt_z, b = cnt_o, c = cnt_f;
        if(a >= i){
            a -= i;
        }else{
            b -= 2 * (i - a);
            a = 0;
        }
        if(b >= 0 && (b + a + c) >= i){
            cout << i << "\n";
            return;
        }
    }
    cout << "0\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}