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
// int[] val;
int f[200005];
bool marked[200005];
vector<int> children_dist[200005];
vector<int> adj[200005];
const int INF = -200005;

int solve1(int root, int parent){
    int res = INF;
    if(marked[root]){
        res = 0;
    }
    children_dist[root].clear();
    // cout << "testing" << endl;
    for(int i =0; i < adj[root].size(); i++){
        int child = adj[root][i];
        if(child != parent){
            int current = solve1(child, root)+1;
            children_dist[root].push_back(current);
            res = max(res, current);
        }
    }
    return f[root] = res;
}
void solve2(int root, int parent, int parent_val){
    int child_s = children_dist[root].size();
    vector<int> left(child_s+2, INF);
    vector<int> right(child_s+2, INF);
    // cout << "root: " << root << " " << f[root] << " " << parent_val+1 << endl;
    for(int i =0; i < children_dist[root].size(); i++){
        int rel_ind = i+1;
        int child_l = children_dist[root][i];
        left[rel_ind] = child_l;
        left[rel_ind] = max(left[rel_ind-1], child_l); 
    }
    for(int i = child_s-1; i >= 0; i--){
        int rel_ind = i+1;
        int child_r = children_dist[root][i];
        right[rel_ind] = child_r;
        right[rel_ind] = max(right[rel_ind+1], child_r);
    }
    // for(int i =0; i < children_dist[root].size(); i++){ 
    //     cout << children_dist[root][i] << " ";
    // }
    // cout << endl;
    // for(int i =0; i < left.size(); i++){ 
    //     cout << left[i] << " ";
    // }
    // cout << endl;
    // for(int i =0; i < right.size(); i++){
    //     cout << right[i] << " ";
    // }
    // cout << endl;
    f[root] = max(f[root], parent_val+1);
    if(parent_val+1 >= f[root]){ 
        f[root] = parent_val+1;
        for(int i =0; i < adj[root].size(); i++){
            int child = adj[root][i];
            if(child != parent){
                solve2(child, root, parent_val+1);
            }
        }
    }else{
        for(int i =1; i <= adj[root].size(); i++){
            int child = adj[root][i-1];
            if(child != parent){
                solve2(child, root, max(0,max(left[i-1], right[i+1])));
            }
        }
    }
}
void solve(){
    int n, k; 
    cin >> n >> k;
    memset(marked, false, marked+n+1-marked);
    // cout << "hello" << endl;
    for(int i =1; i <= n; i++){
        if(adj[i].size()) adj[i].clear();
    }
    for(int i =0; i <k; i++){ 
        int a;
        cin >> a; 
        marked[a] = true;
    }
    for(int i =0; i < n-1; i++){ 
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    // for(int i =1 ;)
    // cout << "got here 1" <<endl;
    solve1(1, -1);
    for(int i =1; i < n+1; i++){
        cout << f[i] << " ";
    }
    cout << endl;
    solve2(1,-1, INF);
    for(int i =1; i < n+1; i++){
        cout << f[i] << " ";
    }
    cout << endl;
    cout << *min_element(f+1, f+n+1) << endl;
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
