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

#define bit_count __builtin_popcountll
ll get_largest(ll target){ 
    ll largest = 1; 
    while((largest << 1) < target){ 
        largest <<= 1;
    }
    return largest; 

}
ll n; 
void solve(){
    // ll n; 
    cin >> n;
    ll p1, p2;
    if(bit_count(n)%2){ 
        cout << "second" << endl;
        cin >> p1 >> p2;
        n = bit_count(p1)%2  ? p2 : p1; 
    }else{ 
        cout << "first" << endl;
    }
    while(n > 0){ 
        ll largest = get_largest(n); 
        cout << largest << " " << (largest^n) << endl; 
        cin >> p1 >> p2;
        n = bit_count(p1)%2  ? p2 : p1; 
    }
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t; 
    cin >> t; 
    while(t--){
        solve();
        if(n == -1){ 
            return 0;
        }
    }
    return 0;
}
