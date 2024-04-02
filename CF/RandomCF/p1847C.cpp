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
void print1(int v[], int n){
    for(int i =1 ; i <= n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}

template<typename T>
void print(vector<T> v){
    for(int i =0 ; i < v.size(); ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
#pragma endregion

bool seen[256];
int a[100005];
int solve(){
    memset(seen, 0, sizeof(seen));
    int n; 
    cin >> n; 
    for(int i =0; i < n; i++){ 
        cin >> a[i];
    }
    int current = 0;
    int ans = 0;
    for(int i  = n-1; i >= 0; i--){ 
        current ^= a[i]; 
        seen[current] = true;
        ans = max(current, ans);
        for(int i = 1; i < 256; i++){ 
           if(seen[i]) ans = max(current^i, ans);
        }
    }
    cout << ans << endl;
    return 0;
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
