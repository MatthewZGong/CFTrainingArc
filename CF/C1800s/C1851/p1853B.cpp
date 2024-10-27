#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
void print(int v[], int n){
    for(int i =0 ; i < n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
#pragma endregion
vector<int> fib;
void precompute(ll n){
    ll a = 0; 
    ll b = 1;   
    while(a < n){ 
        fib.push_back(a);
        ll c = a+b; 
        a = b; 
        b = c; 
    }
}

void solve(){
    ll n, k; 
    cin >> n >> k;
    if(k > 3*n){
        cout << 0 << endl;
        return;
    }
    ll f2, f1;
    if(k < fib.size()){ 
        f2 = fib[k-1];
        f1 = fib[k-2];
    }else{
        cout << 0 << endl;
        return;
    }
    ll res =0;
    
    // cout << f1 << " " << f2 << endl;
    for(ll i =0; i <= n; i++){
        if(n - f1*i <= 0){
            break;
        }
        if((n - f1*i)%f2 == 0 && (n - f1*i)/f2 >= i){ 
            res++;
        }
    }
    cout << res << endl;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t; 
    cin >> t; 
    precompute(1000000000);
    cout << fib.size() << endl;
    while(t--){
        solve();
    }

}
