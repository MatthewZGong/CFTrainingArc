#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
template<typename T>
void print(T v[], int n, int i = 0){
    for(; i < n; ++i){ 
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
ll inv_mod_prime(ll a, ll MOD) {
  return a <= 1 ? a : MOD - (MOD/a) * inv_mod_prime(MOD % a, MOD) % MOD;
}
#pragma endregion

int n; 
int a[1'00'001];
int bit_prefix[32][1'00'002];
int bit_suffix[32][1'00'002];
int bit_tracker[32];

int get_largest_bit(int x){ 
    int largest = 0; 
    for(int i =0; i < 32; i++){ 
        if(x & (1 << i)){ 
            largest = i;
        }
    }
    return largest;
}
void solve(){
    cin >> n;
    for(int i =1; i <= n; ++i){ 
        cin >> a[i];
    }
    memset(bit_tracker, 0, sizeof(bit_tracker));
    for(int i =0; i < 31; ++i){ 
        int mask = 1 << i;
        bool even = true;
        bool even2 = true;
        bit_prefix[i][0] = 0;
        bit_suffix[i][n+1] = 0;
        for(int j = 1; j <= n; ++j){ 
            if((a[j] & mask) > 0){
                even = !even;
            }
            if(a[n+1-j] & (mask)){
                even2 = !even2;
            }
            bit_prefix[i][j] = bit_prefix[i][j-1] + (even ? 1 : 0);
            bit_suffix[i][n+1-j] = bit_suffix[i][n+2-j] + (even2 ? 1 : 0);
        }
        bit_prefix[i][n+1] = bit_prefix[i][n] + (even ? 1 : 0);
        bit_suffix[i][0] = bit_suffix[i][0] + (even2 ? 1 : 0);
    }
    ll res = 0; 
    for(int i = 1; i <= n; ++i){ 
        int x = a[i]; 
        int mask = get_largest_bit(x);
        ll right_even = bit_prefix[mask][n]-bit_prefix[mask][i];
        ll right_odd = n-(i)-right_even;

        ll left_even = bit_suffix[mask][1]-bit_suffix[mask][i];
        ll left_odd = (i-1)-left_even;
        if((bit_suffix[mask][i] == bit_suffix[mask][i+1] && bit_prefix[mask][i] == bit_prefix[mask][i-1]) || (bit_suffix[mask][i] != bit_suffix[mask][i+1] && bit_prefix[mask][i] != bit_prefix[mask][i-1] )){
            res += left_odd*right_even + left_even*right_odd;
        }else{ 
            res += left_odd*right_odd + left_even*right_even;
        }

        if(bit_prefix[mask][i] == bit_prefix[mask][i-1]){ 
            res += right_even;
        }else{ 
            res += right_odd;
        }
        if(bit_suffix[mask][i] == bit_suffix[mask][i+1]){ 
            res += left_even;
        }else{ 
            res += left_odd;
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
    return 0;
}
