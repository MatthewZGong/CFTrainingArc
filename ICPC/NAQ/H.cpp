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
void solve(){
    ll n, k, p; 
    cin >> n >> k >> p;
    vector<ll> res; 
    // ll target = floor(sqrt(n)); 
    for(ll i =1; i*i <= n; i++){
        if(n%i == 0){ 
            ll div = n/i; 
            // cout << i << " " << div << endl;
            if(i <= k && div <= p){ 
                res.push_back(i);
            }if(i != div && div <= k && i <= p){ 
                res.push_back(div);
            }
        }
    }
    cout << res.size() << '\n';
    sort(res.begin(), res.end());
    for(ll i =0; i < res.size(); i++){
        cout << res[i] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();
}
