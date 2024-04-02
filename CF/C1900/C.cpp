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
   // cout << "what" << endl;
struct TreeNode{ 
    char val; 
    int left; 
    int right; 
    int parent;
    TreeNode(char v, int l, int r, int p){
        
    }
    TreeNode(){
        
    }
}; 
const int INF = 1e9;
TreeNode tree[300'001];
int solve(int root){ 
    TreeNode& node = tree[root];
    if(node.left == 0 && node.right == 0){ 
        return 0;
    }
    int res = INF;
    if(node.left != 0){ 
        res = min(res, solve(node.left)+(node.val != 'L'));
    }
    if(node.right != 0){ 
        res = min(res, solve(node.right)+(node.val != 'R'));
    }
    return res;

}
int solve(){
    int n; 
    cin >> n; 
    for(int i =1; i <= n; i++){ 
        char val; 
        cin >> val; 
        tree[i].val = val;
    }
    for(int i = 1; i <= n; i++){ 
        int left, right; 
        cin >> left >> right; 
        tree[i].left = left;
        tree[i].right = right;
    }
    cout << solve(1) << endl;
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
