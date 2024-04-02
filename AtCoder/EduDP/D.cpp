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
ll dp[100005];
ll next_dp[100005];
ll weights[105]; 
ll values[105];
void solve(){
    int n, w; 
    cin >> n >> w; 
    for(int i =0; i <n; i++){ 
        cin >> weights[i] >> values[i];
    }
    for(int i =0; i < n; i++){ 
        
        ll cw = weights[i];
        ll cv = values[i];  
        next_dp[cw] = max(dp[cw], cv);
        for(int j = 1; j < cw; j++){ 
            next_dp[j] = dp[j]; 

        }
        for(int j = cw+1; j <= w; j++){
            next_dp[j] = max(dp[j], dp[j-cw] + cv);
        }
        swap(dp,next_dp);
    }
    cout << dp[w] << endl;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();

}
