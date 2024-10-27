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
#pragma endregion

void solve(){
    for(int i = 0; i < 8; i++){ 
        for(int j =0; j <8; j++){ 
            char a; 
            cin >> a;
            if(a != '.'){
                cout << a; 
            }
        }
    }
    cout << endl;
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
