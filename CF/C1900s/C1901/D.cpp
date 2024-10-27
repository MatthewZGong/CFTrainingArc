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
struct Line{ 
    Line(int x1,int  y1){ 
        start = x1; 
        end = y1; 
    }
    int start; 
    int end;
};
ll a[3'00'000];
ll b[3'00'000];
ll c[3'00'000];
int solve(){
    ll n; 
    cin >> n; 
    for(ll i =0; i < n; i++){ 
        cin >> a[i];
        b[i] = a[i]+i;
        c[i] = a[i]+(n-1-i);
    }
    if(n ==1){ 
        cout << a[0] << endl;
        return 0;
    }
    // print(b,n);
    // print(c,n);
    for(int i =1; i < n; i++){ 
        c[i] = max(c[i],c[i-1]); 
    }
    for(int i = n-2; i >= 0; i--){
        b[i] = max(b[i],b[i+1]);
    }
    // print(b,n);
    // print(c,n);
    ll res = max(b[1], a[0]); 
    for(int i =1; i < n-1; i++){ 
        ll cur = max(b[i+1], c[i-1]);
        cur = max(cur, a[i]);
        res = min(res, cur);
    }
    ll cur = max(c[n-2], a[n-1]);
    res = min(res, cur);
    cout << res << endl;
    

    return 0;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    // int t; 
    // cin >> t; 
    // while(t--){
        
        solve();
    // }

}
