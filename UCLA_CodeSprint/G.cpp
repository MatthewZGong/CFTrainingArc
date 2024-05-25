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

double dp[1001][1001][2]; 
double p[1001];


double expected(int i, int j, int open){ 
    if(i == -1 && j == 0){ 
        return 1;
    }
    if(i == -1 && j != 0){ 
        return 0;
    }
    if(dp[i][j][open] != -1){ 
        return dp[i][j][open];
    }   
    if(open){
        double res =  p[i-1]*(expected(i-1,j-1,1)) +(1-p[i-1]) *expected(i-1, j+1, 0) + 1; 
        res *= p[i]; 
        return dp[i][j][open] = res;
    }else{ 
        if(j == 0){ 
            double res  =  (1-p[i-1])* ( expected(i-1,0,0) ) + (1-p[i-1]) * expected(i-1,j+1, 0) 
        }else{ 
            return dp[i][j][open] = p[i-1]*expected(i-1,j-1, 1) + (1-p[i-1])*(expected(i-1,j+1,0)-1) -1;
        }
    }

    
}

void solve(){
    int n; 
    cin >> n; 
    for(int i =0; i < n; i++){ 
        cin >> p[i];
    }
    dp[0][1] = p[0];
    dp[0][0] = 1-p[0];

    for(int i = 1; i < n; i++){ 
        for(int j = 0; j <= n; j++){ 
            dp[i][j] = -1; 
        }
    }
    double res = 0; 
    for(int i = 0; i <= n; i++){ 
        res += expected(n-1,i);
    }
    cout << double(n)-res << endl;
    for(int i = 1; i < n; i++){ 
        for(int j = 0; j <= n; j++){ 
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    

}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
        
        solve();
    return 0;
}
