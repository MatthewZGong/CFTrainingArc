#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
template<typename T>
void print(T v[], int n){
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

ll x[2'00'000];
ll prefix[2'00'001];
ll n;

ll query(ll a, ll b, ll y){ 
    ll* p = lower_bound(x, x+n, y);
    int i = p - x; 
    
    ll left =  prefix[i];
    ll right = prefix[n] - prefix[i];
    ll left_side = a*y*i - a*left; 
    ll right_side = b*right - b*y*(n-i);
    return left_side + right_side; 
}
void search_min(ll a, ll b){ 
    ll left = 0; 
    ll right = 1'000'000;
    ll mid_val;
    while(left < right){ 
        ll mid = (left+right)/2;
        mid_val = query(a, b, mid);
        ll left_mid = query(a, b, mid-1);
        ll right_mid = query(a, b, mid+1);
        // cout << mid_val << " " << left_mid << " " << right_mid << endl;
        if(mid_val > left_mid){ 
            right = mid-1;
        }else if(mid_val > right_mid){ 
            left = mid+1;
        }else{ 
            cout << mid_val << endl;
            return;
        }
    }
    // cout << left << " " << right << " " << query(a, b, left) << endl;
    cout << query(a, b, left) << endl;
}
void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){ 
        cin >> x[i];
    }
    sort(x, x+n);
    // print(x, n);

    // prefix[0] = x[0];
    for(int i = 1; i <= n; i++){
        prefix[i] = prefix[i-1] + x[i-1];
    }
    // print(prefix, n+1);
    int q; 
    cin >> q; 
    for(int i = 0; i < q; i++){ 
        int a, b; 
        cin >> a >> b;
        search_min(a, b);
    }
    
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
        
        solve();

}
