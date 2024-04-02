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


vector<int> a;
bool works(){ 
    for(int i = 0; i < a.size()-1; i++){ 
        // cout << i << endl;
        // print(a);
        if(a[i] > a[i+1]){ 
            vector<int> next; 
            for(int j = 0; j < i; j++){ 
                next.push_back(a[j]);
            }
            if(a[i] < 10) return false; 
            next.push_back((a[i]/10)%10); 
            next.push_back(a[i]%10);
            for(int j = i+1; j < a.size(); j++){ 
                next.push_back(a[j]);
            }
            swap(a, next);
            return works();
        }

    }
    return true;

}
void solve(){
    a.clear();
    int n; 
    cin >> n; 
    for(int i = 1; i <= n; i++){ 
        int num; 
        cin >> num; 
        a.push_back(num);
    } 
    if(works())
        cout << "YES" << endl; 
    else
        cout << "NO" << endl;
    



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
