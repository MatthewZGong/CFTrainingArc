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
struct TreeNode{ 
    TreeNode(){ 
        val = -1; 
    }
    TreeNode(int v){ 
        val = v; 
        neighbors.clear();
    }
    int val; 
    vector<pair<int,int>> neighbors; 

};
TreeNode tr[200'005];
int get_readings(int root, int ordering){ 
    TreeNode& current = tr[root]; 
    int readings = 0;
    for(auto [childern, order]: current.neighbors){
        if(order != ordering){ 
            readings = max(readings, get_readings(childern, order)+ (order < ordering));
        }
    }
    return readings;
}
int solve(){
    int n; 
    cin >> n; 
    for(int i =1; i <= n; i++){ 
        tr[i] = TreeNode(i);
    }
    for(int i =0; i < n-1; i++){ 
        int x,y; 
        cin >> x >> y; 
        tr[x].neighbors.push_back({y,i}); 
        tr[y].neighbors.push_back({x,i});
    }
    cout << get_readings(1, -1)+1 << endl;
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
