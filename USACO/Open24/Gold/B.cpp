#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
// #include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;

// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;


using ordered_set = tree<
tuple<int,int>,
null_type,
less<tuple<int,int>>,
rb_tree_tag,
tree_order_statistics_node_update>;

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

int get_length(tuple<int,int,int,int> t){ 
    return get<1>(t) - get<0>(t);
}

int answer[200'000];
//Left, Right, K, i
vector<tuple<int,int,int,int>> cultivators_k;
vector<tuple<int,int,int,int>> cultivators_length;


//left, i
ordered_set start_points_bigger_than_k; 
//right i
ordered_set  end_points_bigger_than_k;

//left, i
int ranges_smaller_than_k = 0;

int current_k; 
int length_ind = 0;
int N; 

void update_sets(){ 
    while(length_ind < N && get_length(cultivators_length[length_ind]) < current_k){ 
        auto [left, right, k, id] = cultivators_length[length_ind];
        start_points_bigger_than_k.erase({left, id});
        end_points_bigger_than_k.erase({right, id});
        ranges_smaller_than_k++;
        length_ind++;
    }
}

int get_overlap(int left, int right, int id, int k){ 
    // cout << "over lap for: " << left << " " << right << " " << k << endl;

    int ans = N-1; 
    // cout << N << " " << ans << endl;
    int start_points = start_points_bigger_than_k.size()-start_points_bigger_than_k.order_of_key({right-(k-1), -1});
    int end_points = end_points_bigger_than_k.order_of_key({left+(k-1), N}); 
    // cout << "start points: " << start_points << " end points: " << end_points << " ranges smaller than k: " << ranges_smaller_than_k << endl;
    ans -= start_points;
    ans -= end_points;
    ans -= ranges_smaller_than_k;
    // cout << "ans: " << ans << endl;
    return ans; 
}



void solve(){
    cin >> N; 
    // cout << N << endl;
    for(int i =0; i < N; i++){ 
        int l, r, k; 
        cin >> l >> r >> k;
        cultivators_k.push_back({l, r, k, i});
        cultivators_length.push_back({l, r, k, i});
        start_points_bigger_than_k.insert({l, i});
        end_points_bigger_than_k.insert({r, i});
    }
    sort(cultivators_k.begin(), cultivators_k.end(), [](const tuple<int,int,int,int> a, const tuple<int,int,int,int> b){
        return get<2>(a) < get<2>(b);
    });
    sort(cultivators_length.begin(), cultivators_length.end(), [](const tuple<int,int,int,int> a, const tuple<int,int,int,int> b){
        return get<1>(a)-get<0>(a) < get<1>(b)-get<0>(b);
    });
    for(int i = 0; i < N; i++){ 
        current_k = get<2>(cultivators_k[i]);
        update_sets();
        auto [left, right, k, id] = cultivators_k[i];
        answer[id] = get_overlap(left, right, id, k);

    }
    for(int i =0; i < N; i++){
        cout << answer[i] << endl;
    }

    


    



}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
  
        
    solve();
    return 0;
}
