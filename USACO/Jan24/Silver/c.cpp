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
int N;
ll a[10'000];
vector<ll> unique_numbers;
set<ll> candidates;

unordered_set<ll> visited; 
ll res = 0;
bool is_valid(ll x){ 
    if(x == 0 || visited.find(x) != visited.end())
    {
        return false;
    }
    visited.insert(x);
    
    unordered_set<ll> found;
    for(int i = 0; i < N; i++){ 
        found.insert(a[i]%x);
        if(found.size() > 3){
            return false;
        }
    }
    return true; 
    

}
void solve(){
    cin >> N;
    ll lower = 1e10;
    ll upper = 1;
    unordered_set<ll> unique;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        lower = min(lower, a[i]);
        upper = max(upper, a[i]);
        if(unique.find(a[i]) == unique.end()){
            unique_numbers.push_back(a[i]);
        }
        unique.insert(a[i]);
    }
    lower /= 4; 
    if(unique.size() <= 3){ 
        cout << lower*(lower+1)/2 << endl;
        return;
    }
    sort(unique_numbers.begin(), unique_numbers.end());
    for(int i = 0; i < 4; i++){ 
        for(int k = i+1; k < 4; k++){
            ll current = abs(unique_numbers[i] - unique_numbers[k]);
            for(int j = 1; j*j <= current; j++){ 
                if(current % j == 0){    
                    ll a = current/j;
                    ll b = j; 
                    if(a != b){ 
                        if(is_valid(a) && a <= lower){ 
                            res += a;
                        }
                    }
                    if(is_valid(b) && b <= lower){
                        res += b;
                    }
                }
            }
        }
    }
    cout << res << endl;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    
    solve();
    

}
