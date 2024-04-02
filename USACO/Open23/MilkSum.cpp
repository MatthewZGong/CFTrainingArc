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

pair<ll,ll> info[2'00'000];
ll a[2'00'000];
ll ind_map[2'00'000];
ll prefix[2'00'000];
ll org = 0; 
int n;

ll solve_query(ll i, ll j){
    if(a[i] == j){
        return org; 
    }
    auto ind = lower_bound(a, a+n, j);
    ll index = ind - a;
    ll res = org - (a[i]*(i+1));
    if(a[i] < j){ 
        res -= prefix[index]-prefix[i+1];
        res += j*(index);
    }else{ 
        res += prefix[i]-prefix[index];
        res += j*(index+1);
    }
    return res; 

    
}
void solve(){
    cin >> n; 
    for(int i =0; i < n; i++){ 
        cin >> info[i].first;
        info[i].second = i;
    }
    sort(info, info+n);
    
    for(int i =0; i < n; i++){ 
        a[i] = info[i].first;
        ind_map[info[i].second] = i;
        prefix[i+1] = prefix[i] + a[i];
        org += a[i]*(i+1);
    }
    // cout << org << endl;
    int q; 
    cin >> q; 
    for(int i =0; i < q; i++){ 
        int x, y; 
        cin >> x >> y; 
        x = ind_map[x-1];
        cout << solve_query(x, y) << endl;
    }
    

}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
        
        solve();

}
