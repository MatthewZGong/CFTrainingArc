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

void solve(){
    set<ll> res;
    ll x, n; 
    cin >> n >> x; 
    ll diff = n-x; 

    for(int i = 1; i*i <= diff; i++){ 
        if(diff%i == 0){ 
            ll div = diff/i; 
            ll k1 = (i+2)/2; 
            ll k2 = (div+2)/2;
            if(k1 >= x && k1 != 1 &&  i%2 == 0) res.insert(k1);
            if(k2 >= x && k2 != 1 && div%2 == 0) res.insert(k2);
        }
    }

    ll diff2 = n+x-2;  
    for(int i = 1; i*i <= diff2; i++){
        if(diff2%i == 0){ 
            ll div = diff2/i; 
            ll k1 = (i+2)/2; 
            ll k2 = (div+2)/2;
            if(k1 >= x && k1 != 1 && i % 2 == 0 ) res.insert(k1);
            if(k2 >= x && k2 != 1 && div % 2 == 0) res.insert(k2);
        }
    }
    // for(auto i: res){ 
    //     cout << i << " ";
    // }
    // cout << endl;
    cout << res.size() << endl; 
    
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
