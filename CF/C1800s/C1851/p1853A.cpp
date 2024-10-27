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
    int diff = 1000000000; 
    int prev; 
    cin >> prev;
    for(int i =1; i < n; i++){
        int current; 
        cin >> current; 
        diff = min(current-prev, diff);
        prev = current; 
        
    }
    if(diff < 0){ 
        cout << 0 << endl;
        return;
    }
    diff /= 2;
    diff += 1; 
    cout << diff << endl;
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
