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

    
vector<int> adj[200005];
int dist[200005];
bool visited[200005];
int entrance = -1;
void get_dist(int root, int parent, int d){
    if(dist[root] != -1){
        // cout << "waht " << root  << endl;
        if(entrance == -1) entrance = root;
        return;
    }
    // cout << "He: " << root << endl;
    dist[root] = d;
    for(int child: adj[root]){
        if(child != parent){
            get_dist(child, root, d+1);
        }
    }
    return;
}

int distance_to(int target, int start){ 
    queue<pair<int, int>> bfs;
    bfs.push({start, 0});
    visited[start] = true;
    while(!bfs.empty()){
        auto [node, dist] = bfs.front();
        bfs.pop();
        if(node == target){
            return dist;
        }
        for(int child: adj[node]){
            if(!visited[child]){
                bfs.push({child, dist+1});
                visited[child] = true;
            }
        }
    }
    return -1;
}
void clear(int n){
    entrance = -1;
    for(int i =1; i <=n ;i++){ 
        
        adj[i].clear();
        visited[i] = false;
        dist[i] = -1;
    }
}

int solve(){
    int n,a,b; 
    cin >> n >> a >> b;
    clear(n);
    // cout << n << endl;
    for(int i =1; i <= n; i++){
        int x, y;
        cin >> x >> y; 
        adj[x].push_back(y); 
        adj[y].push_back(x);
    }

    if(a ==b){ 
        cout << "NO" << endl;  
        return 0;
    }
    get_dist(b, -1, 0);
    // cout << b << endl;
    // cout << entrance << " " << dist[entrance] << endl;
    if(dist[entrance] < distance_to(a, entrance)){
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
