#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
void print(ll v[], ll n){
    for(ll i =0 ; i < n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
void print1(ll v[], ll n){
    for(ll i =1 ; i <= n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}

template<typename T>
void print(vector<T> v){
    for(ll i =0 ; i < v.size(); ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
#pragma endregion
ll MOD = 1000000000+7;
ll dp[3005][3005];
ll n;
string s;
ll solve(ll i, ll greater){
    if(greater < 0 || greater > n-1-i) return 0;
    if(i == n-1){
         return 1;
    }
    if(dp[i][greater] != -1){
        return dp[i][greater];
    }
    ll res = 0;
    
    if(s[i] == '<'){
        res += (solve(i+1,greater-1) % MOD);
        res += (solve(i, greater-1) % MOD);  
    }else{
        ll lesser = n-greater-(i+1);   
        res += (solve(i+1,greater) % MOD);
        res += (solve(i, greater+1) % MOD);
    }
    dp[i][greater] = res % MOD;
    return dp[i][greater];
}
void solve(){
    cin >> n >> s;
    for(ll i = 0; i < n; i++){
        for(ll j =0; j < n; j++){
            dp[i][j] = -1;
        }
    }
    ll res = 0;
    for(ll i = 1; i <=n; i++){ 
        res += solve(0, n-i) % MOD;   
    }
    cout << res % MOD << endl;
    // for(ll i = 0; i < n; i++){
    //     for(ll j =0; j < n-1; j++){
    //         cout<< dp[i][j]  << " ";
    //     }
    //     cout << endl; 
    // }
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();

}
