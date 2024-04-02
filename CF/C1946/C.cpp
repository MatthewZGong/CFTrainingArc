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
ll inv_mod_prime(ll a, ll MOD) {
  return a <= 1 ? a : MOD - (MOD/a) * inv_mod_prime(MOD % a, MOD) % MOD;
}
// void sieve(int n){ 
//     // cout << "sieved" << endl;
//     memset(lowest_divisors, 63, sizeof(lowest_divisors));
//     for(int i = 2; i <= n; ++i){ 
//         // cout << i << endl;
//         if(lowest_divisors[i] > i){ 
        
//             primes.push_back(i);
//             adj.push_back({});
//             lowest_divisors[i] = primes.size()-1;
//             for(int j = i+i; j <= A_SIZE; j+= i){ 
//                 lowest_divisors[j] = min(lowest_divisors[j], int(primes.size()-1));
//             }
//         }
//     }
//     for(int i = n; i <= A_SIZE; ++i){ 
//         if(lowest_divisors[i] > i){ 
//             lowest_divisors[i] = primes.size();
//             primes.push_back(i);
//             adj.push_back({}); 
//         }
//     }
// }
#pragma endregion

int n, k;
vector<int> adj[1'00'001];
vector<int> leaves;
void clear(){ 
    for(int i = 1; i <= n; i++){
        adj[i].clear();
    }
    leaves.clear();
}
int works(int target_size, int wiggle){ 
    // cout << "target_size: " << target_size << endl;
    int edges_left = n-1-k; 
    int total_left = n;
    vector<bool> visited(n+1, false);
    vector<int> comp_size(n+1, 1);
    vector<int> neighbors(n+1, 0);
    vector<int> cur_comp; 
    for(int i = 0; i < leaves.size(); i++){
        // visited[leaves[i]] = true;
        cur_comp.push_back(leaves[i]);
    }
    for(int i = 1; i <= n; i++){ 
        neighbors[i] = adj[i].size();
    }
    vector<int> comp_sizes;
    vector<int> next_comp;
    while(cur_comp.size() && total_left > 2){ 

        for(int i =0; i < cur_comp.size(); i++){ 
            visited[cur_comp[i]] = true;
            total_left -= 1;
            int current_size = comp_size[cur_comp[i]];
            for(int neighbor: adj[cur_comp[i]]){
                if(!visited[neighbor]){
                    neighbors[neighbor] -= 1;
                    //merge the components
                    if(edges_left == 0 ||( current_size < target_size  && comp_size[neighbor] < target_size)){
                        comp_size[neighbor] += current_size; 
                    }else{ 
                        edges_left -= 1; 
                        comp_sizes.push_back(current_size);
                    }
                    if(neighbors[neighbor] == 1){ 
                        next_comp.push_back(neighbor);
                    }
                }
            }
        }
        swap(cur_comp, next_comp);
        next_comp.clear();
    }
    // cout << "got here" << endl;
    // cout << comp_sizes.size() << endl;
    if(cur_comp.size() == 2){ 
        if(edges_left == 0){ 
            comp_sizes.push_back(comp_size[cur_comp[0]] + comp_size[cur_comp[1]]);
        }else{ 
            comp_sizes.push_back(comp_size[cur_comp[0]]);
            comp_sizes.push_back(comp_size[cur_comp[1]]);
        }
    }else if(cur_comp.size() == 1){ 
        comp_sizes.push_back(comp_size[cur_comp[0]]);
    }
    // cout << "here" << endl;
    // cout << comp_sizes.size() << endl;
    int smallest_comp = *min_element(comp_sizes.begin(), comp_sizes.end());
    // cout << smallest_comp << endl;
    return smallest_comp;


    
}
void solve(){
    cin >> n >> k; 
    for(int i = 0; i < n-1; i++){ 
        int u,v; 
        cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){ 
        if(adj[i].size() == 1){ 
            leaves.push_back(i);
        }
    }
    
    cout << works(n/(k+1), n%(k+1)) << endl;
    clear();
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
