// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
// #include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;

using ordered_set = tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>;

using ll = long long; 
int MOD = 1000000000;
// pair<int,int> get_rel_ind(vector<pair<int,int>>& removed, int j, int target, int prev){ 
//     pair<int,int> rel_info;
//     while(j < removed.size(),){ 
        
//     }
//     return ;
// }
int solution(vector<int> &T) {
    //tree that keeps track of subtree size
    ordered_set removed;
    int n = T.size(); 
    vector<pair<int,int>> tasks; 
    map<int,vector<int>> indices;
    for(int i =0; i < n; i++){
        indices[T[i]].push_back(i+1);
    }
    
    ll res = 0;
    ll prev_hour = 0;
    ll prev_wait = 0;
    for(auto const& x: indices){ 
        int hour = x.first; 
        const vector<int>& inds = x.second;
        int rel_ind = 0;
        for(int i: inds){ 
            rel_ind = removed.order_of_key(i);
            res += ((hour-prev_hour-1)*(n)+i-rel_ind)+prev_wait;
        }
        for(int i: inds){ 
            removed.insert(i);
        }
        prev_wait += (hour-prev_hour)*n;
        n -= inds.size();
        prev_hour = hour;
    }
    return res;
    // Implement your solution here
}
