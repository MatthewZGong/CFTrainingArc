#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long

#pragma endregion
ll dp[4005];
const ll MOD = 100007;
ll numberOfWay(int n){ 
    if(n == 0) return 1; 
    if(n == 1) return 2; 
    if(dp[n] != 0) return dp[n];
    ll res = 2*numberOfWay(n-1);
    res %= MOD;
    for(int i = n-2; i >= 0; i--){ 
        res += numberOfWay(i); 
        res %= MOD;
    }
    dp[n] = res;
    return res;
}
void solve(){
    int n; 
    cin >> n;
    n--; 
    ll res = 0;
    for(int i =2; i <= n; i++ ){ 
        ll left = 0; 
        ll right = n-i;
        for(int j = i; j <= n; j++){
            res += numberOfWay(left)*numberOfWay(right);
            res %= MOD;
            left ++; 
            right --; 
        }
    }
    cout << res << endl;
    return;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve(); 
}
