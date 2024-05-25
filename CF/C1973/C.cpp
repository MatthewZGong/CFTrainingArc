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


int p[100'000];
int q[100'000];
void solve(){
    int n; 
    cin >> n; 
    vector<pair<int,int>> evens; 
    vector<pair<int,int>> odds;
    int loc = 0;
    for(int i =0 ; i < n; ++i){ 
        cin >> p[i];
        if(p[i] == 1){ 
            loc = i;
        }
    } 

    if(loc%2 == 0){ 
        for(int i = 0; i < n-1  ; ++i){ 
            if(i%2 == 0){
                evens.push_back({p[i],i});
            }else{
                odds.push_back({p[i],i});
            }
        }
        odds.push_back({n+1,n-1});
        sort(evens.begin(), evens.end());
        sort(odds.begin(), odds.end());
        for(int i = 0; i < evens.size(); ++i){ 
            auto [num,  ind] = evens[i];
            q[ind] = n/2-i;
            auto [num2, ind2] = odds[i];
            q[ind2] = n-i;
        }

    }else{ 
        for(int i = 1; i < n; ++i){
            if(i%2 == 0){
                evens.push_back({p[i],i});
            }else{
                odds.push_back({p[i],i});
            }
        }
        evens.push_back({n+1,0});
        sort(evens.begin(), evens.end());
        sort(odds.begin(), odds.end());
        for(int i = 0; i < odds.size(); ++i){ 
            auto [num,  ind] = evens[i];
            q[ind] = n-i;
            auto [num2, ind2] = odds[i];
            q[ind2] = n/2-i;
        }
    }
    for(int i = 0; i < n; ++i){ 
        cout << q[i] << " ";
    }
    cout << endl;


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
