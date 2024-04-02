#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
void print(int v[], int n){
    for(int i =0 ; i < n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
#pragma endregion

int a[55];
int b[55];
int dp[55];
int n;

bool compatible(int i, int j){
    return (a[j] <= i && i <= b[j]) && (a[i] <= j && j <= b[i]);
}
int solve(int i){
    if(dp[i] !=  -1){ 
        return dp[i];
    }
    if(i > n-2){
        return 0;
    }
    int res = 0;
    if(compatible(i, i+1) && compatible(i+1, i+2) && compatible(i, i+2)){
        res = solve(i+3)+1;
    } 
    res = max(res, solve(i+1));
    return res;
}
void solve(){ 
    cin >> n; 
    for(int i =1; i <= n; i++){ 
        cin >> a[i] >> b[i];
        dp[i] = -1;
    }
    dp[n+1] = -1;
    cout << solve(1) << endl;

}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();
}
