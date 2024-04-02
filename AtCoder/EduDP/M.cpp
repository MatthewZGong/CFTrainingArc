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

ll dp[105][100005];
ll a[105];
ll mod = 1000000007;
void solve(){
    int n, k;
    cin >> n >> k;
    for(int i =1; i <=n; i++){ 
        cin >> a[i];
    }
    for(int i =0;  i <= a[1] && i <= k; i++){ 
        dp[1][i] = 1;
    }
    for(int i = 2; i <= n; i++){
        dp[i][0] = dp[i-1][0];
        for(int j =1; j <= k; j++){ 
            dp[i-1][j] += dp[i-1][j-1];
            dp[i-1][j] %= mod;
            dp[i][j] = dp[i-1][j] ;
            if(j > a[i]){ 
                dp[i][j] -= dp[i-1][j-a[i]-1];
                dp[i][j] %= mod;
                if(dp[ i][j] < 0) dp[i][j] += mod;
            }
        }
    }
    // for(int i =1 ; i <= n; i++){
    //     for(int j = 0; j <= k; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[n][k] % mod << endl;
}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();
    return 0;
}
