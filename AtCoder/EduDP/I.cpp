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
double coins[3005];
double dp[3005][3005];
void solve(){
    int n; 
    cin >> n; 
    for(int i = 1; i <= n; i++){ 
        cin >> coins[i];
    }
    for(int i = 0; i <= n; i++){
        // dp[i][0] = 1;
        // dp[0][i] = 1;
    }
    dp[1][1] = coins[1];
    dp[1][0] = 1-coins[1]; 
    for(int i =2; i <= n; i++){ 
        dp[i][0] = (1-coins[i])*dp[i-1][0];
        for(int j = 1; j <= n; j++){ 
            dp[i][j] = (1-coins[i])*dp[i-1][j]+(coins[i])*dp[i-1][j-1];
        }
    }
    double res = 0; 
    for(int j = n/2+1; j <= n; j++){ 
        res += dp[n][j];
    }
    // for(int i = 0; i <= n; i++){ 
    //     for(int j = 0; j <= n; j++){ 
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << fixed << setprecision(10) << res << endl;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();

}
