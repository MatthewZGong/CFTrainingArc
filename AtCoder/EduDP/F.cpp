#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
#pragma endregion
int dp[3005][3005];
void solve(){
    string s, t; 
    cin >> s >> t;
    dp[0][0] = (s[0] == t[0]);
    // cout << dp[0][0] << ' ';
    for(int i =1; i< t.size(); i++){ 
        dp[0][i] = max(dp[0][i-1], int(s[0] == t[i]));
        // cout << dp[0][i] << " ";
    }
    // cout << endl;
    for(int i =1; i < s.size(); i++){
        dp[i][0] = max(dp[i-1][0],int(s[i] == t[0]));
        // cout << dp[i][0] << " ";
        for(int j =1; j < t.size(); j++){ 
            dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            if(s[i] == t[j]) dp[i][j] = max(dp[i][j], 1+dp[i-1][j-1]);
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }
    string res;
    int j = t.size()-1;
    for(int i =s.size()-1; i >= 0; i--){ 
        int target = dp[i][j]; 
        for(int k = j; k >= 0; k--){ 
            if(dp[i][k] == target && s[i] == t[k]){
                res += s[i];
                j = k-1;
                break;
            }
        }
    }
    reverse(res.begin(), res.end()) ;
    cout << res << endl;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();

}
