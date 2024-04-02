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
int a[205];
int solve(){
    int n; 
    cin >> n; 
    for(int i =0; i < 2*n; i++){ 
        cin >> a[i]; 
    }
    sort(a, a+2*n); 
    cout << (a[n-1]-a[0]) + (a[2*n-1]-a[n]) << endl; 
    for(int i =0; i < n; i++){ 
        cout << a[i] << " " << a[2*n-1-i] << endl;
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
