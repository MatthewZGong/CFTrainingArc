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
const ll MOD = 998244353;
ll res;
int n;
vector<int> adj[3'00'001];
ll dfs(int node, int parent){ 
    ll current = 1; 
    for(int child: adj[node]){ 
        if(child != parent){ 
            current *= (dfs(child, node)+1);
            current %= MOD;
        }
    }

    res += current;
    res %= MOD;
    return current % MOD;
}

void solve(){
    res = 1; 
    cin >> n; 
    for(int i =0 ; i < n-1; i++){ 
        int u,v; 
        cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    cout << res % MOD << endl;
    //clear
    for(int i = 1; i <= n; i++){ 
        adj[i].clear(); 
    }
    
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t; 
    cin >> t; 
    while(t--){
        
        solve();
    }

}
