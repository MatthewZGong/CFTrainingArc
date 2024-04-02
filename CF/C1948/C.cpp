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

#pragma endregion

int n;
int grid[2][2'00'000];

int dp[2][2'00'000];
bool visited[2][2'00'000];

bool solve(int i, int j){
    // if(i < 0 || i > 1 || j < 0 || j >= n){ 
    //     return false;
    // }
    // cout << i  << " " << j << endl;
    if(i == 1 && j == n-1){ 
        return true;
    }
    if(dp[i][j] != 0){ 
        return dp[i][j] == 2;
    }
    if(visited[i][j]) return false;
    visited[i][j] = true;
    bool res = false;
    if(i == 0)
        res = res || solve(i+1, j+grid[i+1][j]);
    if(i == 1)
        res = res || solve(i-1, j+grid[i-1][j]);
    if(j != 0)
        res = res || solve(i, j-1+grid[i][j-1]);
    if(j != n-1)
        res = res || solve(i, j+1+grid[i][j+1]);
    if(res) dp[i][j] = 2;
    else dp[i][j] = 1;
    return res;

}

void solve(){
    cin >> n; 
    for(int i = 0; i < n; i++){ 
        char c; 
        cin >> c;
        if(c == '>'){ 
            grid[0][i] = 1;
        }else{ 
            grid[0][i] = -1;
        }
        dp[0][i] = 0;
        visited[0][i] = false;
    }
    for(int i = 0; i < n; i++){ 
        char c;
        cin >> c;
        if(c == '>'){ 
            grid[1][i] = 1;
        }else{ 
            grid[1][i] = -1;
        }
        dp[1][i] = 0;
        visited[1][i] = false;
    }
    // for(int i = 0; i < n; i++){ 
    //     cout << grid[0][i] << " ";
    // }
    // cout << endl;
    // for(int i = 0; i < n; i++){ 
    //     cout << grid[1][i] << " ";
    // }
    // cout << endl;
    if(solve(0,0)){ 
        cout << "YES" << endl; 
    }else{
        cout << "NO" << endl;
    }
    return;


    



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
