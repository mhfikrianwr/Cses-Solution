#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin >> n >> x;
    int ans = 0, sum = 0;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr,arr+n);
    int l = 0, r = n-1;
    while(l <= r){
        if(l == r){
            ans++; break;
        }
        if((arr[l] + arr[r]) > x){
            r--;
        }else{
            r--;
            l++;
        }
        ans++;
    }
    cout << ans;
}
/* 

*/