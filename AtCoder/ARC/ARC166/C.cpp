#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
template<typename T>
void print(T v[], int n, int i = 0){
    for(; i < n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
template<typename T>
void print(vector<T> v){
    for(int i =0 ; i < v.size(); ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
ll inv_mod_prime(ll a, ll MOD) {
  return a <= 1 ? a : MOD - (MOD/a) * inv_mod_prime(MOD % a, MOD) % MOD;
}
// void sieve(int n){ 
//     // cout << "sieved" << endl;
//     memset(lowest_divisors, 63, sizeof(lowest_divisors));
//     for(int i = 2; i <= n; ++i){ 
//         // cout << i << endl;
//         if(lowest_divisors[i] > i){ 
        
//             primes.push_back(i);
//             adj.push_back({});
//             lowest_divisors[i] = primes.size()-1;
//             for(int j = i+i; j <= A_SIZE; j+= i){ 
//                 lowest_divisors[j] = min(lowest_divisors[j], int(primes.size()-1));
//             }
//         }
//     }
//     for(int i = n; i <= A_SIZE; ++i){ 
//         if(lowest_divisors[i] > i){ 
//             lowest_divisors[i] = primes.size();
//             primes.push_back(i);
//             adj.push_back({}); 
//         }
//     }
// }
#pragma endregion

ll MOD = 998244353;

ll dp[2'000'005];
ll solve_diagonal(int n){

    if(n < 0) return 0; 
    if(dp[n] > 0) return dp[n]%MOD;
    if(n == 0) return 1;
    if(n == 1) return 1; 
    // cout << n << endl;
    return dp[n] = ((solve_diagonal(n-1))%MOD + (solve_diagonal(n-2))%MOD)%MOD;
}
ll dp2[1'000'001];
ll solve_axis(int n){ 
    if(n == 0) return 1;
    if(dp2[n] != 0) return dp2[n];
    return dp2[n] = (solve_diagonal(2*n)*solve_axis(n-1))%MOD;
}

void solve(){
    ll h, w;
    cin >> h >> w;
    ll res = 1;

    //width 
    res *= solve_axis(min(w, h)) %  MOD;
    res %= MOD;
    if(w-h > 0){
        ll exp = w-h;
        ll mult = solve_diagonal(2*min(w,h)+1);
        for(ll i = 1; i <= exp; i <<= 1){ 
            if(exp & i){
                res *= mult;
                res %= MOD;
            }
            mult *= mult; 
            mult %= MOD;
        }   
        
    }
    res %= MOD;

    //bottom row
    res *= solve_axis(min(h, w)) %  MOD;
    res %= MOD;
    if(h-w > 0){ 
        ll exp = h-w;
        ll mult = solve_diagonal(2*min(h,w)+1);
        for(ll i = 1; i <= exp; i <<= 1){ 
            if(exp & i){
                res *= mult; 
                res %= MOD;
            }
            mult *= mult; 
            mult %= MOD;
            
        }
    }
    res %= MOD;
    // cout << "hello" << endl;
    cout << res  << endl;
    



}



int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);    
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < 1'000'001; i += 1'000){
        // cout << i << endl;
        solve_diagonal(2*i);
        solve_axis(i);
    }
    // solve_diagonal(2'000'001);
    // solve_axis(1'000'001);
    // for(int i =0; i < 10; i++){ 
    //     cout << solve_axis(i) << endl;
    //     // cout << solve_diagonal(i) << endl;
    // }
    // memset(dp, -1, sizeof(dp));
    int t; 
    cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}
