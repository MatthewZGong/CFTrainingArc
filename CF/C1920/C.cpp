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
int n;
int a[2'00'000];
int solve_group(int k){ 
    vector<int> diffs; 
    for(int i = 0; i < n-k; i++){
        if(a[i] == a[i+k]) continue;
        diffs.push_back(abs(a[i]-a[i+k]));
    }
    if(diffs.size() == 0) return 1;
    int factor = diffs[0];
    for(int i = 1; i < diffs.size(); i++){
        factor = gcd(factor, diffs[i]);
    }
    return factor > 1;
}
void solve(){
    cin >> n;
    for(int i =0; i < n; i++){
        cin >> a[i];
    }   
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    int ans = 1+solve_group(1);
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0){
            ans += solve_group(i);
            if(i != n/i)
            ans += solve_group(n/i);
        }
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
