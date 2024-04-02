#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
#pragma endregion
ll dp[64][51][51];
ll MOD = 1000000007;
ll dot_product(int n, int first, int row, int second, int col){ 
    ll product = 0;
    // cout << "test1" << endl;
    for(int i =0; i < n; i++){ 
        product += (dp[first][row][i] * dp[second][i][col]) % MOD;
    }
    // cout << "test2" << endl;
    return product % MOD;
    
}
void multiple(int first, int second, int target, int n){ 
    for(int i =0; i < n; i ++){ 
        for(int j =0; j < n; j++){ 
            dp[target][i][j] = dot_product(n, first, i, second, j);
        }
    }
    // cout << "hello" << endl;
}
int power(ll k, int n){
    ll power = 2; 
    ll i = 1;
    while(power <= k){ 
        multiple(i-1,i-1, i, n); 
        power <<= 1; 
        i++;
    }
    // cout << i << " " << power << endl;
    // int target = -1; 
    power = 1; 
    i = 0; 
    ll current = 62; 
    ll nxt = 63;
    for(int i =0; i < n; i++){
        dp[current][i][i] = 1;
    }
    while(power <= k){
        if( (k & power) ){ 
            multiple(current, i, nxt, n);
            swap(current, nxt);
        }
        power <<= 1;
        i++;
    }
    return current;
}
void solve(){
    int n; 
    ll k;
    cin >> n >> k;
    // cout << n << " " << k << endl;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j++){ 
            cin >> dp[0][i][j];
        } 
    }
    int target = power(k, n); 
    ll res = 0; 
    for(int i =0; i < n; i++){ 
        for(int j =0; j < n; j++){
            res += dp[target][i][j] % MOD;
        }
    }
    
    cout << res % MOD << endl;
}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();
    return 0;
}
