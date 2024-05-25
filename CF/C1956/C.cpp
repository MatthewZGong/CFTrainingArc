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


int a[500][500];
void solve(){
    int n; 
    cin >> n; 
    for(int i = 0; i < n; i++){ 
        for(int j = 0; j < n; j++){ 
            a[i][j] = 0;
        }
    }
    vector<pair<int,int>> res; 
    for(int i = n; i  >= 2; i--){ 
        res.push_back({1,i});
        res.push_back({2,i-1});
    }
    res.push_back({1, 1}); 
    for(auto  [k,j]: res){ 
        for(int i =0; i < n; i++){ 
            if(k == 1){ 
                a[j-1][i] = i+1;
            }else{ 
                a[i][j-1] = i+1;
            }
        }

    }
    int s = 0;
    for(int i = 0; i < n; i++){ 
        for(int j = 0; j < n; j++){ 
            s += a[i][j];
        }   
    }

    cout << s  << " " <<  res.size() << endl;
    for(int i = 0; i < res.size(); i++){ 
        cout << res[i].first << " " << res[i].second << " "; 
        for(int j = 0; j < n; j++){ 
            cout << j+1 << " ";
        }
        cout << endl;
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
