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
int a[2'00'005]; 
int b[2'00'005];

int solve(){
    int n, m; 
    cin >> n >> m;
    for(int i =0; i < n; i++){ 
        cin >> a[i]; 
    }
    for(int i =0; i < m; i++){ 
        cin >> b[i];
    }
    sort(b,b+m, [](int l, int r){return l > r;});
    int i =0; 
    int j =0; 
    while(i < n && j < m){ 
        if(b[j] >= a[i]){ 
            cout << b[j++] << " ";
        }else{ 
            cout << a[i++] << " ";
        }
    }
    for(; i < n; i++){ 
        cout << a[i] << " ";
    }
    for(; j < m; j++){ 
        cout << b[j] << " ";
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
