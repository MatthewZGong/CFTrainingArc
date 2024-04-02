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
#pragma endregion

bool guernsey [100005];
vector<int> graph[100005]; 
bool visited[100005];
int island[100005];
void dfs(int start, int num, bool g){ 
    if(visited[start] || guernsey[start] != g){ 
        return; 
    }
    visited[start] = true;
    island[start] = num;

    for(int i =0; i < graph[start].size(); i++){ 

        dfs(graph[start][i], num, g);
    }
} 
int solve(int n, int m){
    char g; 
    for(int i =1; i <= n; i++){ 
        cin >> g; 
        if(g == 'G'){ 
            guernsey[i] = true;
        }else{
            guernsey[i] = false; 
        }
    }
    int island_num = 0;
    for(int i = 0; i < n-1 ; i++){ 
        int x, y; 
        cin >> x >> y;
        graph[x].push_back(y); 
        graph[y].push_back(x);
    }
    for(int i =1; i <= n; i++){
        if(visited[i]) continue; 
        island_num ++;
        dfs(i, island_num, guernsey[i]);
    }
    for(int i =0; i < m; i++){ 
        int x, y;
        char type;
        cin >> x >> y >> type; 
        if(island[x] != island[y] ){ 
            cout << 1;
        }else{
            cout << (guernsey[x] == (type == 'G')) ? 1 : 0;
        }
    } 
    cout << endl; 
    return 0;
}
void setIO(string s) {
  ios_base::sync_with_stdio(0); 
  cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}


int main(){
    setIO("milkvisits");
    cin.tie(0);
    int n,m; 
    cin >> n >> m;     
    solve(n, m);
    // cout << 3 << "\n";
    // cin >> n;


}
