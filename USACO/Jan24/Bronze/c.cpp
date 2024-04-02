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
int n;

void solve(){
    cin >> n; 
    ll ans = 0;
    ll removed = 0; 
    ll added = 0;
    ll neg_offset = 0; 
    ll pos_offset = 0;
    for(int i = 0; i < n; i++){ 
        ll a; 
        cin >> a; 
        neg_offset += removed; 
        pos_offset += added;
        // cout << a << " " << neg_offset << " " << pos_offset << endl;
        ll current = a - neg_offset + pos_offset; 
        ans += abs(current);
        if(current > 0){ 
            removed += abs(current);
            neg_offset += abs(current);
        }else{ 
            added += abs(current);
            pos_offset += abs(current);
        }

    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();

}
