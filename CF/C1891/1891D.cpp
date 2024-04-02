#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll unsigned long long
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
const ll MOD = 10e9+7;

ll f(ll n){ 
    ll res = 0; 
    ll counter = 0;
    while(n){
        if(n&1) res = counter; 
        counter ++; 
        n >>= 1;
    } 
    return res;
}

ll g(ll n){ 
    return log(n)/log(f(n));
}
ll brute_force(ll r,ll l){ 
    ll res = 0;
    for(int i =l; i <= r; i++){ 
        res += g(i);
        res %= MOD;
        if(g(i) != g(i-1)) cout << i << endl;
    }
    return res;
}

int solve(){
    ll r, l; 
    cin >> l >> r; 
    cout << brute_force(r,l) << endl;
    ll start = 1 << f(l);
    ll res = 0;
    while(start < r){ 
        start <<= 1; 
        res += g(l)*((start)-l);
        res %= MOD;
        l = start;
    }
    res -= g(r)*(start-r-1);
    res %= MOD;
    cout << res << endl;
    return 0;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    for(ll i =5; i <= (1ll<<32); i++){ 
        if(i%500'000'000 == 0)  cout << "CHECK" << endl; 
        if(g(i) != g(i-1)) cout << i << endl;
    }
    int t; 
    cin >> t; 
    while(t--){
        
        solve();
    }

}
