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
int h[100005];
int dp[100005][3];
void solve(){
    int n; 
    cin >> n; 
    int a, b, c;
    cin >> a >> b >> c; 
    dp[0][0] = a; 
    dp[0][1] = b;
    dp[0][2] = c;
    for(int i = 1; i < n; i++){
        cin >> a >> b >> c; 
        dp[i][0] = a+max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = b+max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = c+max(dp[i-1][0], dp[i-1][1]);
    }
    cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2])) << endl;
    
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();

}
