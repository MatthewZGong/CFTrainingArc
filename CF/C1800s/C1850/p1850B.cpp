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

int solve(){
    int n; 
    cin >> n;
    int best = -1; 
    int res = 0;  
    for(int i = 1; i <= n; ++i){ 
        int a,b; 
        cin >> a >> b; 
        if(a <= 10){ 
            if(b > best){ 
                best = b; 
                res = i; 
            }
        }
    }
    cout << res << endl;
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
