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

int a[200'001];

void solve(){
    int n; 
    int k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    a[0] = INT_MAX;
    int swap_pos = 1;
    for(int i =1; i < k; i++){ 
        if(a[i] > a[k]){ 
            swap_pos = i;
            break;
        }
    }
    int res = swap_pos-2;
    // cout << swap_pos << endl;
    swap(a[k], a[swap_pos]);
    // print(a, n+1,1);
    k = swap_pos;
    int wins = a[k] > a[k-1] ? 1 : 0;
    for(int i = k+1; i <= n; i++){
        if(a[k] > a[i]){
            wins ++;
        }else{ 
            break;
        }

    }
    cout << max(res, wins) << endl;
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
