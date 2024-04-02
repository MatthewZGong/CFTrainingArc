#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
void print(int v[], int n){
    for(int i =1 ; i <= n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
#pragma endregion

int a[200005];
int c[200005];
int trap(int n){
    int sq = (int) sqrt(n);
    // cout << n <<  " sq: " << sq << " calc: "; 
    int res = 0;
    for(int i =1; i <= sq; i++){ 
        int cur = n/i*i;
        if(cur == n){ 
            // cout << i << "|" << n/i << " ";
            if(i == sq && i*i == n){
                res += c[i];
            }else{
                res += c[i]; 
                res += c[n/i];

            }
        }
    }
    // cout << endl;
    // cout << "res: " << res << endl;
    // int res = 1;
    return res;
}
void clear(int n){ 
    for(int i =1; i <= n; i++){ 
        c[i] = 0; 
    }
}
void solve(){
    int n; 
    cin >> n; 
    // cout << n << endl;
    for(int i =1; i <= n; i++){
        cin >> a[i];
        if(a[i] <= n){ 
            c[a[i]] += 1;
        }
    }
    int res = 0;
    for(int i = 1; i <=n; i++){
        res = max(trap(i), res);
    }
    cout << res << endl;
    // print(c,n);

    clear(n);
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
