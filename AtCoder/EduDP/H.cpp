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
ll MOD = 1000000007;
ll dp[1005][1005];
void solve(){
    int h,w; 
    cin >> h >> w; 
    char wall;
    dp[1][1] = 1;
    for(int i =1; i <= h; i++){ 
        for(int j = 1; j <= w; j++){ 
            cin >> wall; 
            if(wall != '#'){
                dp[i][j] = (dp[i][j]+dp[i-1][j] + dp[i][j-1]) % MOD;
            }
        }
    }
    cout << dp[h][w] % MOD << endl;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();

}
