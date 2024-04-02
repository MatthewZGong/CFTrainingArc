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
ll n, t_c, t_m; 

tuple<ll, ll, ll> friends[100];

bool works(ll money){ 
    // return false;
    ll upgrade_c = 0; 
    ll upgrade_m = 0;
    // cout << "START" << endl;
    for(int i = 0; i < n; i++){ 
        auto [a, b, c] = friends[i];
        // cout << a << " " << b << " " << c << endl;
        ll diff = abs(a-b);
        if(a > b){
            ll current_c = min(money, t_c-1);
            ll current_m = max(0ll, money-(t_c-1));
            ll cost = (t_c-current_c)*a + (t_m-current_m)*b;
            if(cost > c){ 
                return false;
            }
            ll cost_diff = c-cost;
            ll slack = cost_diff/diff;
            upgrade_c = max(upgrade_c, current_c-slack);    
        }else if(b > a){
            ll current_m = min(money, t_m-1);
            ll current_c = max(0ll, money-(t_m-1));
            ll cost = (t_c-current_c)*a + (t_m-current_m)*b;
            if(cost > c){
                return false;
            }
            ll cost_diff = c-cost;
            ll slack = cost_diff/diff;
            upgrade_m = max(upgrade_m, current_m-slack);
        }else{ 
            ll current_c = min(money, t_c-1);
            ll current_m = max(0ll, money-(t_c-1));
            ll cost = (t_c-current_c)*a + (t_m-current_m)*b;
            if(cost > c){ 
                return false;
            } 
        }
    }
    return upgrade_m + upgrade_c <= money;
}
void solve(){
    cin >> n >> t_c >> t_m;
    for(int i = 0; i < n; i++ ){ 
        ll a, b, c; 
        cin >> a >> b >> c;
        friends[i] = {a, b, c};
    }
    
    ll start = 0; 
    ll end = t_c+t_m-2;
    while(start < end){ 
        ll mid = (start+end)/2;
        if(works(mid)){ 
            end = mid;
        }else{ 
            start = mid+1;
        }
    }
    cout << start << endl;
    
    
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
