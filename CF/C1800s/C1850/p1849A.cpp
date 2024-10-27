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
    int a,b,c; 
    cin >> a >> b >> c; 
    if(a+b >= 10){ 
        cout << "YES" << endl;
        return;
    }
    if(a+c >= 10){ 
        cout << "YES" << endl;
        return;
    }
    if(c+b >=10){
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
    return;
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
