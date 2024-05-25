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
    ll sum; 
    int left, right; 
    Segment(int s, int e, ll v): start(s), end(e), sum(v){ 
        
    }


};


int n,q; 
ll x[200'001];
vector<Segment> segment_tree; 


int build(int start, int end){ 
    int ind = segment_tree.size();
    segment_tree.push_back(Segment(start, end, 0));
    if(start == end){ 
        segment_tree[ind].sum = x[start];
        return ind; 
    }
    int mid = (start+end)/2; 
    int left = build(start, mid);
    int right = build(mid+1, end);
    segment_tree[ind].left = left;
    segment_tree[ind].right = right;
    segment_tree[ind].sum = segment_tree[left].sum + segment_tree[right].sum;
    return ind;
}
int update(int root, int ind, ll val){ 
    Segment& seg = segment_tree[root];
    if(seg.start == ind && seg.end == ind){ 
        ll diff = val-seg.sum;
        seg.sum = val;
        return diff; 
    }
    int mid = (seg.start+seg.end)/2;
    ll diff = 0;
    if(ind > mid){ 
        diff = update(seg.right, ind, val);
    }else{ 
        diff = update(seg.left, ind, val);
    }
    seg.sum += diff;
    return diff;
}
ll query_sum(int root, int start, int end){ 
    Segment& seg = segment_tree[root];
    if(seg.start == start && seg.end == end){ 
        return seg.sum; 
    }
    int mid = (seg.start+seg.end)/2;
    // cout << mid << " " << start << " " << end << endl;
    if(end <= mid){ 
        return query_sum(seg.left, start, end);
    }else if(start > mid){ 
        return query_sum(seg.right, start, end);
    }else{ 
        ll sum = 0; 
        if(seg.end == end){ 
            sum += segment_tree[seg.right].sum;
        }else{ 
            sum += query_sum(seg.right, mid+1, end);
        }
        if(seg.start == start){
            sum += segment_tree[seg.left].sum;
        }else{ 
            sum += query_sum(seg.left, start, mid);
        }
        return sum;
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
    //     cout <<seg.start << " " << seg.end << " " << seg.sum << endl;
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
    



}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();
    return 0;
}
