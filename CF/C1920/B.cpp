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
int a[200000];
int prefix[200001];
void solve(){
    int n,k,x; 
    cin >> n >> k >> x;
    for(int i =0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    for(int i =0; i < n; i++){
        prefix[i+1] = prefix[i] + a[i];
    }
    int ans = -1000000000;
    for(int i =0; i <= k; i++){
        int neg = prefix[max(n-i,0)]-prefix[max(n-i-x,0)];
        int pos = prefix[max(n-i-x,0)];
        ans = max(ans, pos-neg); 
    }
    cout << ans << endl;
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
