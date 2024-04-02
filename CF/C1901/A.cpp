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

// int a[100];
int solve(){
    // cout << "_______________" << endl;
    int n, x;
    cin >> n >> x; 
    int prev = 0;
    int current; 
    int res = 0; 
    for(int i =0; i < n; i++){ 
        cin >> current; 
        res = max(res, current-prev); 
        prev = current; 
    }
    res = max(res, (x-prev)*2);
    cout << res << endl;
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
