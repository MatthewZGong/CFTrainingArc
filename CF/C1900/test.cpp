#include<bits/stdc++.h>
 
using namespace std;
void print(int v[], int n){
    for(int i =0 ; i < n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
void solve(){
    cout << 1 << endl;
    int n = 80'000;
    cout << n << endl;
    for(int i =0; i < n; i++){ 
        cout << (rand() % 100'000 )+1<< " ";
    }
    cout << endl;
}
 
 
int main(){ 
    // int t = 1; 
    // cout << &t << endl; 
    solve();
}