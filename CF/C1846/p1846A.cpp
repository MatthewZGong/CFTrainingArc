#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
void print(int v[], int n){
    for(int i =0 ; i < n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
#pragma endregion

int solve(){
    int n; 
    cin >> n; 
    int res =0;
    for(int i =0; i < n; ++i){ 
        int a, b; 
        cin >> a >> b; 
        if( a > b){ 
            res ++; 
        }
    }
    cout << res << endl;
    return res;

}

int main(){
    int t; 
    cin >> t; 
    while(t--){
        solve();
    }

}
