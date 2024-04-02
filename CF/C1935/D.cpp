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
ll a[3'00'000];
void solve(){
    int n;
    ll c;  
    cin >> n >> c; 
    ll res = ((c+1)*(c+2))/2;
    for(int i = 0; i < n; i++){ 
        cin >> a[i];
    }
    ll odds = 0; 
    for(int i = 0; i < n; i++){
        res -= a[i]/2+c-a[i]+1; 
        odds += a[i]%2;
    }
    res += (odds-1)*(odds)/2; 
    res += (n-odds)*(n-odds-1)/2;
    cout << res << endl;

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
