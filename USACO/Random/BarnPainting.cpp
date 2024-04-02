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

int MOD = 1000000007;
vector<int> adj[100005];
int colors[100005];
// int res;
ll dp[100005][4];
ll solve_subtree(int root, int parent, int color){ 
    if(dp[root][color] != -1){ 
        return dp[root][color];
    }
    // cout << root << " "  << parent << " " << color << endl;; 
    ll res = 1;
    if(colors[root] == 0  || colors[root] == color){ 
        for(int child: adj[root]){ 
            if(child != parent){
                ll current_res = 0;
                for(int i =1 ; i<= 3; i++){
                    if(i != color) current_res +=  (solve_subtree(child, root, i)*res) % MOD;
                }  
                res = current_res; 
            }
         }
         dp[root][color] = res % MOD; 
         return dp[root][color];
    }else{ 
        dp[root][color] = 0;
        return 0; 
    }
}
void solve_tree(){
    ll res = 0;
    for(int i =1 ; i <= 3; i++){ 
        res += solve_subtree(1,0,i) % MOD;
    }
    res %= MOD;
    cout << res << endl;
}
void solve(int n, int k)
{
    int a,b;
    for(int i =0; i < n-1; i++){ 
       cin >> a >> b; 
       adj[a].push_back(b); 
       adj[b].push_back(a);  
    }
    for(int i =0; i < k; i++){ 
        cin >> a >> b; 
        colors[a] = b; 
    }
    for(int i =1; i <= n; i++){ 
        for(int j = 1; j <=3; j++){ 
            dp[i][j] = -1; 
        }
    }
    solve_tree();

}
void setIO(string s) {
  ios_base::sync_with_stdio(0); 
  cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}


int main(){
    setIO("barnpainting");
    cin.tie(0);
    int n,k; 
    cin >> n >> k;     
    solve(n, k);
    // cout << 3 << "\n";
    // cin >> n;


}
