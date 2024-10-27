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
struct TrieNode{ 
    TrieNode* children[26]; 
    int cnt;
    int cnt_reversed;
    TrieNode(){ 
        for(int i =0; i < 26; i++){ 
            children[i] = nullptr; 
        }
        cnt = 0;
        cnt_reversed = 0;
    }
};
ll res;
void dfs(TrieNode* root){
    for(int i = 0; i < 26;i++){ 
        TrieNode* child = root->children[i];
        if(child != nullptr && child->cnt_reversed > 0 && child->cnt > 0){
            dfs(child);
        }
    }
    res -= ((ll)root->cnt)*((ll)root->cnt_reversed)*2ll;
    return;
}
int solve(){
    ll n; 
    cin >> n; 
    TrieNode* root = new TrieNode();
    ll total = 0;
    res = 0;
    for(int i =0; i < n; i++){ 
        string s; 
        cin >> s;
        TrieNode* current = root;
        // current->cnt += 1;
        for(char c: s){ 
            if(current->children[c-'a'] == nullptr){ 
                current->children[c-'a'] = new TrieNode();
            }
            current = current->children[c-'a'];
            current->cnt += 1;
        }
        current = root;
        for(int i = s.size()-1; i >= 0; i--){
            char c = s[i];
            if(current->children[c-'a'] == nullptr){ 
                current->children[c-'a'] = new TrieNode();
            }
            current = current->children[c-'a'];
            current->cnt_reversed += 1;
        }

        total += (ll) s.size(); 
        res += (ll)s.size()*n;
    }
    res += total*n;
    // cout << res << endl;
    dfs(root);
    cout << res << endl;
    return 0;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

        
        solve();

}
