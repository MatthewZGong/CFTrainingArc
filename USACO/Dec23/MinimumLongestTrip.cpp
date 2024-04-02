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
// bool visited[2'00'001];
// vector<pair<ll,ll>> adj[2'00'001];
// vector<pair<ll,ll>> reverse_adj[2'00'001];

//to, edge, length, cost 
// tuple<ll,ll,ll, ll> paths[2'00'001];

// bool cmp(tuple<ll,ll,ll, ll> a, tuple<ll,ll,ll, ll> b){
//     if(get<2>(a) == get<2>(b)){
//         // cout << get<2>(a) << endl;
//         tuple<ll,ll,ll, ll>& a1 = a; 
//         tuple<ll,ll,ll, ll>& b1 = b;
//         while(get<1>(a1) == get<1>(b1) && get<0>(a1) != get<0>(b1) && get<1>(a1) != 0){
//             a1 = paths[get<0>(a1)];
//             b1 = paths[get<0>(b1)];
//         }
//         // if(get<0>(a1) == get<0>(b1)){ 
//         //     cout << "TEST" << endl;
//         // }
//         return get<1>(a1) < get<1>(b1);
//     }
//     return get<2>(a) > get<2>(b);

// }
// tuple<ll,ll,ll, ll> dfs(int node){ 
//     if(visited[node]){
//         return paths[node];
//     }
//     tuple<ll,ll,ll, ll> best = {node, 0, 0, 0};
//     for(pair<ll,ll>& nxt: adj[node]){ 
//         tuple<ll,ll,ll, ll> child = dfs(nxt.first);
//         get<0>(child) = nxt.first;
//         get<1>(child) = nxt.second;
//         get<2>(child) += 1; 
//         get<3>(child) += nxt.second;
//         if(cmp(child, best)){ 
//             best = child;
//         }
//     }
//     // sort(children.begin(), children.end(), cmp);
//     // cout << node << endl;
//     visited[node] = true;
//     return paths[node] = best;
// }
vector<pair<ll,ll>> adj[2'00'001];
vector<pair<ll,ll>> reverse_adj[2'00'001];
tuple<ll,ll> ans[2'00'001];
void solve(){
    int N, M; 
    cin >> N >> M;
    
    for(int i =0; i < M; i++){ 
        ll a, b, l;
        cin >> a >> b >> l; 
        adj[a].push_back({b, l});
        reverse_adj[b].push_back({a, l});
    }
    //edge, prev_rank to, sum
    vector<tuple<ll,ll,ll,ll>> paths; 
    vector<tuple<ll,ll,ll,ll>> next_paths;
    for(int i = 1; i <= N; i++){ 
        if(adj[i].size() == 0){ 
            paths.push_back({0,0,i, 0});
        }
        ans[i] = {-1, -1};
    }
    sort(paths.begin(), paths.end());
    ll length = 0;
    while( paths.size())
    { 
        for(int i = 0; i < paths.size(); i++)
        { 
            auto [edge, rank,  to, sum] = paths[i];
            auto [cur_length, cur_sum] = ans[to];
            if( cur_length != length)
            {
                ans[to] = {length, sum};
                for( auto& nxt: reverse_adj[to])
                { 
                    next_paths.push_back({nxt.second, i, nxt.first, sum + nxt.second});
                }
            }
        }
        sort(next_paths.begin(), next_paths.end());
        swap(paths, next_paths);
        next_paths.clear();
        length++;
    }
    for(int i =1; i <= N; i++){ 
        cout << get<0>(ans[i]) << " " << get<1>(ans[i]) << endl;
    }
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
        
        solve();

}
