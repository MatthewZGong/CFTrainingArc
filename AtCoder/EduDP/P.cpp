#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
#pragma endregion
vector<int> adj[100005];
ll dp[100005][2];
ll mod = 1000000007;
ll solve(int root, int color, int parent){ 
    if(dp[root][color] != -1){ 
        return dp[root][color]; 
    }
    // cout << "start: " <<  root << " " << color   << endl;
    ll res = 1;
    for(int child: adj[root]){
        if(child != parent){
            ll current = 0;
            if(color){
                current += solve(child, 0, root);
                current %= mod;
            }
            current %= mod;
            current += solve(child, 1, root);
            res *= current;
            res %= mod;
        }
    }
    // cout << "end: " << root << " " << color  << " " <<  res << endl;
    return dp[root][color] = res;

}
void solve(){
    int n; 
    cin >> n; 
    memset(dp, -1, sizeof(dp));
    for(int i =0; i < n-1; i++){ 
        int x, y; 
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout << (solve(1, 0, -1) + solve(1, 1, -1))% mod << endl;
    // for(int i =1; i <= n; i++){
    //     cout << dp[i][0] << " " << dp[i][1] << endl;
    // }
}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();
    return 0;
}
