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
int dp[100005];
void solve(){
    int n,k;
    cin >> n >> k; 
    for(int i =0; i < n; i++){
        cin >> h[i];
    }
    dp[0] = 0; 
    for(int i =1; i < n; i++){
        dp[i] = abs(h[i]-h[i-1])+dp[i-1];
        for(int j = 1; j <= min(i,k) ; j++){
            dp[i] = min(dp[i-j]+abs(h[i]-h[i-j]), dp[i]);
        }
        // cout << dp[i] << " ";

    }
    // cout << endl;
    cout << dp[n-1] << endl;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();

}
