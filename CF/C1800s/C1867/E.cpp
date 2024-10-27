#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
void print(int v[], int n){
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
// int[] val;
int a[200005];
int dp[200005];

void solve(){
    int n; 
    cin >> n;
    for(int i =1; i <= n;i++){ 
        cin >> a[i];
        dp[i] = n; 
    }
    int res = n;
    dp[n+1] = 0;
    for(int i = n; i >= 1; i--){ 
        if(i+a[i] <= n){ 
            dp[i] = dp[i+a[i]+1];
        }
        dp[i] = min(dp[i], dp[i+1]+1);
        res = min(res, dp[i]+i-1);
    }
    // for(int i =1; i <= n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    // for(int i =1; i <= n; i++){
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    cout << res << endl;

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
