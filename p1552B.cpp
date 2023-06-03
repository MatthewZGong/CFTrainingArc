#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
using namespace std;

int r[50005][5];
int cmp(int a, int b){
    if(a == b){
        return 0;
    }
    int g = 0;
    for(int i =0; i < 5; ++i){
        if(r[a][i] < r[b][i]){
            g++; 
        }
    }
    return g >= 3 ? 1 : 0;

}
int solve(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j =0; j < 5; j++){
            cin >> r[i][j];
        }
    }
    int res = 1; 
    for(int i = 2; i <= n; i++){
        if(cmp(i, res)){
            res = i;
        }
    }
    for(int i = 1; i <= n; i++){
        if(cmp(i, res)){
            return -1;
        }
    }
    return res; 
}
void print(int v[], int n){
    for(int i =0 ; i < n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){ 
    int t; 
    cin >> t; 
    while(t--){
        cout << solve() << endl;
    }

}
