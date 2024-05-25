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
#pragma endregion
struct Segment{
    int start;
    int end; 
    int min; 
    int left, right; 
    Segment(int s, int e, ll v): start(s), end(e), min(v){ 
        
    }


};


int n,q; 
ll x[200'001];
vector<Segment> segment_tree; 


int build(int start, int end){ 
    int ind = segment_tree.size();
    segment_tree.push_back(Segment(start, end, 0));
    if(start == end){ 
        segment_tree[ind].min = x[start];
        return ind; 
    }
    int mid = (start+end)/2; 
    int left = build(start, mid);
    int right = build(mid+1, end);
    segment_tree[ind].left = left;
    segment_tree[ind].right = right;
    segment_tree[ind].min = min(segment_tree[left].min, segment_tree[right].min);
    return ind;
}
int update(int root, int ind, ll val){ 
    Segment& seg = segment_tree[root];
    if(seg.start == ind && seg.end == ind){ 

        seg.min = val;
        return val; 
    }
    int mid = (seg.start+seg.end)/2;
    int value = 0;
    if(ind > mid){ 
        value = update(seg.right, ind, val);
        seg.min = min(value, segment_tree[seg.left].min);
    }else{ 
        value = update(seg.left, ind, val);
        seg.min = min(value, segment_tree[seg.right].min);
    }
    return seg.min;
}
int query_sum(int root, int start, int end){ 
    Segment& seg = segment_tree[root];
    if(seg.start == start && seg.end == end){ 
        return seg.min; 
    }
    int mid = (seg.start+seg.end)/2;
    // cout << mid << " " << start << " " << end << endl;
    if(end <= mid){ 
        return query_sum(seg.left, start, end);
    }else if(start > mid){ 
        return query_sum(seg.right, start, end);
    }else{ 
        int left;
        int right;
        if(seg.end == end){ 
            left =  segment_tree[seg.right].min;
        }else{ 
            left = query_sum(seg.right, mid+1, end);
        }
        if(seg.start == start){
            right = segment_tree[seg.left].min;
        }else{ 
            right = query_sum(seg.left, start, mid);
        }
        return min(left, right);
    }

}


void solve(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){ 
        cin >> x[i];
    }
    // for(int i =0; i < n; i++){ 
    //     prefix[i+1] = prefix[i] + x[i];
    // }
    build(1, n);
    // for(Segment seg: segment_tree){
    //     cout <<seg.start << " " << seg.end << " " << seg.min << endl;
    // }
    for(int i =0; i < q; i++){
        int type;
        cin >> type;
        if(type == 1){
            int k, u;
            cin >> k >> u;
            update(0, k, u);
        }else if(type == 2){
            int a, b; 
            cin >> a >> b;
            // cout << "start: " << a << " " << b << endl;
            cout << query_sum(0, a, b) << endl;
        }
    }
    
    // for(Segment seg: segment_tree){
    //     cout <<seg.start << " " << seg.end << " " << seg.min << endl;
    // }



}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();
    return 0;
}
