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

ll h[100'001];
ll t[100'001];
void solve(){
    int n; 
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    t[n] = 0; 
    h[n] = 0;
    ll res = 0;
    for(int i = n-1; i >= 0; i--){
        if(h[i] > h[i+1]){ 
            if(h[i] > t[i+1]){
                t[i] = h[i];
            }else{ 
                t[i] = t[i+1]+1;
            }
        }else{ 

            ll wait = t[i+1]-h[i+1]; 
            ll diff = h[i+1]-h[i];
            t[i] = wait+diff+1+h[i];
            if(h[i] == 0){ 
                t[i] = 0;
            }
        }
        res = max(res, t[i]);
    }
    cout << res << endl;

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
