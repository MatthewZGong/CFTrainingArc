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
ll a[2000];
int solve(){
    ll n, k; 
    cin >> n >> k; 
    for( int i = 0; i < n; i++){ 
        cin >> a[i]; 
    }
    if(k >= 3){ 
        cout << 0 << endl;
        return 0;
    }
    ll res = *min_element(a, a+n);
    vector<ll> diff; 
    for(int i =0; i < n; i++){ 
        for(int j = i+1; j < n; j++){ 
            ll d = abs(a[i] - a[j]);
            diff.push_back(d);
            res = min(res, d);
        }
    }
    if(k == 1){ 
        cout << res << endl;
        return 0;
    }
    sort(diff.begin(), diff.end());
    for(int i =0; i < n; i++){ 
        auto closest = lower_bound(diff.begin(), diff.end(), a[i]);
        if(closest != diff.end())
            res = min(res, *closest-a[i]);
        if(closest != diff.begin()){
            res = min(res, a[i]-*(--closest));
        }
    }
    cout << res << endl;
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
