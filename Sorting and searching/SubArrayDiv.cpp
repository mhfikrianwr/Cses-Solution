#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, a; cin >> n;
    vector<long long> num(n);
    long long sum = 0, ans = 0;
    map<long long,int> pref;
    for(int i = 0; i < n; i++){
        cin >> a;
        sum += a;
        sum %= n;
        if(sum == 0) ans++;
        if(sum >= 0){
            ans += pref[sum];
            if(sum != (sum - n)) ans += pref[sum - n];
        }else {
            ans += pref[n + sum];
            ans += pref[sum];
        }
        pref[sum]++;
    }
    cout << ans;
}