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
void solve(){
    int n, a, b; 
    cin >> n >> a >> b;
    bool start = false; 
    bool end = false;
    for(int i =0; i < n-1; i++){ 
        int c; 
        cin >> c;
        if(c == a){
            start = true;
        }
        if(c == b){
            end = true;
        }
    }
    if(start == false && end == false){
        cout << -1 << '\n';
    }else if(start == false){ 
        cout << a << '\n';
    }else if(end == false){ 
        cout << b << '\n';
    }else{ 
        for(int i = a; i <= b; i++){
            cout << i << '\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();
}
