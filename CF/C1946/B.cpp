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
ll MOD = 1e9 + 7;
int n, k;
ll a[2'00'001];
void solve(){
    cin >> n >> k; 
    for(int i =0; i < n; i++){ 
        cin >> a[i];
    }
    ll total_sum = 0;
    //largest continous subarray sum 
    ll curr = 0, max_sum = LLONG_MIN; 
    int best_ind = 0;
    for(int i =0; i < n; i++){
        curr += a[i];
        if(max_sum < curr) best_ind = i;
        max_sum = max(max_sum, curr);
        total_sum = (total_sum + a[i]+MOD)%MOD;
        // total_sum %= MOD;
        if(curr < 0) curr = 0;
    }
    if(max_sum < 0) max_sum = 0;
    // cout << max_sum << " " << total_sum << endl;
    total_sum += (max_sum%MOD);
    total_sum %= MOD;
    // cout << "test: "<< total_sum << endl;
    if(k == 1){ 
        if(total_sum < 0){ 
            total_sum = MOD+total_sum;
        }
        cout << total_sum << endl;
        return;
    }
    // a[best_ind] += max_sum;
    // curr = 0; max_sum = LLONG_MIN;
    // for(int i =0; i < n; i++){
    //     curr += a[i];
    //     max_sum = max(max_sum, curr);
    //     // total_sum += a[i];
    //     if(curr < 0) curr = 0;
    // }
    // cout << max_sum << " " << total_sum << endl;

    // cout << max_sum << endl;
    // max_sum %= MOD;
    // total_sum += max_sum;
    // total_sum %= MOD;
    int i = 1; 
    for(; i < k; i++){ 
        max_sum *= 2; 
        max_sum %= MOD;
        total_sum = (total_sum + max_sum+MOD)%MOD;
    }
    if(total_sum < 0){ 
        total_sum = MOD+total_sum;
    }
    cout << total_sum << endl;


}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t; 
    cin >> t; 
    while(t--){
        
        solve();
    }
    return 0;
}
