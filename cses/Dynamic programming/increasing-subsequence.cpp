#include <bits/stdc++.h>
#define eb emplace_back
 
using namespace std;
 
int main()
{
    int N,x; cin >> N;
    vector<int> v;
    for(int i=0; i<N; i++){
         cin >> x;
         v.eb(x);
    }
    vector<int>ans;
    ans.eb(v[0]);
    for(int i=1; i<N; i++){
        if(v[i]>ans.back()){
            ans.eb(v[i]);
        }else{
            auto idx = lower_bound(ans.begin(),ans.end(),v[i]) - ans.begin();
            ans[idx] = v[i]; 
        }
    }
    cout<<ans.size();
 
    return 0;
