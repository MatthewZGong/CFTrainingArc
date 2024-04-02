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
const ll INF = 1e18+1;
int solve(){
    ll n, m, k; 
    cin >> n >> m >> k;
    vector<pair<ll,ll>> cows;
    for(int i = 0; i < n; i++){ 
        ll w, a; 
        cin >> w >> a;
        cows.push_back({w,a});
    }
    sort(cows.begin(), cows.end());
    deque<pair<ll,ll>> towers; 
    towers.push_back({INF, m});
    ll ans = 0;
    for(int i = n-1; i >= 0; i--){ 
        auto [w, a] = cows[i];
        while(!towers.empty() && a > 0 && towers.front().first - w >= k){
            auto& [w1, a1] = towers.front();
            ans += min(a1,a);
            if(a1 > a){
                a1 -= a;
                a = 0;
            }else{
                a -= a1;
                towers.pop_front();
            }
        }
        towers.push_back({w, cows[i].second - a});
    }
    cout << ans << endl;
    return 0;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();

}
