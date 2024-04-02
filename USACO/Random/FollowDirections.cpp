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
char directions[1501][1501];
ll flow[1501][1501]; 
ll cost_column[1500]; 
ll cost_row[1500];
ll cost = 0;
int n;
ll compute_flow2(int i, int j){ 
    int left = 0; 
    int up = 0;
    if(j > 0 && directions[i][j-1] == 'R'){ 
        left = compute_flow2(i, j-1);
    }
    if(i > 0 && directions[i-1][j] == 'D'){
        up = compute_flow2(i-1, j);
    }

    return left+up+flow[i][j];
}
ll compute_flow(int i, int j){ 
    int left = 0; 
    int up = 0;
    if(j > 0 && directions[i][j-1] == 'R'){ 
        left = compute_flow(i, j-1);
    }
    if(i > 0 && directions[i-1][j] == 'D'){
        up = compute_flow(i-1, j);
    }

    return flow[i][j] = left+up+flow[i][j];
}
void add_flow(int x, int y, int cows){
    flow[x][y] += cows;
    if(x == n || y == n){ 
        if(x == n)
            cost += cows*cost_row[y];
        if(y == n)
            cost += cows*cost_column[x];
        return;
    }
    if(directions[x][y] == 'R'){
        add_flow(x, y+1, cows);
    }
    if(directions[x][y] == 'D'){
        add_flow(x+1, y, cows);
    }
    return;
}
void subtract_flow(int x, int y, int cows){ 
    flow[x][y] -= cows;
    if(x == n || y == n){ 
        if(x == n)
            cost -= cows*cost_row[y];
        if(y == n)
            cost -= cows*cost_column[x];
        return;
    }
    if(directions[x][y] == 'R'){
        subtract_flow(x, y+1, cows);
    }
    if(directions[x][y] == 'D'){
        subtract_flow(x+1, y, cows);
    }
    return;
}
void print_flow(){
    for(int i =0; i <= n; i++){ 
        for(int j =0; j <= n; j++){ 
            cout << flow[i][j] << " ";
        }
        cout << endl;
    }
}
void print_directions(){
    for(int i =0; i <= n; i++){ 
        for(int j =0; j <= n; j++){ 
            cout << directions[i][j] << " ";
        }
        cout << endl;
    }
}

int solve(){
    cin >> n; 
    for(int i =0; i < n; i++){ 
        string dir; 
        cin >> dir;
        for(int j = 0; j < n; j++){ 
            directions[i][j] = dir[j];
            flow[i][j] = 1;
        }
        directions[i][n] = 'R';
        cin >> cost_column[i];
    }
    
    for(int i =0; i < n; i++){
        directions[n][i] = 'D';
        cin >> cost_row[i];
    }
    // print_directions();
    // print_flow();
    for(int i = 0; i < n; i++){ 
        compute_flow(i, n); 
        compute_flow(n,i);
    }
    cost = 0; 
    for(int i =0; i < n; i++){ 
        cost += cost_column[i]*flow[i][n];
        cost += cost_row[i]*flow[n][i];
    }
    cout << cost << endl;
    int q; 
    cin >> q; 
    for(int i = 0; i < q; i++){ 
        int x, y; 
        cin >> x >> y; 
        x -=1; 
        y -=1;
        if(directions[x][y] == 'R'){
            directions[x][y] = 'D';
            subtract_flow(x, y+1, flow[x][y]);
            add_flow(x+1, y, flow[x][y]);
        }else{
            directions[x][y] = 'R';
            subtract_flow(x+1, y, flow[x][y]);
            add_flow(x, y+1, flow[x][y]);
        }
        
        cout << cost << endl;
    }
    // print_flow();
    return 0;
    
}
int solve2(){ 
    cin >> n; 
    for(int i =0; i < n; i++){ 
        string dir; 
        cin >> dir;
        for(int j = 0; j < n; j++){ 
            directions[i][j] = dir[j];
            flow[i][j] = 1;
        }
        directions[i][n] = 'R';
        cin >> cost_column[i];
    }
    
    for(int i =0; i < n; i++){
        directions[n][i] = 'D';
        cin >> cost_row[i];
    }
    cost = 0; 
    for(int i = 0; i < n; i++){ 
        cost += cost_column[i]*compute_flow2(i, n); 
        cost += cost_row[i]*compute_flow2(n,i);
    }
    cout << cost << endl;
    int q ; 
    cin >> q; 
    for(int i =0; i < q; i++){ 
        int x, y; 
        cin >> x >> y; 
        x -=1; 
        y -=1;
        if(directions[x][y] == 'R'){
            directions[x][y] = 'D';          
        }else{ 
            directions[x][y] = 'R';
        }
        cost = 0; 
        for(int i = 0; i < n; i++){ 
            cost += cost_column[i]*compute_flow2(i, n); 
            cost += cost_row[i]*compute_flow2(n,i);
        }
        cout << cost << endl; 
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    // int t; 
    // cin >> t; 
    // while(t--){
        
        solve();
    // }

}
