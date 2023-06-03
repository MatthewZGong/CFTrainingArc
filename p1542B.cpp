//https://codeforces.com/problemset/problem/1542/B


#include<bits/stdc++.h>

using namespace std;


void solve(){
    int64_t n, a, b;
    cin >> n >> a >> b; 
    if(a == 1){
        cout << (((n - 1) % b) ? "No" : "Yes") << endl;
        return;
    }
    int64_t ex = 1; 
    while(ex <= n){
        if((n-ex)%b == 0){
            cout << "Yes" << endl;
            return;
        }
        ex *= a;
    }
    cout << "No" << endl;

}
// void print(int v[], int n){
//     for(int i =0 ; i < n; ++i){ 
//         cout << v[i] << " ";
//     }
//     cout << endl;
// }

int main(){ 
    int t; 
    cin >> t; 
    while(t--) solve();
    return 0;
}
