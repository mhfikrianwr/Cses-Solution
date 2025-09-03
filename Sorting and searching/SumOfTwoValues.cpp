#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,target; cin >> n >> target;
    int ansa = 0,ansb = 0;
    vector<int> a(n);
    map<int,int> bisa;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(target - a[i] > 0 && bisa[target - a[i]] != 0){
            ansa = bisa[target - a[i]];
            ansb = i + 1;
        }
        bisa[a[i]] = i + 1;
    }
    if(ansa == 0 || ansb == 0){
        cout << "IMPOSSIBLE";
    }else cout << ansa << " " << ansb;
}