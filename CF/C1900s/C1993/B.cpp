
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


ll a[2'00'000];
void solve(){
    ll n; 
    cin >> n; 
    ll odd = 0; 
    ll largest = 0;
    ll largest_odd = 0;
    for(int i =0; i < n; i++){
        cin >> a[i];
        odd += a[i]%2;
        largest = max(largest, a[i]);
        if(a[i]%2) largest_odd = max(largest_odd, a[i]);
    }
    if(odd == 0 || odd == n){ 
        cout << 0 << endl;
        return;
    }
    sort(a, a+n);
    // cout << largest << " " << odd << endl;
    for(int i = 0; i < n; i++){ 
        if(a[i] % 2 == 0){ 
            if(a[i] > largest_odd){ 
                cout << n-odd+1 << endl;
                return;
            }
            largest_odd += a[i];
        }
    }
    cout << n-odd  << endl;
    return;



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
