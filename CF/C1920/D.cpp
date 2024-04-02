#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#define ll long long

const ll MAX_INT = 1e18;
ll n, q; 
pair<ll, ll> op[100000];
ll queries[100000];
ll numbs[100000];
ll sizes[100000];

ll solve(ll k, int nums){

    auto it = lower_bound(sizes, sizes+nums, k+1); 
    if(it == sizes+nums){ 
        return solve(k%sizes[nums-1], nums);
    }
    if((*it)-1 == k){ 

        return numbs[it-sizes];
    }

    return solve(k%(*it),it-sizes);

}
void solve(){
    cin >> n >> q; 
    for(int i = 0; i < n; i++){ 
        cin >> op[i].first >> op[i].second;
    }
    for(int i = 0; i < q; i++){ 
        cin >> queries[i];
    }
    ll current_size = 0;
    int nums = 0;
    for(int i = 0; i < n && current_size <= MAX_INT; i++){ 
        if(op[i].first == 1){ 
            current_size += 1;
            sizes[nums] = current_size;
            numbs[nums] = op[i].second;
            nums++;
        }else{ 
            if(MAX_INT/(op[i].second+1) < current_size){
                break;
            }
            current_size *= (op[i].second+1);

        }
    }
    for(int i = 0; i < q; i++){
        cout << solve(queries[i]-1, nums) << " ";
    }
    cout << endl;

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
