#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
#pragma endregion
ll weights[105];
ll values[105];
ll dp[1000*105];
ll dp_next[1000*105];

void solve(){
    ll n, w; 
    cin >> n >> w;
    ll total = 0;
    for(ll i =0; i < n; i++){
        cin >> weights[i] >> values[i]; 
        total += values[i];
    }
    ll res = 0;
    for(ll i =0; i < n; i++){
        ll current_weight = weights[i]; 
        ll current_value = values[i]; 
        for(ll j =0; j < current_value; j++){ 
            dp_next[j] = dp[j];
        }
        if (dp[current_value] == 0){ 
            dp_next[current_value] = current_weight; 
        }else{ 
            dp_next[current_value] = min(current_weight, dp[current_value]);
        }
        if(dp_next[current_value] <= w) res = max(res, current_value);
        for(ll j = current_value+1; j <= total; j++){ 
            dp_next[j] = dp[j];
            if(dp[j-current_value] != 0){ 
                if(dp[j] == 0) dp_next[j] = dp[j-current_value] + current_weight;
                else dp_next[j] = min(dp[j], dp[j-current_value] + current_weight);
                
                if(dp_next[j] <= w) res = max(res, j);
            }
        }
        swap(dp,dp_next);
    }
    cout << res << endl;

}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();

}
