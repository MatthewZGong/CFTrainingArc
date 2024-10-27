#include<bits/stdc++.h>
#include <memory>
#include <utility>
#include <vector>
// g++-14 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long

ll inv_mod_prime(ll a, ll MOD) {
  return a <= 1 ? a : MOD - (MOD/a) * inv_mod_prime(MOD % a, MOD) % MOD;
}
// count number of bits 
// only for int64 and int32
//__builtin_popcount 

// void sieve(int n){ 
//     // cout << "sieved" << endl;
//     memset(lowest_divisors, 63, sizeof(lowest_divisors));
//     for(int i = 2; i <= n; ++i){ 
//         // cout << i << endl;
//         if(lowest_divisors[i] > i){ 
        
//             primes.push_back(i);
//             adj.push_back({});
//             lowest_divisors[i] = primes.size()-1;
//             for(int j = i+i; j <= A_SIZE; j+= i){ 
//                 lowest_divisors[j] = min(lowest_divisors[j], int(primes.size()-1));
//             }
//         }
//     }
//     for(int i = n; i <= A_SIZE; ++i){ 
//         if(lowest_divisors[i] > i){ 
//             lowest_divisors[i] = primes.size();
//             primes.push_back(i);
//             adj.push_back({}); 
//         }
//     }
// }

int maxWrapper(int a, int b) {
    return std::max(a, b);
}

int minWrapper(int a, int b) {
    return std::min(a, b);
}
#pragma endregion

//range, (max,min)
map< pair<int,int>, pair<int,int> > sortable_segments;
int p[2'00'001];

struct Segment{
    int start;
    int end; 
    int min; 
    int left, right; 
    Segment(int s, int e, ll v): start(s), end(e), min(v){ 
        
    }
};
vector<Segment> min_segment_tree; 
vector<Segment> max_segment_tree; 
int build(int start, int end, vector<Segment>& segment_tree, int (*func)(int, int)){ 
    int ind = segment_tree.size();
    segment_tree.push_back(Segment(start, end, 0));
    if(start == end){ 
        segment_tree[ind].min = p[start];
        return ind; 
    }
    int mid = (start+end)/2; 
    int left = build(start, mid, segment_tree, func);
    int right = build(mid+1, end, segment_tree, func);
    segment_tree[ind].left = left;
    segment_tree[ind].right = right;
    segment_tree[ind].min = func(segment_tree[left].min, segment_tree[right].min);
    return ind;
}
int query_tree(int root, int start, int end, vector<Segment>& segment_tree,  int (*func)(int, int)){ 
    Segment& seg = segment_tree[root];
    if(seg.start == start && seg.end == end){ 
        return seg.min; 
    }
    int mid = (seg.start+seg.end)/2;
    if(end <= mid){ 
        return query_tree(seg.left, start, end, segment_tree, func);
    }else if(start > mid){ 
        return query_tree(seg.right, start, end, segment_tree, func);
    }else{ 
        int left;
        int right;
        if(seg.end == end){ 
            left =  segment_tree[seg.right].min;
        }else{ 
            left = query_tree(seg.right, mid+1, end, segment_tree, func);
        }
        if(seg.start == start){
            right = segment_tree[seg.left].min;
        }else{ 
            right = query_tree(seg.left, start, mid, segment_tree, func);
        }
        return func(left, right);
    }

}

pair<int,int> get_max_min(int start, int end){ 
    int max_val = query_tree(0, start, end, max_segment_tree, maxWrapper);
    int min_val = query_tree(0, start, end, min_segment_tree, minWrapper);
    return {min_val, max_val};
}
pair<int,int> get_max_min(pair<int,int> range){ 
    return get_max_min(range.first, range.second);
}
bool is_unordered(pair<int,int> first, pair<int, int> second){ 
    return first.second > second.first;
}
int unordered = 0;
int n, q; 
string s; 
void merge(pair<int,int> first_seg, pair<int,int> pre_max_min,  pair<int, int> second_seg, pair<int,int> cur_max_min){ 
    // cout << "merged" << endl;
    unordered -= is_unordered(pre_max_min, cur_max_min);
    int max_val = max(cur_max_min.second, pre_max_min.second);
    int min_val = min(cur_max_min.first, pre_max_min.first);
    sortable_segments.erase(first_seg); //log
    sortable_segments.erase(second_seg); //log
    sortable_segments[{first_seg.first, second_seg.second}] = {min_val, max_val}; //log
}
void shift_one_up(pair<int,int> first_seg, pair<int,int> pre_max_min,  pair<int, int> second_seg, pair<int,int> cur_max_min){
    unordered -= is_unordered(pre_max_min, cur_max_min);
    sortable_segments.erase(first_seg); //log
    sortable_segments.erase(second_seg); //log
    first_seg.second += 1; 
    second_seg.first +=1; 
    auto  first_mins = get_max_min(first_seg); //log
    auto  second_mins = get_max_min(second_seg); //log
    sortable_segments[first_seg] = first_mins; //log
    sortable_segments[second_seg] = second_mins; //log
    unordered += is_unordered(first_mins, second_mins);
}
void break_up(pair<int,int> cur_seg, int mid){ 
    pair<int,int> left = {cur_seg.first, mid-1};
    pair<int,int> right = {mid, cur_seg.second};
    sortable_segments.erase(cur_seg); //log
    auto left_mins = get_max_min(left); //log
    auto right_mins = get_max_min(right); //log
    unordered += is_unordered(left_mins, right_mins);
    sortable_segments[left] = left_mins;  //log
    sortable_segments[right] = right_mins; //log
}

