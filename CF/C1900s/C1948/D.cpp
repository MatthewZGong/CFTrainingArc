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


string s;
int n;


void solve(){
    cin >> s; 
    n = s.size(); 
    int ans = 0;  
    for(int length = 1; length <= n/2 ; length++){ 
        int cur = 0;
        for(int i = 0; i < s.size()-length; i++){ 
            if(s[i] == s[i+length] || s[i] == '?' || s[i+length] == '?'){
                cur++;
            }else{ 
                cur = 0;
            }
            if(cur == length){ 
                ans = length;
                break;
            }
        }
    }
    cout << ans*2 << endl;
    



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
