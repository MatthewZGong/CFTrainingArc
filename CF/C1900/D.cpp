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
ll a[80000];
int solve(){
    int n; 
    cin >> n;
    for(int i =0; i < n; i++){ 
        cin >> a[i];
    }
    ll res = 0;
    sort(a, a+n);
    ll g = __gcd(a[0], a[1]);
    for(int i =2; i < n;i++){ 
        res += g;
        for(int j =0; j < i; j++){
            g += __gcd(a[i], a[j]);
        }
    }
    // print(a, n);
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
