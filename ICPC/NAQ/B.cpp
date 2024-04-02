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
#pragma endregion

int MOD = 9302023;
int sz;
char s[1000010];
pair<int,int> dp[1000010];
string nums[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
bool isNumber(int ind, int j){
    for(int i = 0; i < nums[j].size(); i++){
        if(s[i+ind] != nums[j][i]){ 
            return false;
        }
    }   
    // cout << "hi " << nums[j] << " " << ind << endl;
    return true;
}
pair<int,int> solve(int i){ 
    if(dp[i].first != -1){
        return dp[i];
    }
    if(i >= sz){ 
        dp[i] = make_pair(0,1);
        return dp[i];
    }
    // cout << i << endl;
    pair<int,int> res = solve(i+1); 
    for(int j =0; j < 10; j++){
        if(isNumber(i, j)){
            pair<int,int> current = solve(i+nums[j].size());
            if(current.first < res.first){
                res = current;
            }else if(current.first == res.first){
                res.second += current.second;
                res.second %= MOD;
            }
        }
    }
    res.first += 1;
    dp[i] = res;
    return res;
}

void solve(){
    char c; 
    sz = 0;
    while(cin >> c){ 
        s[sz] = c;
        dp[sz] = make_pair(-1,-1); 
        sz++; 
    }
    for(int i =0; i <= 9; i++){ 
        dp[sz+i] = make_pair(-1,-1);
    }
    // for(int i =0; i < sz; i++){ 
    //     cout << s[i];
    // }
    // cout << endl;
    pair<int,int> res = solve(0);
    // for(int i =0; i < sz; i++){ 
    //     cout << dp[i].first << " " << dp[i].second << endl;
    // }
    cout << res.first << "\n" << res.second % MOD << endl;

}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
        
    solve();

}
