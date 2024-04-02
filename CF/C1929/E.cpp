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

const int int_max = 1e9;
int n;
int k; 
vector<int> adj[1'00'001];
bool seen[1<<20];
map<pair<int, int>, int> edge_info; 
vector<int> unique_edges;


pair<int,int> edge_pair(int a, int b){ 
    return {min(a,b), max(a,b)};
}
bool dfs(int i, int parent, int source, int target){ 
    if(source == target){ 
        return true;
    }

    for(int edge: adj[source]){ 
        if(edge != parent){ 
            if(dfs(i , source, edge, target)){ 
                int& info = edge_info[edge_pair(source, edge)];
                info |= (1<<i);
                return true;
            }
        }
    }

    return false;

}


vector<vector<int>> dp_state; 

int dp(int i, int mask){ 
    if(mask == ((1<<k)-1)){ 
        return 0;
    }
    if(i == unique_edges.size()){ 
        return 20;
    }
    if(dp_state[i][mask] != int_max){ 
        return dp_state[i][mask];
    }
    
    return dp_state[i][mask] = min(dp(i+1, mask | unique_edges[i])+1, dp(i+1, mask));
}

void solve(){
    cin >> n; 
    for(int i =0; i < n-1; i++){
        int u, v; 
        cin >> u >> v; 
        adj[u].push_back(v); 
        adj[v].push_back(u); 
        edge_info[edge_pair(u,v)] = 0;
    }
    cin >> k; 
    for(int i = 0; i < k; i++){ 
        int a, b; 
        cin >> a >> b;
        dfs(i, 0, a, b);
        
    }
    //clean seen
    memset(seen, false, (1<<k)); 

    for(auto [edge, info]: edge_info){ 
        if(!seen[info]){
            dp_state.push_back(vector<int>((1 << k), int_max));
            unique_edges.push_back(info);
            seen[info] = true;
        }
    }
    cout << dp(0, 0) << endl;

    




}
void clear(){
    for(int i = 1; i <= n; i++){ 
        adj[i].clear();
    }
    edge_info.clear();
    dp_state.clear();
    unique_edges.clear();
}


int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t; 
    cin >> t; 
    while(t--){
        
        solve();
        clear();
        
    }
    return 0;
}
