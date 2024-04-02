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
ll a[405];
ll asum[405];
ll dp[405][405];
ll solve(int start, int end){ 
    if(dp[start][end] != -1){ 
        return dp[start][end];
    }
    if(start >= end){ 
        return 0;
    }
    ll sum = asum[end] - asum[start-1];
    ll res = sum + solve(start,start) + solve(start+1, end);
    for(int i = start+1; i < end; i++){
        ll left = solve(start, i);
        ll right = solve(i+1, end);
        res = min(res, left + right+sum);
    } 
    // cout << res << endl; 
    return dp[start][end] = res;

}
void solve(){
    int n; 
    cin >> n; 
    for(int i = 1; i <= n; i++){ 
        cin >> a[i];
    }
    partial_sum(a, a+n+1, asum);
    // print(asum, n+1);

    for(int i =0 ; i <= n; i++){ 
        for(int j =0; j <= n; j++){ 
            dp[i][j] = -1;
        }
    }
    cout << solve(1, n) << endl;

    // for(int i =0 ; i <= n; i++){ 
    //     for(int j =0; j <= n; j++){ 
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();
    return 0;
}
