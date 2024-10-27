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

void solve(){
    ll k, x, a; 
    cin >> k >> x >> a; 
    // cout << "Case: " << k << " " << x << " " << a << endl;
    ll loss = 0;
    k--;
    for(int i = 0; i < x; i++){ 
        ll make_back = loss/k + 1;
        loss += make_back;
        a -= make_back;
        // cout << "loss: " << loss << " " << a << endl;
        if(a < 0){ 
            cout << "NO" << endl;
            return;
        }
    }
    ll make_back = loss/k + 1;
    // cout << a << " " << make_back << " " << loss << endl;
    if(a < make_back){ 
        cout << "NO" << endl;
    }else{ 
        cout << "YES" << endl;
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
