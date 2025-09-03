#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, ans = 1; cin >> n;
    vector<int> v(n),dp(n,1),lis;
    cin >> v[0]; 
    lis.push_back(v[0]);
    for(int i = 1; i<n; i++){
        cin >> v[i];
        auto it = lower_bound(lis.begin(),lis.end(),v[i]) - lis.begin();
        int a = (int)it;
        int b = lis.size();
        if(a == b) lis.push_back(v[i]);
        else  lis[a] = v[i]; 
    }
    cout << lis.size();
}