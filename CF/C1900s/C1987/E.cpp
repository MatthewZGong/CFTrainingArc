#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;
 
#pragma region
#define ll long long
#pragma endregion
 
int n;
vector<int> tree_graph[5001];
ll a[5001];
ll res = 0;
//height, number of free operations 
//-1 is infinity
map<ll,ll> dfs(int node, int height){ 
    if(tree_graph[node].size() == 0){ 
        return {{height, -1}};
    }
    vector<map<ll,ll>> childern_ops;
    int largest_map_index = 0;
    int largest_map_size = 0;
    ll au = 0;

    for (int child: tree_graph[node]){
        map<ll,ll> child_ops = dfs(child, height+1);
        childern_ops.push_back(std::move(child_ops));
        if(childern_ops.back().size() > largest_map_size){ 
            largest_map_size = childern_ops.back().size();
            largest_map_index = childern_ops.size()-1;
        }
        au += a[child];
    }
    //merge into the largest map
    map<ll,ll>& ops = childern_ops[largest_map_index];
    for(int i = 0; i < childern_ops.size(); i++){
        if(i != largest_map_index){
            for(auto [node_height, free_ops]: childern_ops[i]){  
                    if(ops[node_height] == -1 || free_ops == -1){ 
                        ops[node_height] = -1;
                        smallest = min(smallest, node_height+1);
                    }else{
                        ops[node_height] = ops[node_height] + free_ops;
                    }
            }
        }
    }

    ll diff = a[node]-au;
    if(diff <= 0){ 
        ops[height] = abs(diff);
        return ops;
    }else{ 
        auto iter = ops.begin();
        while(diff > 0 && iter != ops.end()){
            ll rel_height = iter->first-height;
            // cout << rel_height << " " << diff << endl;
            if(iter->second == -1){ 
                res += rel_height*diff;
                diff = 0;
            }else{ 
                if(iter->second <= diff){
                    res += rel_height*(iter->second);
                    diff -= iter->second;
                    iter->second = 0;
                }else{ 
                    res += rel_height*diff;
                    iter->second -= diff;
                    diff = 0;
                }
            }
            ++iter;
        }
    }
    // cout << "res: " << res << endl;
    return ops;
 
}
void solve(){
    cin >> n; 
    res = 0;
    for(int i = 1; i <= n; i++){ 
        cin >> a[i];
        tree_graph[i].clear();
    }
    for(int i = 2; i <= n; i++){ 
        int parent; 
        cin >> parent;
        tree_graph[parent].push_back(i);
    }
    dfs(1, 0);
    cout << res << endl;
}
 
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t; 
    cin >> t; 
    while(t--){
        
        solve();
    }
    return 0;
}