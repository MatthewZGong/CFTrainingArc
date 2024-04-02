#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
void print(ll v[], ll n){
    for(ll i =0 ; i < n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
void print1(ll v[], ll n){
    for(ll i =1 ; i <= n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}

template<typename T>
void print(vector<T> v){
    for(ll i =0 ; i < v.size(); ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
#pragma endregion
ll mod = 1000000007;
ll dp[21][2200000];
bool a[21][21];
int n;
ll solve(int i, int mask){ 
    // cout << mask << endl;
    if(i == n){ 
        return 1;
    }
    if(dp[i][mask] != -1){ 
        // cout << "test" << endl;
        return dp[i][mask];
    }
    int current = 1;
    int res = 0;
    for(int j =0; j < n; j++){ 
        // cout << a[i][j] << " " << (mask & current) << endl;
        if((mask & current) == 0 && a[i][j]){ 
            // cout << "hello" << endl;
            res += solve(i+1, mask | current);
            res %= mod;
        }
        current <<= 1;
    }
    return dp[i][mask] = res;
}

void solve(){

    cin >> n;   
    for(int i =0; i < n; i++){ 
        for(int j = 0; j < n; j++){ 
            cin >> a[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    // for(int i =0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    cout << solve(0, 0) % mod << endl;

}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();
    return 0;
}
