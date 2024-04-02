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
int n, m, k;
int a[70][70];
int dp[70][70][70][36];

int solve(int i, int j, int r, int choose){ 
    // cout << i << " " << j << " " << r << " " << choose << endl;
    // cout << "dp: " << dp[i][j][r][choose] << endl;
    if(i == n){ 
        if(r == 0) return 0;
        return -1;
    }
    if(j == m || choose == 0){ 
        return solve(i+1, 0, r, m/2);
    }
    if(dp[i][j][r][choose] != -2){
        return dp[i][j][r][choose];
    }
    dp[i][j][r][choose] = -1;
    int c = solve(i, j+1, (r-(a[i][j]%k)+k)%k , choose-1); 
    int nc = solve(i, j+1, r, choose);
    if(c != -1){ 
        dp[i][j][r][choose] = max(dp[i][j][r][choose], c+a[i][j]);
    }
    if(nc != -1){ 
        dp[i][j][r][choose] = max(dp[i][j][r][choose], nc);
    }
    return dp[i][j][r][choose];

}
void solve(){
    cin >> n >> m >> k;
    // cout << n << m << k << endl;
    for(int i = 0; i < n; i++){ 
        for(int j = 0; j < m; j++){ 
            cin >> a[i][j];
            for(int x = 0; x < k; x++){ 
                for(int y= 0; y <= m/2; y++ ){ 
                    dp[i][j][x][y] = -2;
                }
            }
        }
    }
    cout << solve(0, 0, 0, m/2) << endl;


}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    solve();
    

}
