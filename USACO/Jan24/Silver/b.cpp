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
int N;
int p[1'00'001];
vector<int> adj[1'00'001];
int potions[1'00'001];
int get_leaves(int root, int parent){ 
    if(adj[root].size() == 1 && root != 1){ 
        return 1;
    }
    int res = 0;
    for(int child: adj[root]){ 
        if(child != parent){ 
            res += get_leaves(child, root);
        }
    }
    return res;
}
int total_potions = 0;
int max_potions(int root, int parent){ 
    if(adj[root].size() == 1 && root != 1){ 
        if(potions[root] == 0){ 
            return 1;
        }
        total_potions++;
        return 0;
    }else{ 
        int total_paths = 0; 
        for(int child: adj[root]){
            if(child != parent){
                total_paths += max_potions(child, root);
            }
        }
        total_potions += min(potions[root], total_paths);
        return max(0, total_paths-potions[root]);
    }

}
void solve(){
    cin >> N; 
    for(int i = 1; i <= N; i++){ 
        cin >> p[i];
    }
    for(int i = 0; i < N-1; i++){ 
        int a, b; 
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int leaves = get_leaves(1, 0);
    for(int i = 1; i <= leaves; i++){ 
        potions[p[i]]++;
    }

    max_potions(1,0);
    cout << total_potions << endl;

}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
        
    solve();

}
