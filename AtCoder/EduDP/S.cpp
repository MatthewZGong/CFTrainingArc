#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
#pragma endregion
vector<int> adj[100005];
ll dp[10005][105][10][2]; 
ll MOD = 1000000007;
int digits; 
string s; 
int d;
void solve(){
    cin >> s >> d; 
    digits = s.size(); 
    reverse(s.begin(), s.end());
    // cout << s << " " << digits << " " << d << endl;
    for(int i =0; i <= 9; i++){ 
        dp[1][0][i][0] = 1;
        dp[1][0][i][1] = 1;
    }
    ll res = 0;
    for(int i = 2; i <= digits; i++ ){
        int largest_digit;

        largest_digit = s[i-2]-'0';
        // cout << largest_digit << endl;
        for(int j =0; j < d; j++){ 
            for(int k = 0; k <= 9; k++){ 
                for(int num = 0; num <= 9; num++){ 
                    dp[i][j][k][0] += dp[i-1][(j+num)%d][num][0];
                    dp[i][j][k][0] %= MOD;

                    // if(num <= largest_digit){
                    //      dp[i][j][k][1] += dp[i-1][(j+num)%d][num][1]; 
                    //      dp[i][j][k][1] %= MOD;
                    // }
                }
            }                     
        }
        if(i != digits){
            for(int j =1; j <= 9; j++){ 
                res += dp[i][j%d][j][0];
                res %= MOD;
            }
        }
    }
    // for(int i = 0; i <= digits; i++ ){ 
    //     for(int j =0; j < d; j++){ 
    //         for(int k = 0; k <= 9; k++){ 
    //             cout << dp[i][j][k][0] << " ";
    //         }
    //         cout << " | ";
    //     }
    //     cout << endl;
    // }
    // cout << "----------------" << endl;
    // for(int i = 0; i <= digits; i++ ){ 
    //     for(int j =0; j < d; j++){ 
    //         for(int k = 0; k <= 9; k++){ 
    //             cout << dp[i][j][k][1] << " ";
    //         }
    //         cout << " | ";
    //     }
    //     cout << endl;
    // }
    int largest_digit = s[digits-1]-'0';
    // cout << largest_digit << endl;
    for(int i =1; i < largest_digit; i++){ 
        res += dp[digits][i%d][i][0];
        res %= MOD;
        // cout << dp[digits][i%d][i][0] << " ";
    }
    res += dp[digits][largest_digit%d][largest_digit][1];
    res %= MOD;
    // cout << dp[digits][largest_digit%d][largest_digit][1] << endl;

    cout << res << endl;

}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();
    return 0;
}
