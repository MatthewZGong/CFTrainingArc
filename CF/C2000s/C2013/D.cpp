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

bool canMerge(ll total, int count, pair<ll,int> group){
    auto [num, ammount] = group; 
    return total/count < num;
}

void solve(){
    int n; 
    cin >> n; 
    // cout << "--------------------" << endl;
    for(int i = 0; i < n; i++){ 
        cin >> a[i];
    }
    vector<pair<ll, int>> groups; 
    for(int i = 0; i < n; i++){   
        ll total = a[i]; 
        int count = 1;
        while(groups.size() && canMerge(total, count, groups.back())){ 
            total += groups.back().first*groups.back().second;
            count += groups.back().second;
            groups.pop_back();
        }
        if(total%count == 0){ 
            groups.emplace_back(total/count, count);
        }else{ 

            groups.emplace_back(total/count, count-(total%count));
            groups.emplace_back(total/count+1, total%count);
        }

        // for(int i =0 ; i < groups.size(); i++){ 
        //     cout << groups[i].first  << " " << groups[i].second << endl;
        // }
        // cout << endl;

    }
    // cout << groups.size() << endl;
    // for(int i =0 ; i < groups.size(); i++){ 
    //     cout << groups[i].first  << " " << groups[i].second << endl;
    // }
    // cout << endl;
    cout << groups.back().first-groups.front().first << endl;
    

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
