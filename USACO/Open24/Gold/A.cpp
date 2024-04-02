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

int N, K;
string first; 
string last;

void solve(){
    cin >> N >> K;
    cin >> first;
    cin >> last;
    vector<int> H_top; 
    vector<int> H_bot;
    for(int i = 0; i < N; i++){ 
        if(first[i] != last[i]){ 
            if(first[i] == '1'){ 
                H_top.push_back(i);
            }else{ 
                H_bot.push_back(i);
            }

        }
    }
    assert(H_top.size() == H_bot.size());

    ll res = 0; 
    vector<int> forward_start;
    set<int> forward_dest; 
    vector<int> backward_start;
    set<int, greater<int>> backward_dest;
    for(int i = 0; i < H_top.size(); i++){
        // cout << H_top[i] << " " << H_bot[i] << endl;
        if(H_top[i] < H_bot[i]){ 
            forward_start.push_back(H_top[i]);
            forward_dest.insert(H_bot[i]);
        }else{ 
            backward_start.push_back(H_top[i]);
            backward_dest.insert(H_bot[i]);
        }
    }
    for(int i = 0; i < forward_start.size(); i++){
        int current = forward_start[i]; 
        int target = *forward_dest.begin(); 
        int jumps = (abs(current - target)+(K-1))/K; 
        int max_jump_range = current+(jumps)*K; 
        auto target_res = forward_dest.lower_bound(max_jump_range);
        if(target_res == forward_dest.end() || (*target_res) != max_jump_range){ 
            target_res--;
        }
        forward_dest.erase(target_res);
        res += jumps;
    }
    // cout << "got here" << endl;
    for(int i = backward_start.size()-1; i >= 0; i--){
        int current = backward_start[i]; 
        int target = *backward_dest.begin(); 
        int jumps = (abs(current - target)+(K-1))/K; 
        int max_jump_range = current-(jumps)*K; 
        auto target_res = backward_dest.lower_bound(max_jump_range);
        if(target_res == backward_dest.end() || (*target_res) != max_jump_range){ 
            target_res--;
        }
        backward_dest.erase(target_res);
        res += jumps;
    }
    cout << res << endl;
    
    



}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
        
        solve();
    return 0;
}
