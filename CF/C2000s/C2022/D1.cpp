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

bool check_same(int a, int b){ 
    cout << "? " << a << " " << b << endl;
    int ans1; 
    cin >> ans1; 
    cout << "? " << b << " " <<  a<< endl;
    int ans2; 
    cin >> ans2;
    return ans1 == ans2;
}


void solve(){
    int n; 
    cin >> n;
    int imposter_area = -1;
    for(int i = 1; i <= n - (n%2); i+= 2){ 
        if(!check_same(i, i+1)){
            imposter_area = i;
            break;
        }
    }
    if(imposter_area == -1){ 
        cout << "! " << n << endl;
    }else{ 
        if(imposter_area == 1){ 
            if (!check_same(n, imposter_area)){ 
                cout << "! " << imposter_area << endl;
            }else{ 
                cout << "! " << imposter_area+1 << endl;
            }
        }else{ 
            if (!check_same(1, imposter_area)){ 
                cout << "! " << imposter_area << endl;
            }else{ 
                cout << "! " << imposter_area+1 << endl;
            }
        }
    }



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