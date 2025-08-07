#include <bits/stdc++.h>
using namespace std;
int main(){
    string n; cin >> n;
    int maks = -1;
    int p;
    for(int i=0; i<n.size(); i++){
        if(i==0){
            p = 1;
        }else{
            if(n[i] != n[i-1]){
                maks = max(p,maks);
                p = 1;
            }else{
                p++; 
            }
        }
    }
    maks = max(maks,p);
    cout << maks;

}