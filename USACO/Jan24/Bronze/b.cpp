#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
template<typename T>
void print(T v[], int n, int i = 0){
    for(; i < n; ++i){ 
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
ll n, s; 
ll q[1'00'001]; 
ll v[1'00'001];
ll visited[1'00'001][2];
void solve(){
    cin >> n >> s; 
    memset(visited, -1, sizeof(visited));
    for(int i = 1; i <= n; i ++){ 
        cin >> q[i]; 
        cin >> v[i];
    }
    ll direction = 1; 
    ll power = 1;
    ll destroyed = 0;
    int i = s;
    while(i <= n && i > 0){ 
        if(direction == -1 && visited[i][0] == power) break; 
        if(direction == 1 && visited[i][1] == power) break;
        if(direction == -1)
            visited[i][0] = power;
        else
            visited[i][1] = power;
        if(q[i] == 0){ 
            direction *= -1; 
            power += v[i];
        }
        i += power*direction;
    }
    int res = 0;
    // print(visited, n+1, 1);
    for(int i = 1; i <= n; i++){ 
        if(q[i] == 1){ 
            if(visited[i][0] >= v[i] || visited[i][1] >= v[i]){
                res++;
            }
        }
    }
    // cout << endl;
    cout << res << endl;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

        
    solve();
    

}
