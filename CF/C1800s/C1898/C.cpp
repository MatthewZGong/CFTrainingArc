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

int horizontal[16][15]; 
int vertical [16][15];
char get_char(int x){ 
    if(x == 0){ 
        return 'B';
    }
    return 'R';
}
void make_board(int n, int m, int min_dist){
    for(int i = 0; i < m-1; i++){ 
        horizontal[0][i] = i%2;
    }
    int offest = (m-1)%2;
    for(int i = 0; i < n-1; i++){ 
        vertical[i][m-1] = (i+offest)%2;
    }
    horizontal[1][0] = 1;
    vertical[0][0] = 0;
    vertical[0][1] = 0;


    // vertical[n-3][m-2] = 1;
        

    vertical[n-2][m-2] = vertical[n-2][m-1];
    horizontal[n-1][m-2] = (vertical[n-2][m-1]+1)%2;
    horizontal[n-2][m-2] = (vertical[n-2][m-1]+1)%2;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m-1; j++){ 
            cout << get_char(horizontal[i][j]) << " ";
        }
        cout << endl;
    }
    for(int i =0; i < n-1; i++){ 
        for(int j =0; j < m; j++){ 
            cout << get_char(vertical[i][j]) << " ";
        }
        cout << endl;
    }
}
int solve(){
    memset(vertical, 0, sizeof(vertical));
    memset(horizontal, 0, sizeof(horizontal));
    int n, m , k; 
    cin >> n >> m >> k; 
    int min_dist =(m-1)+(n-1);
    if(min_dist > k){ 
        cout << "NO" << endl;
        return 0;
    }   
    int dist = k-min_dist; 
    // cout << k << " " << min_dist << endl;
    // cout << dist << endl;
    if(dist%2 == 0){ 
        cout << "YES" << endl;
        make_board(n,m, min_dist);
    }else{ 
        cout << "NO" << endl;
    }
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
