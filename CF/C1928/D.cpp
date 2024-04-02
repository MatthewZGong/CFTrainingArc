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

ll n, b, x;
ll c[2'00'000];
ll get_pairs(ll a, ll k){ 
    k = min(k, a);
    ll size = a/k; 

    ll pairs = k*(k-1)/2 * (size*size);
    ll excess = a%k; 
    pairs += excess*(excess-1)/2 + excess*(size*k - size);
    return pairs;
}
ll get_total_pairs(ll k){ 
    ll total = 0;
    for(int i = 0; i < n; i++){ 
        total += b*get_pairs(c[i], k);
    }
    return total-x*(k-1);
}

void solve(){
    cin >> n >> b >> x;
    ll start = 1;
    ll end = 1;
    for(int i = 0; i < n; i++){ 
        cin >> c[i];
        end = max(end, c[i]);
    }
    while(start < end){ 
        ll mid = (start+end)/2+1;
        ll left = get_total_pairs(mid-1);
        ll right = get_total_pairs(mid);
        if(left <= right){ 
            start = mid;
        }else{ 
            end = mid-1;
        }
    }
    cout << get_total_pairs(start) << endl;


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
