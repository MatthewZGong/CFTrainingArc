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

bool visited[1'00'001];
int c[1'00'001];
int s[1'00'001];
int f[1'00'001];
void solve(){
    int n, m; 
    cin >>  n >> m;
    for(int i =0; i < n; i++){ 
        cin >> c[i];
    }
    for(int i = 0; i < n; i++){ 
        cin >> s[i];
    }
    for(int i = 0; i < n; i++){
        cin >> f[i];
    }


    for(int i =0; i < m; i++){ 

    }
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