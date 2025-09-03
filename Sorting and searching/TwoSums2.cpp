#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a,target;
    cin >> n >> target;
    long long pref = 0;
    map<long long, int> prefix;
    long long ans = 0;
    for(int i = 0; i<n ; i++){
        cin >> a;
        pref += a;
        long long b = pref - target;
        if(b == 0) ans++;
        ans += prefix[b];
        prefix[pref]++;
        // cout << "------\n";
        // cout << pref << " " << prefix[pref] << endl; 
        // cout << b << " " <<prefix[b] << "\n";
    }
    cout << ans;
}