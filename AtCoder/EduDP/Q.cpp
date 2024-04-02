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
ll h[2'00'000];
ll a[2'00'000];
void solve(){
    set<pair<ll,ll>> heights; 
    int n; 
    cin >> n;
    for(int i =0; i < n; i++){ 
        cin >> h[i];
    }
    for(int i = 0; i < n; i++){ 
        cin >> a[i];
    }
    ll best = 0;
    for(int i = 0; i < n; i++){ 
        ll hi = h[i]; 
        ll ai = a[i];
        auto front = heights.lower_bound({hi, 0}); 
        pair<ll,ll> res;
        if(front == heights.begin()){ 
            res = {hi, ai};
        }else{
            pair<ll,ll> back = *(--front); 
            res = {hi, back.second+ai};
            best = max(best, res.second);
            front++;
        }

        while(front != heights.end() && front->second < res.second){ 
            heights.erase(front); 
            front = heights.lower_bound({hi, 0});
        }
        best = max(best, res.second);
        heights.insert(res);
    }
    cout << best << endl;

}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);    
    solve();
}
