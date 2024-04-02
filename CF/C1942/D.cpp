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
const int min_cost = INT_MIN;
vector<int> emp = {};
vector<int> zeros = {0};
int n, k; 
int a[1000][1000];
vector<int> dp[1000];

vector<int> merging(vector<int>& a, vector<int>& b, int rel, bool add, int val){
    vector<int> res;
    res.reserve(a.size()+b.size()+1);
    int i = 0, j = 0;
    
    while(i < a.size() || j < b.size()){
        int a_val = i < a.size() ? a[i] : INT_MIN;
        int b_val = j < b.size() ? b[j]+rel : INT_MIN;
        if(a_val >= b_val){
            if(add && val >= a_val){ 
                res.push_back(val);
                add = false;
            }
            res.push_back(a_val);
            i++;
        }else{
            if(add && val >= b_val){ 
                res.push_back(val);
                add = false;
            }
            res.push_back(b_val);
            j++;
        }
    }
    if(add){
        res.push_back(val);
    }
    return res;
    
}


vector<int>& get_max_paint(int i){ 
    if(i >= n){ 
        return emp;
    }
    if(dp[i].size()){
        return dp[i];
    }
    vector<int> res = {};
    for(int j = i; j < n; ++j){ 
        res = merging(res, get_max_paint(j+2), a[i][j], true, a[i][j]);
    }
    res = merging(res, get_max_paint(i+1), 0, false, 0);
    int size = res.size();
    copy(res.begin(), res.begin()+min(size, k), back_inserter(dp[i]));
    // print(dp[i]);
    return dp[i];
}

void solve(){
    // cout << "START" << endl;
    
    cin >> n >> k;
    for(int i = 0; i < n; ++i){ 
        dp[i].clear();
        for(int j = 0; j < n-i; ++j){
            cin >> a[i][i+j];
        }
    }
    vector<int> res = merging(get_max_paint(0), zeros,0, false, 0);
    int size = res.size();
    for(int i =0; i < min(k, size); ++i){
        cout << res[i] << " ";
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
