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
const ll inf = 1e18;
int n; 
ll h[2'00'000]; 
ll a[2'00'000]; 
ll t[2'00'000];

pair<ll,ll> plants[2'00'000];

pair<ll,ll> get_range(pair<ll,ll> prev, pair<ll,ll> cur){
    if(cur == prev){ 
        return {0, -1};
    }
    ll cur_start, cur_end;
    if(prev.first > cur.first){ 
        if(prev.second < cur.second){ 
            cur_start = (cur.first-prev.first)/(prev.second-cur.second)+1;
            cur_end = inf;
        }else{ 
            return {0,-1};
        }
    }else{ 
        if(prev.second < cur.second){
            cur_start = 0 + (cur.first == prev.first); 
            cur_end = inf;
        }else if(prev.second > cur.second){
            cur_start = 0; 
            cur_end = (cur.first-prev.first)/(prev.second-cur.second)-(0 == (cur.first-prev.first)%(prev.second-cur.second));
        }else{ 
            return {0, inf};
        }
    }
    return {cur_start, cur_end};
}

void solve(){
    cin >> n; 
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> t[i];
        plants[n-1-t[i]] = {h[i], a[i]};
    }
    ll start = 0; 
    ll end = inf;
    for(int i = 1; i < n; i++){     
        pair<ll,ll> cur = plants[i];
        pair<ll,ll> prev = plants[i-1];
        auto [cur_start, cur_end] = get_range(prev, cur);
        start = max(start, cur_start);
        end = min(end, cur_end);
    }
    if(start > end){ 
        cout << -1 << endl;
    }else{ 
        cout << start << endl;
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

}
