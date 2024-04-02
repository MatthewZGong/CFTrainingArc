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

ll coins[] = {1,3,6,10,15};
ll dp[30];

ll solve(ll n){ 
    if(n == 0){ 
        return 0;
    }
    if(dp[n] != -1){ 
        return dp[n];
    }
    ll res = 1e18;
    for(int i = 0; i < 5; i++){ 
        if(n-coins[i] >= 0){ 
            res = min(res, 1+solve(n-coins[i]));

        }
    }
    return dp[n] = res;
    

}
void solve(){
    int n;
    cin >> n;
    ll res = 1e18;
    for(int i = 0; i <= min(n,29); i++){ 
        if((n-i)%15 == 0){
            // cout << i << endl;
            res = min(res, (n-i)/15+solve(i));
        }
    }
    cout << res << endl;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t; 
    cin >> t; 
    for(int i = 0; i < 30; i++){ 
        dp[i] = -1;
    }
    // cout <<solve(23)+(98-23)/15 << endl;
    while(t--){
        
        solve();
    }
    return 0;
}
