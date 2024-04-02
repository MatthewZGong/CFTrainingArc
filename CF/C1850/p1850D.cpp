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
    int n; 
    int k; 
    cin >> n >> k; 
    for(int i =0; i < n; i++){ 
        cin >> a[i];
    }
    if(n == 1){
        cout << 0 << endl; 
        return;
    }
    sort(a, a+n);
    int current = 1;
    int res = 0;
    // cout << k << endl;
    // for(int i =0; i < n; i++){ 
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    for(int i =1; i < n; i++){ 
        // cout << "diff: " << a[i]-a[i-1] << endl;
        if(a[i]-a[i-1] > k){
            // cout << "cur " << current << endl;
            res = max(current, res);
            current = 0;
        }
        current++;
    }
    // cout << "cur " << current << endl;
    res = max(current, res);
    cout << n-res << endl;

}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t; 
    cin >> t; 
    while(t--){
        // cout << "______" << endl;
        solve();
    }

}
