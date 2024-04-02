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

int solve(){
    vector<pair<ll,ll>> a; 
    ll n, c; 
    cin >> n >> c; 
    ll s; 
    cin >> s; 
    // cout << s << " ";
    for(ll i = 2; i <= n; i++){ 
        ll current; 
        cin >> current; 
        // cout << current << " ";
        a.push_back({i*c-current, current});
    }
    // cout << endl;
    sort(a.begin(), a.end()); 
    for(int i = 0; i < a.size(); i++){ 
        auto [diff, val] = a[i];
        // cout << diff  << "|" << val << " ";
        if(s >= diff){ 
            s += val; 
        }else{ 
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl; 
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
