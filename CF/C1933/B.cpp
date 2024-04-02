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


vector<int> nums[50'001];


void solve(){
    int n, k; 
    cin >> n >> k;
    for(int i = 0; i < 2*n; i++){ 
        int a; 
        cin >> a; 
        nums[a].push_back(i);
    }
    k *= 2; 
    vector<int> l; 
    vector<int> r; 
    vector<int> l_pairs; 
    vector<int> r_pairs;
    for(int i = 1; i <= n; i++){ 
        if(nums[i][0] >= n){ 
            r_pairs.push_back(i);
        }
        else if(nums[i][1] < n){ 
            l_pairs.push_back(i);
        }else{ 
            l.push_back(i); 
            r.push_back(i);
        }
    }
    assert(l_pairs.size() == r_pairs.size()); 
    while(l.size() > k){ 
        l.pop_back(); 
        r.pop_back();
    }
    // cout << l.size() << endl;
    if((k-l.size())%2 == 1){
        // cout << "what" << endl;
        l.pop_back(); 
        r.pop_back(); 
    }
    int s = l.size();
    for(int i = 0; i < (k-s)/2; i++){ 
        r.push_back(r_pairs[i]); 
        r.push_back(r_pairs[i]); 
        l.push_back(l_pairs[i]);
        l.push_back(l_pairs[i]);
    }

    for(int i = 0; i < l.size(); i++){ 
        cout << l[i] << " ";
    }
    cout << endl; 
    for(int i = 0; i < r.size(); i++){ 
        cout << r[i] << " ";
    }
    cout << endl;
    

    for(int i = 1; i <= n; i++){ 
        nums[i].clear();
    }


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
