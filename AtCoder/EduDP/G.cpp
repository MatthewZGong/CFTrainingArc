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
vector<int> adj[100005];
int dp[100005];
int dfs(int node){ 
    if(dp[node] != -1){ 
        return dp[node];
    }
    dp[node] = 1;
    for(int nxt: adj[node]){ 
        dp[node] = max(dp[node], 1+dfs(nxt));
    }
    return dp[node];
}

void solve(){
    int n, m; 
    cin >> n >> m;
    for(int i =0; i < m; i++){ 
        int x, y; 
        cin >> x >> y; 
        adj[x].push_back(y);
    }
    for(int i =1; i <=n ; i++){ 

        dp[i] = -1;
    }
    int res =0;
    for(int i =1; i <= n; i++){ 
        res = max(res, dfs(i));
        // cout << dp[i] << " ";
    }
    // cout << endl; 

    cout << res-1 << endl;

    
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();

}
