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

ll snowflake_size(ll k, ll degree, ll n){
    ll res = 1;
    for(int i =0; i < degree; i++){
        if(n/res < k){
            return -1;
        }
        res *= k;
        res += 1;
    }
    return res;
}

void solve(){
    ll n; 
    cin >> n;
    ll result = 0;
    ll log = n;
    while (log >>= 1) result++;   
    for(int degree =2; degree < result+1; degree++){
        ll start = 2; 
        ll end = (ll) pow(n,1.0L/degree);
        while(start < end){ 
            ll mid = (start+end)/2;
            ll size = snowflake_size(mid, degree, n);
            if(size >= n || size < 0){ 
                end = mid;
            }else{
                start = mid+1;
            }
        }

        if(snowflake_size(start, degree, n) == n){ 
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;

}

int main(){
    int t; 
    cin >> t; 
    while(t--){
        
        solve();
    }

}
