#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;
 
#pragma region
#define ll long long
#pragma endregion
 
vector<pair<int,int>> adj[105]; 
vector<pair<int,int>> backtrace[105];
bool visited[105];
int distances[105];
const int INF = 100000000;
int find_roads(int start, int target){
    if(start == target) return 0;
    visited[start] = true; 
    int length = 0;
    for(auto [e,l]: backtrace[start]){ 
        if(!visited[e]){ 
            length += l;
            length += find_roads(e, target);
        }
    }
    return length;
}
void solve(){
    int n,m,a,b; 
    cin >> n >> m >> a >> b; 
    vector<tuple<int,int,int>> edges;
    int total_length = 0;
    for(int i =0; i < m; i++){ 
        int x,y,l; 
        cin >> x >> y >> l; 
        adj[x].emplace_back(y, l);
        adj[y].emplace_back(x,l);
        edges.emplace_back(x,y,l);
        total_length += l;
    }
    for(int i =1; i <= n; i++){ 
        distances[i] = INF;
    }
    distances[a] = 0;
    //bellmen ford 
    for(int i =0; i < n-1; i++){ 
        for(int j =0; j < m; j++){ 
            auto& [x,y,l] = edges[j]; 
            if(distances[x]+l < distances[y]){ 
                distances[y] = distances[x]+l;
            }
            if(distances[y]+l < distances[x]){ 
                distances[x] = distances[y]+l;
            }
        }
    }

    for(int i =0;i < m; i++){ 
        auto& [x,y,l] = edges[i];
        if(distances[x]+l == distances[y]){ 
            backtrace[y].emplace_back(x, l);
        }
        if(distances[y]+l == distances[x]){ 
            backtrace[x].emplace_back(y,l);
        } 
    }

    int res = total_length - find_roads(b,a);

    cout << res << endl;
}   
 
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();
}