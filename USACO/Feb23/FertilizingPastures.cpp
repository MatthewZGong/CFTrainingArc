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

vector<int> tree[2'00'001];
ll a[2'00'001];
ll ans = 0;
pair<ll,ll> dfs(int node){
    vector<pair<ll,ll>> childern;
    ll total_fert = a[node];
    ll total_time = 0; 
    ll tt = 0;
    for(int child: tree[node]){
        childern.push_back(dfs(child));
        tt += childern.back().second;
    }
    sort(childern.begin(), childern.end(), [&](const pair<ll,ll>& l, const pair<ll,ll>& r){
        return l.first*(tt-l.second) > r.first*(tt-r.second);
    });
    for(int i = childern.size()-1; i >= 0; i--){
        auto [fert, time] = childern[i];
        total_fert += fert;
        total_time += 1; 
        ans += fert*total_time;
        total_time += time; 
        total_time += 1;
    }
    return {total_fert, total_time};
}
void solve(){
    int N, T; 
    cin >> N >> T;
    for(int i = 2; i <= N; i++){
        int pi, ai; 
        cin >> pi >> ai;
        tree[pi].push_back(i);
        a[i] = ai;
    }
    // if(T == 0){
        pair<ll,ll> res = dfs(1);
        cout << res.second << " " << ans << endl;
    // }
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
        
    solve();

}
