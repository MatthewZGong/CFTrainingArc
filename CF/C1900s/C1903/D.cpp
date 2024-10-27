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

const int LIMIT = 1 << 20;

ll a[1'000'000];
vector<pair<ll, ll>> break_points; 
ll n;



void preprocess(ll limit, ll mask, ll prev, ll k, ll prev_k) {
    vector<pair<ll,ll>> best; 
    for(int power = 1; power < limit; power <<= 1) { 
        ll operations = 0;
        for(int j = 0; j < n; j++) {
            if( (a[j] & mask) != mask )
            { 
                operations += power; 
            }
            else if( ( a[j] & power ) == 0) { 
                ll mod =   a[j] & (power-1);
                operations += (power-mod);
            }
        }
        if(operations != 0 && operations < k){
            while(best.size() > 0 && best.back().first >= operations) { 
                best.pop_back();
            }
            best.push_back({operations, power});
        }
    }
    for(int i = 0; i < best.size(); i++) { 
        auto [operations, power] = best[i];
        int ans = prev;
        ans |= power; 
        int comp = ~(power-1);
        ans = ans & comp;
        break_points.push_back({prev_k+operations, ans});
        ll max_operations;
        if(i == best.size()-1) { 
            max_operations = k;
        }else{ 
            max_operations = best[i+1].first;
        }
        preprocess(power, mask | power, ans, max_operations-operations, prev_k+operations);
    }
}

int solve(){
    int q; 
    cin >> n >> q; 
    ll start = LIMIT-1;
    ll max_operations = 0;
    for(int i =0; i < n; i++){ 
        cin >> a[i];
        start &= a[i];
        max_operations += LIMIT-a[i];
    }  
    // cout << "got to preprocess" << endl;
    break_points.push_back({0, start});
    preprocess(LIMIT, 0, start, max_operations, 0);
    break_points.push_back({max_operations, LIMIT});

    // cout << "got to queries" << endl;

    ll k;
    for(int i = 0; i < q; i++) { 
        cin >> k;
        auto it = lower_bound(break_points.begin(), break_points.end(), k, [](const pair<ll,ll>& a, const ll b) { return a.first < b; });
        if(it == break_points.end()) { 
            it--; 
            ll operations_left = k - (*it).first;
            ll ans = (*it).second;
            ans += (operations_left/n);
            cout << ans << endl;
            continue;
        }else if((*it).first > k) { 
            it--;
        }
        cout << (*it).second << endl;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();
        // preprocess();
        // solve();

}
