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
    int n; 
    cin >> n;
    for(int i =0;i < n; i++){ 
        int val; 
        cin >> val; 
    }
    if(n%2 == 0){ 
        cout << 2 << endl; 
        cout << 1 << " " << n << endl; 
        cout << 1 << " " << n << endl; 
    }else{ 
        cout << 4 << endl; 
        cout << 1 << " " << n << endl; 
        cout << 1 << " " << n-1 << endl; 
        cout << n-1 << " " << n << endl; 
        cout << n-1 << " " << n << endl;
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