bool change_ordering(int query){ 
    auto itr = sortable_segments.lower_bound({query, n+1});
    --itr;
    auto [cur_range, cur_max_min] = *itr;
    // cout << query << endl;
    // cout << cur_range.first << " " << cur_range.second << endl;
    if(s[query] == 'R'){ 
        //merge
        if(s[query-1] == 'R' && s[query+1] == 'L'){
            --itr; 
            auto [pre_range, pre_max_min] = *itr; 
            merge(pre_range, pre_max_min, cur_range, cur_max_min);
        }else if (s[query-1] == 'L' && s[query+1] == 'R'){ 
            --itr; 
            auto [pre_range, pre_max_min] = *itr; 
            shift_one_up(pre_range, pre_max_min, cur_range, cur_max_min);
        }else if (s[query-1] == 'R' && s[query+1] == 'R'){ 
            break_up(cur_range, query);
        }
        s[query] = 'L';
    }else{ 
        if(s[query+1] == 'L' && s[query-1] == 'L'){
            break_up(cur_range, query);
        }else if (s[query-1] == 'L' && s[query+1] == 'R'){ 
            ++itr; 
            auto [front_range, front_max_min] = *itr; 
            shift_one_up(cur_range, cur_max_min, front_range, front_max_min);
        }else if (s[query+1] == 'R' && s[query-1] == 'R'){ 
            //merge
            ++itr; 
            auto [front_range, front_max_min] = *itr; 
            merge(cur_range, cur_max_min, front_range, front_max_min);
        }
        s[query] = 'R';
    }
    return unordered == 0;
}

void solve(){
    min_segment_tree.clear();
    max_segment_tree.clear();
    sortable_segments.clear();

    unordered = 0;
    cin >> n >> q;
    for(int i =1; i <= n; i++){ 
        cin >> p[i];
    }
    build(1, n, min_segment_tree, minWrapper); //nlogn
    build(1, n, max_segment_tree, maxWrapper); //nlogn

    s = 'R';
    for(int i = 1; i <= n; i++){ 
        char c; 
        cin >> c; 
        s += c;
    }
    int start = 1; 
    int end = 1; 
    bool switched = false;
    // cout << s << endl;
    pair<int,int> previous = {0,0};
    
    for(int i = 1; i <= n; i++){ 
        if(s[i] != s[i-1]){ 
            //start of new range
            // cout << "here" << endl;
            if(switched == true){ 
                pair<int,int> max_min = get_max_min(start, end);
                if(max_min.first < previous.second){ 
                    unordered += 1;
                }
                previous = max_min;
                sortable_segments[{start,end}] = max_min;
                switched = false;
                start = i;
            }else{ 
                switched = true;
            }
        }
        end = i;
    }
    //last one
    {
        pair<int,int> max_min = get_max_min(start, end);
        sortable_segments[{start,end}] = max_min;
        if(max_min.first < previous.second){ 
            unordered += 1;
        }
        previous = max_min;
    }

    for(int i =0; i < q; i++){ 
        int query; 
        cin >> query; 
        if (change_ordering(query)){ 
            cout << "YES\n";
        }else{ 
            cout << "NO\n";
        }
    }


}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t; 
    cin >> t; 
    min_segment_tree.reserve(400'000);
    max_segment_tree.reserve(400'000);
    while(t--){
        solve();
    }
    return 0;
}