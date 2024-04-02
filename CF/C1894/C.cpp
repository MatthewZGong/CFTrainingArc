#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
template<typename T>
void print(T v[], int n){
    for(int i =0 ; i < n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
void print1(int v[], int n){
    for(int i =1 ; i <= n; ++i){ 
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


const int inf = 1'000'000'005;

int b[200'005];

vector<int> adj[200'005];

int visited[200'005];

int dfs(int node){
    if(visited[node]){ 
        return inf;
    } 
    int res =0;
    visited[node] = 1;
    for(int edge: adj[node]){ 
        res = max(res, dfs(edge)+1);
    }
    return res;
}

int solve(){
    int n, k;
    cin >> n >> k; 
    for(int i =0; i < n; i++){ 
        cin >> b[i]; 
        adj[i].clear();
    }
    for(int i =0; i < n; i++){ 
        if(b[i] <= n){ 
            int ind = ((i-(b[i]-1))+n)%n;
            int value = b[i]; 
            int next = (ind+value)%n;
            adj[next].push_back(ind);
        }
    }
    memset(visited, 0, sizeof(visited));
    int res = dfs(0); 
    if(res >= k){ 
        cout << "YES" << endl;
    }else{ 
        cout << "NO" << endl;
    }
    return 0;

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
