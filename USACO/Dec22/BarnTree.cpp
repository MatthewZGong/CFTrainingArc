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

int n;
ll h[2'00'001];
ll target;
vector<int> edges[2'00'001];
int children[2'00'001];
bool visited[2'00'001];


void solve(){
    cin >> n; 
    ll sum = 0;
    for(int i = 1; i <= n; i++){ 
        cin >> h[i];
        sum += h[i];
    }
    target = sum/n;
    for(int i = 0; i < n-1; i++){ 
        int u, v; 
        cin >> u >> v; 
        edges[u].push_back(v); 
        edges[v].push_back(u);
        children[u]++; 
        children[v]++;
    }
    vector<tuple<ll, ll, ll>> res_front; 
    vector<tuple<ll,ll,ll>> res_back;
    vector<int> bfs_front;
    vector<int> bfs_back;
    for(int i = 1; i <= n; i++){ 
        if(children[i] == 1){ 
            bfs_front.push_back(i);
        }
    }
    while(bfs_front.size()){
        for(int i = 0; i < bfs_front.size(); i++){ 
            int root = bfs_front[i];
            if(visited[root]) continue;

            for(int j = 0; j < edges[root].size(); j++){ 
                int parent = edges[root][j]; 
                if(!visited[parent]){ 
                    children[parent] -= 1;
                    if(children[parent] == 1){ 
                        bfs_back.push_back(parent);
                    }
                    if(h[root] < target){ 
                        ll need = target-h[root];
                        res_back.push_back({parent, root, need});
                        h[parent] -= need;
                    }else if(h[root] > target){ 
                        ll excess = h[root]-target; 
                        res_front.push_back({root, parent, excess});
                        h[parent] += excess; 
                    }
                }
            }
            visited[root] = true;
        }
        swap(bfs_front, bfs_back);
        bfs_back.clear();
    }
    cout << res_front.size() + res_back.size() << endl; 
    for(int i = 0; i < res_front.size(); i++){ 
        auto [a,b,c] = res_front[i];
        cout << a << " " << b << " " << c << endl;
    }
    for(int i = res_back.size()-1; i >= 0; i--){ 
        auto [a,b,c] = res_back[i];
        cout << a << " " << b << " " << c << endl;
    }
    


}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
   
        solve();
    

}
