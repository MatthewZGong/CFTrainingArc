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

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}
vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}
vector<int> pal;
int solve(int l, int r){ 
    int length = r-l+1; 
    
    if(length%2 == 0){ 

    }else{ 

    }

}


void solve(){
    int n, q; 
    string s;
    cin >> n >> q; 
    cin >> s; 

    pal.clear();
    pal = manacher(s);
    for(int i = 0; i <pal.size(); i+=1){ 
        if(i%2 == 0){ 
            pal[i] /=2;
        }else{ 
            pal[i] -=1; 
            pal[i] /=2;
        }
        cout << pal[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < q; i++){ 
        int l, r; 
        cin >> l >> r; 
        cout << l << " " << r << endl;
    }


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
