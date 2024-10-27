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
int a[200005];
void solve(){
    int n, k; 
    cin >> n;
     
    for(int i= 0; i < n; i++){ 
        cin >> a[i];
        for(int i =0; i < n; i++){ 
            cin >> a[i]; 
        }
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
