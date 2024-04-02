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
// template<typename T>
struct TreeNode{
    int val;
    int depth;
    vector<int> ancestors;
    vector<int> children;
    int parent;
    TreeNode(int val){
        this->val = val;
    }
    TreeNode(){
    }
};

#pragma endregion

TreeNode tree[200005];

int findBoss(int a, int b){
    if(tree[a].depth < tree[b].depth) swap(a,b);
    int diff = tree[a].depth-tree[b].depth;
    int power = 0;
    while(diff != 0){
        if(diff & 1 == 1) a = tree[a].ancestors[power];
        diff >>= 1; 
        power += 1;
    } 
    while( a != b){
        int i = 0;
        for(; i < tree[a].ancestors.size() && tree[a].ancestors[i] != tree[b].ancestors[i];  i++){}
        if(i == 0){
            return tree[a].parent;
        }
        a = tree[a].ancestors[i-1]; 
        b = tree[b].ancestors[i-1];
    }
    return a;
}
void buildAncestors(int root, vector<int>& current_ancestors, int depth){ 
    vector<int>& children = tree[root].children;
    tree[root].depth = depth; 
    for(int i = 1; i <= current_ancestors.size(); i *= 2){ 
        tree[root].ancestors.push_back(current_ancestors[current_ancestors.size()-i]);
    }
    current_ancestors.push_back(root);
    for(int child: children){ 
        buildAncestors(child, current_ancestors, depth+1);
    }
    current_ancestors.pop_back();
}
void buildAncestors(int root, int depth){
    int current = root;
    tree[root].depth = depth;
    // cout << root << endl;
    current = tree[root].parent;
    for(int i = 0; i < tree[current].ancestors.size(); i ++)
    {
        current = tree[current].ancestors[i];
        tree[root].ancestors.push_back(current);
    }
    for(int child: tree[root].children){
        buildAncestors(child, depth+1);
    }
}
void solve(){
    int n, q; 
    cin >> n >> q;
    tree[1].val = 1; 
    tree[1].parent = 1;
    for(int i =2; i <= n; i++){
        int boss; 
        cin >> boss;
        tree[boss].children.push_back(i);
        tree[i].ancestors.push_back(boss);
        tree[i].parent = boss;
        tree[i].val = i;
    }
    // cout << n << endl;
    vector<int> current_ancestors;
    buildAncestors(1,1);
    for(int i =0 ; i < q; i++){
        int a, b; 
        cin >> a >> b; 
        cout << findBoss(a,b) << endl;
    }
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();

}
