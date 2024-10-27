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
ll inv_mod_prime(ll a, ll MOD) {
  return a <= 1 ? a : MOD - (MOD/a) * inv_mod_prime(MOD % a, MOD) % MOD;
}

#pragma endregion



void solve(){
    int n;
    cin >> n;
    if(n%2 == 1){ 
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; i++){ 
        if( (i%4) <= 1 ){ 
            cout << "A";
        }else{ 
            cout << "B";
        }
    }
    cout << endl;
    return;
    



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
