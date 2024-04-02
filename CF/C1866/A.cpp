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

int solve(){
    ll n, x,y,z;
    cin >> n;
    if(n%3 == 0){
        x =1; y = 4; z = n-5;
    }else{
        x = 1; y =2; z = n-3;
    }
    // cout << x << " " << y << " " << z << endl;
    if((x+y+z) == n && x > 0 && y > 0 && z > 0 && (x != y && y !=z && x != z)){
        cout << "YES"  << endl;
        cout << x << " " << y << " " << z << endl;
    }else{
        cout << "NO"  << endl;
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
