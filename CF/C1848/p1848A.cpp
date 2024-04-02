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
    int n,m,k;
    cin >> n >> m >> k;
    int x,y; 
    cin >>x >> y;
    int current = (x+y)%2; 
    bool res = false;
    for(int i =0; i < k; i++){
        cin >> x >> y;  
        if(current == (x+y)%2){ 
             res = true;
        }
    }
    if(res == true){ 
        cout << "NO" << endl; 
    }else{ 
        cout << "YES" << endl;
    }
    return 0;

}

int main(){
    int t; 
    cin >> t; 
    while(t--){
        
        solve();
    }

}
