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

ll dp[3005][3005][2];
bool solved[3005][3005][2];
ll a[3005];

ll solve(int i, int j, int player){
    if(i > j){ 
        return 0;
    }
    if(solved[i][j][player]){ 
        return dp[i][j][player];
    }
    ll res;
    if(player == 0){ 
        res = max(a[i]+solve(i+1, j, 1), a[j]+solve(i, j-1, 1));
    }else{ 
        res = min(-a[i]+solve(i+1, j, 0), -a[j]+solve(i, j-1, 0));
    }
    dp[i][j][player] = res;
    solved[i][j][player] = true; 
    return res; 

}
void solve(){
    int n; 
    cin >> n;
    for(int i =0; i <n; i++){ 
        cin >> a[i];
    }
    cout << solve(0, n-1, 0) << endl;
}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();

}
