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
// map<ll,ll> dist_to_node;
bool dfs(int node, vector<vector<pair<ll,ll>>> &adj, map<ll,ll> &rel_dist, ll dist){
    for(auto [edge, rel]: adj[node]){ 

        if(rel_dist.find(edge) == rel_dist.end()){ 
            rel_dist[edge] = dist+rel;

            // if (dist_to_node.find(dist+rel) == dist_to_node.end())
            // { 
            //     dist_to_node[dist+rel] = node; 
            // }
            // else if(dist_to_node[dist+rel] != node){ 
            //     return true;
            // }else{ 
            //     continue;
            // }
            if(dfs(edge, adj, rel_dist, dist+rel)){ 
                return true;
            }


        }else{ 

            ll rd = dist+rel; 

            if(rel_dist[edge] != rd){ 
                // cout << "hi" << node << " " << edge << endl;
                return true; 
            }

        }
    }
    return false;
}

int solve(){
    int n,m; 
    cin >> n >> m; 
    vector<vector<pair<ll,ll>>> adj(n+1);
    for(int i = 0; i < m; i++){ 
        ll a, b,d; 
        cin >> a >> b >> d; 
        adj[a].push_back({b,-d});
        adj[b].push_back({a,d});
    }
    map<ll,ll> rel_dist; 
    for(int i =1; i <= n; i++ ){
        if(rel_dist.find(i) == rel_dist.end()){ 
            // dist_to_node.clear();
            rel_dist[i] = 0;
            // dist_to_node[0] = i;
            if (dfs(i, adj, rel_dist, 0)){ 
                // for(auto [node, dist]: rel_dist){ 
                //     cout << node << " " << dist << endl;
                // }
                cout << "NO" << endl;
                return 0; 
            }
        }
    }
    cout << "YES" << endl;  
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
