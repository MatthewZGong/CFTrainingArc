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
#pragma endregion
vector<int> primes = {1}; 
vector<int> sieve;
void get_primes(int target){ 
    for(int i = 2; i <= target; i++){
        sieve.push_back(false);
    }
    int i = 0; 
    while(i < sieve.size()){ 
        // cout << i << endl;
        if(!sieve[i]){ 
            primes.push_back(i+2); 
            for(int j = i; j < sieve.size(); j += (i+2)){ 
                sieve[j] = true;
            }
        }
        i++;
    }
}

int dp[1001][2];
bool visited[1001][2];
int solve(int n, int turn){
    // cout << n << endl;
    if(n == 0){ 
        return turn ^ 1; 
    }
    if(visited[n][turn]) return dp[n][turn]; 
    // if(n == 0){ 
    //     return turn ^ 1; 
    // }
    bool res = false;

    for(int i = 0; i < primes.size() && (n-primes[i]) >= 0; i++){ 
        // cout << "what " << n << " " << n-primes[i] << endl;
        if(solve(n-primes[i], turn^1) == turn) res = true;
    }
    visited[n][turn] = true; 
    return dp[n][turn] = res ? turn : turn^1;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    get_primes(1'000);
    print(primes);
    // cout << solve(2,0) << endl;
    for(int i = 1000; i >= 0; i--){ 
        cout << i << " : " << solve(i, 0)  << endl;
    }

    cout << primes.size() << endl;
}
