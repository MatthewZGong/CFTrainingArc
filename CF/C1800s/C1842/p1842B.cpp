#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region

int a[100005];
int b[100005];
int c[100005]; 

void print(int v[], int n){
    for(int i =0 ; i < n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
#pragma endregion


void solve(){
    int n,x; 
    cin >> n >> x; 
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++i){
        cin >> b[i];
    }
    for(int i = 1; i <= n; ++i){
        cin >> c[i];
    }
    int current; 
    int res = 0;
    for(int i =1; i <= n; ++i){
        current = a[i] | res; 
        if((current | x) != x){
            break;
        }
        res = current; 
    }
    for(int i =1; i <= n; ++i){
        current = b[i] | res; 
        if((current | x) != x){
            break;
        }
        res = current; 
    }
    for(int i =1; i <= n; ++i){
        current = c[i] | res; 
        if((current | x) != x){
            break;
        }
        res = current; 
    }
    // cout << res << endl;
    if(res != x){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl; 
    }
    
}

int main(){
    int t; 
    cin >> t; 
    while(t--){
        solve();
    }

}
