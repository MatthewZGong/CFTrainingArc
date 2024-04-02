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
int a[100'005];
int solve(){
    int n; 
    cin >> n; 
    for(int i = 0; i < n; i++){ 
        cin >> a[i];
    }
    if(a[n-1] == 1){ 
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    // cout << 0 << endl;
    int length = 0;
    for(int i =n-1; i >= 1; i--){
        if(a[i] == 1 && a[i-1] == 0){ 
            cout << length+1 << " ";
            length = 0;
        }else{ 
            length += a[i];
            cout << 0 << " ";
        }
    }
    if(a[0] == 1){ 
        cout << length+1 << endl;
    }else{
        cout << 0 << endl;
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
