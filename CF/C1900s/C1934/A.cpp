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
int a[100];
void solve(){
    int n; 
    cin >> n; 
    for(int i = 0; i < n; i++){ 
        cin >> a[i]; 

    }
    sort(a, a+n);
    ll res1 = abs(a[0]-a[n-1]) + abs(a[0]-a[n-2]) + abs(a[1]-a[n-2]) + abs(a[1]-a[n-1]);
    cout << res1 << endl;

}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t; 
    cin >> t; 
    while(t--){
        
        solve();
    }
    return 0;
}
