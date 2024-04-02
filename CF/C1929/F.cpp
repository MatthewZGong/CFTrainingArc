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
#pragma endregion

const ll MOD = 998244353; 
int n;
ll c;

pair<ll,ll> children[5'00'001];
ll values[5'00'001];
vector<ll> ordering;

ll inv(ll a) {
  return a <= 1 ? a : MOD - (MOD/a) * inv(MOD % a) % MOD;
}

ll nCr(ll n, ll r){ 
    if(n < r){ 
        return 0;
    }
    if(r == 0 || n == r){ 
        return 1; 
    }
    if(n-r < r){ 
        return nCr(n, n-r);
    }
    ll num = 1; 
    ll dem = 1; 
    for(int i = 1; i <= r; i++){ 
        dem *= i; 
        dem %= MOD;
        num *= (n+1-i);
        num %= MOD;
    }
    ll dem_inv = inv(dem)%MOD; 
    
    return (num*dem_inv)%MOD;
}

void in_order_traversal(ll root){ 
    if(root == -1){ 
        return;
    }
    auto [left,right] = children[root];
    in_order_traversal(left);
    ordering.push_back(values[root]);
    in_order_traversal(right); 
    return;
}

void solve(){
    cin >> n;
    cin >> c;
    for(int i = 1; i <= n; i++){ 
        ll left, right, value; 
        cin >> left >> right >> value; 
        children[i] = {left, right}; 
        values[i] = value;
    }
    ordering.clear(); 
    ordering.push_back(1); 
    in_order_traversal(1); 
    ordering.push_back(c);

    ll res = 1; 
    int i = 1; 
    while(i <= n){ 
        if(ordering[i] == -1){ 
            int j = i; 
            while(ordering[j] == -1){ 
                j++;
            }
            ll length = j-i; 
            ll range = ordering[j]-ordering[i-1];
            ll options = nCr(range + length, length);
            res *= options; 
            res %= MOD;
            i = j;
        }
        i++;
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
