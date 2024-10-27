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
struct Section{ 
    int parent; 
    int value;
    int left; 
    int right; 
    ll combinations;
};
const ll MOD = 998244353;
int n;
Section parents[3'00'000]; //parents, combinations
int p[3'00'000];
int find(int i){
    if(parents[i].parent == i){
        return i;
    }
    return parents[i].parent = find(parents[i].parent);   
}
void union_find(int a, int b){
    if(b == -1  || b == n ){ 
        return; 
    }
    if(p[a] > p[b]){ 
        return; 
    }
    b = find(b);
    ll new_combs = 1;
    if(a > b){
        new_combs += parents[b].parent - parents[b].left;
    }else{ 
        new_combs += parents[b].right - parents[b].parent;
    }
    parents[a].combinations *= (parents[b].combinations+new_combs);
    parents[a].combinations %= MOD;
    parents[b].parent = a;
    parents[a].right = max(parents[a].right, parents[b].right); 
    parents[a].left = min(parents[a].left, parents[b].left);
    cout << parents[a].value << " " <<  parents[a].combinations << " " << parents[b].value  << endl;
    cout << "RANGE" << " " << parents[a].left << " " << parents[a].right << endl;
}
int solve(){
    cin >> n;
    vector<pair<int,int>> ps;
    for(int i =0; i < n; i++){ 
        cin >> p[i];
        parents[i] = {i, p[i], i,i, 1};

        ps.push_back({p[i], i});
    }
    sort(ps.begin(), ps.end());//val, indx
    for(int i = n-1; i >= 0; i--){
        union_find(ps[i].second, ps[i].second-1);
        union_find(ps[i].second, ps[i].second+1);
    }
    cout << parents[ps[0].second].combinations << endl;
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
