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

int n, x;
int a[100'000];

int works(int bound, int mask){ 
    int k = 0; 
    int current = 0;
    for(int i =0; i < n; i++){ 
        current ^= a[i]; 
        if( (current & (~mask) ) <=  bound){
            // cout << current << " " << i << endl;
            k++; 
            current = 0;
        }
    }
    if(current  != 0){ 
        return -1;
    }
    return k;
}



void solve(){
    cin >> n >> x;
    for(int i =0; i < n; i++){ 
        cin >> a[i];
    }
    // cout << "start " << n << " " << x << endl;
    int ans = -1; 
    int bound = 1 << 30;
    int current_mask = 0;
    for(int bound = 1 << 30; bound >= 1; bound >>= 1){ 
        // cout << bound << endl;
        if(x&bound){ 

            // current_mask|= bound;
            // cout << std::bitset<32>(current_mask) << endl;
            ans = max(ans, works(bound, current_mask));
            current_mask|= bound;
        }

    }
    cout << ans << endl;
    



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
