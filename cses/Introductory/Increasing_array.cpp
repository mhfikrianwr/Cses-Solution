#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    long long arr[n];
    long long moves = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(i > 0){
            if(arr[i] < arr[i-1]) {
                moves += arr[i-1] - arr[i];
                arr[i] = arr[i-1];
            }
        }
    }
    cout << moves; return 0;
}