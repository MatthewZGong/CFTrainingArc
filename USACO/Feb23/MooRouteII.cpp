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
int n, m; 
struct Airport{ 
    vector<tuple<int,int, int >> adj; 
    int a; 
    vector<tuple<int, int, int>>::iterator visited;
    int earliest; 

};
const int INF = 2e9+1;
Airport airports[200001];
void dfs(int airport, int arrival){ 
    if(airports[airport].earliest < arrival){ 
        return;
    }
    airports[airport].earliest = min(airports[airport].earliest, arrival);
    auto start = lower_bound(airports[airport].adj.begin(), airports[airport].adj.end(), arrival + airports[airport].a, 
    [](auto a, int b){
        return get<0>(a) < b;
    });
    auto end = airports[airport].visited;
    airports[airport].visited = start;
    for(auto i = start; i != end; ++i){ 
        dfs(get<1>((*i)), get<2>((*i)));
    }
    return;
}
void solve(){
    cin >> n >> m;
    for(int i =0; i < m; i++){
        int c, r, d, s; 
        cin >> c >> r >> d >> s;
        airports[c].adj.push_back({r, d, s});
    }
    for(int i = 1; i <= n; i++){
        cin >> airports[i].a;
        sort(airports[i].adj.begin(), airports[i].adj.end());
        airports[i].visited = airports[i].adj.end();
        airports[i].earliest = INF;
    }   
    dfs(1, -airports[1].a);
    for(int i = 1; i <= n; i++){
        if(airports[i].earliest == INF){ 
            cout << -1 << endl;
        }else{ 
            cout << max(0,airports[i].earliest) << endl;
        }
    }

}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
        
        solve();

}
