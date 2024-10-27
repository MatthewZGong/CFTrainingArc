#include<bits/stdc++.h>
// g++-14 -o main [file].cpp;
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
// count number of bits 
// only for int64 and int32
//__builtin_popcount 

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

ll expected_hits[2001]; 
ll registered_hits[2001];
ll dp[2001][2001];
ll match(int e, int a){ 
    int diff = abs(e-a);
    if(diff <= 15){ 
        return 7;
    }else if(diff <= 23){
        return 6;
    }else if(diff <= 43){
        return 4;
    }else if(diff <= 102){ 
        return 2;
    }
    return 0;
}

void solve(){
    int n, m; 
    cin >> n >> m;
    for(int i =0; i < n; i++){ 
        cin >> expected_hits[i];
    }
    for(int i =0 ; i < m; i++){
        cin >> registered_hits[i];
    }
    for(int i = n-1; i >= 0; i--){ 
        for(int j = m-1; j >= 0; j-- ){
            ll score = match(expected_hits[i], registered_hits[j]);
            ll res = max(score+dp[i+1][j+1], dp[i][j+1]);
            res = max(res, dp[i+1][j]);
            dp[i][j] = res;
        }
    }
    cout << dp[0][0] << endl;




}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
        solve();
    return 0;
}