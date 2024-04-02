#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
template<typename T>
void print(T v[], int n){
    for(int i =0 ; i < n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
void print1(int v[], int n){
    for(int i =1 ; i <= n; ++i){ 
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
const int NINF = -1;
ll a[2'00'001];
ll n;
ll dp[2'00'001][2];
ll solve(int i, int odd){ 
    if(i >= n) return 0; 
    if(dp[i][odd]  != -1){ 
        return dp[i][odd];
    }
    ll res;
    if(odd){ 
        res = max(a[i]+solve(i+1, 1), solve(i+1, 0));
        res = max(res, a[i]+solve(i+2,1));
        
    }else{ 
        res = max(solve(i+1,1), solve(i+1,0));
    }
    dp[i][odd] = res;
    return res;

}
int solve(){
    cin >> n; 
    // memset(dp, -1, sizeof(dp));
    for(int i =0; i <n; i++){ 
        cin >> a[i];
        dp[i][0] = -1; 
        dp[i][1] = -1;
    }
    // for(int i =0; i < n; i++){ 
    //     cout << dp[i][0] << " ";
    // }
    // cout << endl;
    // for(int i =0; i < n; i++){ 
    //     cout << dp[i][1] << " ";
    // }
    // cout << endl;
    cout << solve(0, 1) << endl;

    return 0;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t; 
    cin >> t; 
    while(t--){
        
        solve();
    }

}
