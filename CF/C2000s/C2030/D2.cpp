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


int n, q; 
int p[2'00'001];
bool required_start[2'00'001];
string s;
set<int> visited;
int get_min_end(int ind){ 
    if(visited.find(ind) == visited.end()){ 
        visited.insert(ind);
        return max(get_min_end(p[ind]), ind);
    }
    return ind;
}
int invalid_starts;

bool process_query(int query){ 
    // int range_start = *itr;
    if (s[query] == 'R') { 
        if (s[query-1] == 'R' && s[query+1] == 'R') { 
            invalid_starts += !required_start[query+1];
        }else if (s[query-1] == 'L' && s[query+1] == 'R') { 

            invalid_starts -= !required_start[query];
            invalid_starts += !required_start[query+1];

        }else if (s[query-1] == 'L' && s[query+1] == 'L') { 
            invalid_starts -= !required_start[query];
        }
        s[query] = 'L';
    }else{ 
        s[query] = 'R';
        if (s[query-1] == 'R' && s[query+1] == 'R') { 
            invalid_starts -= !required_start[query+1];
        }else if (s[query-1] == 'L' && s[query+1] == 'R') { 
            invalid_starts -= !required_start[query+1];
            invalid_starts += !required_start[query];
        }else if (s[query-1] == 'L' && s[query+1] == 'L') { 
            invalid_starts += !required_start[query];
        }
    }
    return invalid_starts == 0;


}

void solve(){
    cin >> n >> q; 
    for(int i = 1; i <= n; i++){ 
        cin >> p[i];
    }
    cin >> s; 
    s = "R"+s;
    vector<pair<int,int>> ranges;
    visited.clear();
    for(int i =1; i <= n; i++){ 
        if (visited.find(i) == visited.end() ){ 
            int start = i; 
            int end = get_min_end(start);
            ranges.push_back({start,end});
        }
    }
    memset(required_start, 0, n+1);
    auto [start, end] = ranges[0];
    for (auto r: ranges){ 
        auto [cur_start, cur_end] = r;
        if (cur_start <= end){ 
            end = max(end, cur_end);
        }else{ 
            required_start[start] = true;
            start = cur_start;
            end = cur_end;
        }
    }
    required_start[start] = true;
    bool has_changed = false;
    invalid_starts = 0;
    for (int i = 1; i <= n; i++){ 
        if (s[i] != s[i-1]){ 
            has_changed = !has_changed;
            if(has_changed == false){ 
                invalid_starts += !required_start[i];
            }
        }
    }
    for (int i =0; i < q; i++) { 
        int query;
        cin >> query;
        if(process_query(query)){
            cout << "YES" << endl;
        }else{ 
            cout << "NO" << endl;
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