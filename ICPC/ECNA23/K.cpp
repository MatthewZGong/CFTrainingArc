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


unordered_map<string, set<pair<int,int>>> invalid;

unordered_map<string, set<pair<int,int>>> seen;

//the match, prefix suffix len
pair<string, pair<int,int>>is_match(string& a, string& b){ 
    if (a.size() != b.size()) { 
        return {"", {-1,-1}};
    }
    int different = 0;
    string difference1 = "";
    string difference2 = "";
    int match_ind = -2;
    bool concsec = false;
    for (int i =0; i < a.size(); i++) { 
        if (a[i] != b[i]) { 
            different += 1;
            if (i < a.size()-1 && a[i+1] != b[i+1]){ 
                concsec = true;
                difference1 = a.substr(i,2);
                difference2 = b.substr( i, 2);
                // cout << match << endl;
                match_ind = i;
            }
        }
    }
    if (different != 2 || !concsec) { 
        return {"", {-1,-1}};
    }
    string match = (difference1 < difference2) ? difference1+difference2 : difference2+difference1;

    return {match, {match_ind, a.size()-match_ind} };
}


void solve(){
    vector<string> words;
    int n;
    cin >> n;
    for(int i =0; i < n; i++){ 
        string cur;
        cin >> cur;
        words.push_back(cur);
    }
    int res = 0;
    for (int i =0; i < n; i++){ 
        string& a = words[i];
        for (int j = i+1; j < n; j++){
            string& b = words[j];
            auto [match, indicies] = is_match(a,b);
            // cout << a << " " << b << endl;
            if (match != ""){
               auto& match_set = seen[match];
               auto seen_before = match_set.find(indicies);
               if (seen_before != match_set.end()){ 
                auto& invalid_set = invalid[match];
                if (invalid_set.find(indicies) == invalid_set.end()){
                    --res;
                    invalid_set.insert(indicies);
                }
               }else{
                    // cout << "matched: " << match << " " << indicies.first << " " << indicies.second << endl;
                    match_set.insert(indicies);
                    ++res;
               }
            }
        }
    }
    cout << res << endl;




}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
        solve();
    return 0;
}