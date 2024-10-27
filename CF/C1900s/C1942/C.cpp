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
int n, x, y;
vector<int> v;
void solve(){
    cin >> n >> x >> y;
    // cout << "n " << n << " x " << x << " y " << y << endl;
    v.clear();
    for(int i =0; i < x; ++i){ 
        int a; 
        cin >> a;
        v.push_back(a);
    }
    vector<int> even_diffs; 
    vector<int> odd_diffs;
    sort(v.begin(), v.end());
    int res = v.size()-2;
    for(int i = 0; i < v.size(); ++i){
        int diff;
        if(i == v.size()-1){
            diff = v[0]+n - v[i];
        }else{
            diff = v[i+1] - v[i];
        }
        if(diff == 2) res++;
        else{ 
            if(diff%2 == 0){
                even_diffs.push_back(diff);
            }else{
                if(diff > 1) odd_diffs.push_back(diff);
            }
        }
    }
    // cout << res << endl;
    sort(even_diffs.begin(), even_diffs.end());
    sort(odd_diffs.begin(), odd_diffs.end());
    // print(even_diffs);
    // print(odd_diffs);
    for(int i = 0; i < even_diffs.size() && y > 0; ++i){ 
        int diff = even_diffs[i];
        int splits = diff/2; 
        int cost = splits-1; 
        // cout << "diff " << diff << " splits " << splits << " cost " << cost << endl;
        if(y >= cost){ 
            // cout << "I AM HERE" << endl;
            y -= cost; 
            res += splits; 
            res += cost; 
        }else{ 
            res += 2*y; 
            y = 0;
        }
    }
    for(int i = 0; i < odd_diffs.size() && y > 0; ++i){
    
        int diff = odd_diffs[i];
        int splits = (diff+1)/2; 
        int cost = splits-1; 
        if(y >= cost){ 
            y -= cost;
            res += 2*cost;
        }else{ 
            res += 2*y;
            y = 0;
        }
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
