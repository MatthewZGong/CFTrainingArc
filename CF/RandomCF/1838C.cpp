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
int solve(){
    int n,m; 
    cin >> n >> m; 
    for(int i = n%2 ? n: n-1; i >= 1; i-=2){ 
        for(int j = 1; j <= m; j++){ 
            cout << (i-1)*m+j << " ";
        }
        cout << endl;
    }
    for(int i = n%2 ? n-1: n; i >= 1; i -= 2){
        for(int j = 1; j <= m; j++){ 
            cout << (i-1)*m+j << " ";
        } 
        cout << endl;
    }
    cout << endl;
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
