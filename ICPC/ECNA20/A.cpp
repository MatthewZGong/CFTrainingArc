#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long

#pragma endregion
struct Node{ 
    Node(string n){ 
        name = n;
    }
    string name;
    int depth;
    vector<int> parents;
    vector<int> children;
};
vector<Node> tree;
map<string, int> name_to_node; 


void make_lca(int root, int depth){
     vector<int>& parents = tree[root].parents;
    // cout << tree[root].name << endl;
    // for(int i =0; i < stack.size(); i++){ 
    //     cout << tree[stack[i]].name << " ";
    // }
    // int i = 2;
    // current = parents.size();
    if(parents.size()){
        int i =0; 
        int current = parents[0];
        while(i < tree[current].parents.size()){
            parents.push_back(tree[current].parents[i]);
            current = tree[current].parents[i];
            i++;
        }
     }
     tree[root].depth = depth;
     for(int i =0; i < tree[root].children.size(); i++){ 
        make_lca(tree[root].children[i], depth+1);
     }
     
}

void add_child(string& p, string& c){  
    int parent = -1; 
    int child = -1; 
    if(name_to_node.count(p)){ 
        parent = name_to_node[p]; 
    }else{ 
        parent = tree.size(); 
        tree.push_back(Node(p));
        name_to_node[p] = parent;
    }
    if(name_to_node.count(c)){ 
        child = name_to_node[c]; 
    }else{ 
        child = tree.size(); 
        tree.push_back(Node(c));
        name_to_node[c] = child;
    }
    tree[parent].children.push_back(child); 
    tree[child].parents.push_back(parent);
}

int find_lca(int a, int b){
    if(tree[a].depth < tree[b].depth){ 
        swap(a, b);
    }
    int diff = tree[a].depth - tree[b].depth;
    int i =0;
    while(diff){ 
        if(diff & 1){ 
            a = tree[a].parents[i];
        }
        diff >>= 1;
        i++;
    }
    // cout << tree[a].depth << " " << tree[b].depth << endl;
    while(a != b){ 
        int jump = 0;
        for(int i =0; i < tree[a].parents.size(); i++){ 
            if(tree[a].parents[i] != tree[b].parents[i]){ 
                jump = i;
            }else{ 
                break;
            }
        }
        a = tree[a].parents[jump];
        b = tree[b].parents[jump];
    }
    if(a != b){ 
        cout << "SOMETHING WENT WRONG" << endl;
    }
    return a;

}
// int find_lca(int a, int b){ 
//     if(tree[a].depth < tree[b].depth){ 
//         swap(a, b);
//     } 
//     while(tree[a].depth != tree[b].depth){ 
//         a = tree[a].parents[0];
//     }
//     while(a != b){ 
//         a = tree[a].parents[0];
//         b = tree[b].parents[0];
//     }
//     return a;

// }

void output_num(int n){ 
    cout << n;
    
    if(n%10 == 1 && n%100 != 11){ 
        cout << "st";
    }else if(n%10 == 2 && n%100 != 12){
        cout << "nd";
    }else if(n%10 == 3 && n%100 != 13){ 
        cout << "rd";
    }else{ 
        cout << "th";
    }
}

void solve(string& n1, string& n2){ 
    int a = name_to_node[n1]; 
    int b = name_to_node[n2]; 
    // cout << tree[a].name <<  " " << tree[b].name << endl;
    int lca = find_lca(a,b);
    // cout << tree[lca].name << endl;
    int m = tree[a].depth-tree[lca].depth; 
    int n = tree[b].depth - tree[lca].depth;
    // if(m > n){ 
    //     swap(m,n);
    //     swap(a,b);
    // }
    if(m == 0 || n == 0){
        if(m > n){ 
            swap(m,n);
            swap(a,b);
        } 
        cout << tree[b].name << " is the ";
        for(int i = 2; i < n; i++){ 
            cout << "great ";
        }
        if(n >= 2){ 
            cout << "grand";
        }
        cout << "child of ";
        cout << tree[a].name;
    }else if(m == n){
        cout << tree[a].name<< " and " << tree[b].name << " ";
        if(n == 1){ 
            cout << "are siblings";
        }else{ 
            cout << "are ";
            output_num(n-1);
            cout <<" cousins";
        }
    }else{ 
            if(m > n){ 
        swap(m,n);
        // swap(a,b);
    }
       cout << tree[a].name<< " and " << tree[b].name << " are ";
       output_num(m-1);
       cout << " cousins, " << (n-m) << ( (n-m) > 1 ?  " times removed" :" time removed" );

    }
    cout << endl;
}

void solve(){
    int t, p; 
    cin >> t >> p; 
    // cout << t << p;
    for(int i =0; i < t; i++){ 
        string parent; 
        cin >> parent; 
        int d; 
        cin >> d; 
        for(int j =0; j < d; j++){ 
            string child; 
            cin >> child;
            // cout << parent << " " << child << endl;
            add_child(parent, child);
        }
    }
    //find root
    int root = -1;
    for(int i = 0; i < tree.size(); i++){ 
        if(tree[i].parents.size() == 0){ 
            root = i;
        }
    }
    // cout << tree[root].name << endl;
    make_lca(root, 0);
    // for(int i = 0; i < tree.size(); i++){ 
    //     Node& root = tree[i];
    //     cout << root.name << " " << root.depth << ": "; 
    //     for(int j =0; j < root.parents.size(); j++){ 
    //         cout << tree[root.parents[j]].name << " ";
    //     }
    //     cout << endl;
    // }

    for(int i =0; i < p; i++){ 
        string a,b; 
        cin >> a >> b; 
        // cout << a << " " << b << endl; 
        solve(a,b); 
    }
    

}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    solve();

}
