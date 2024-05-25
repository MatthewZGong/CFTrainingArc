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
int res[3000][2];

bool solve_axis(priority_queue<tuple<int,int, int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> &ranges, int n, int axis){
    priority_queue<tuple<int, int>, vector<tuple<int,int>>, greater<tuple<int,int>>> active_ranges;
    for(int i = 1; i <= n; i++){ 
        while(active_ranges.size() && get<0>(active_ranges.top()) < i){
            active_ranges.pop();
        }
        while(ranges.size() && get<0>(ranges.top()) <= i){
            auto [start,end,ind] = ranges.top();
            active_ranges.push({end,ind});
            ranges.pop();
        }
        if(active_ranges.size() == 0){
            return false;
        }else{ 
            auto [end,ind] = active_ranges.top();
            active_ranges.pop();
            res[ind][axis] = i;
        }
    }
    return true;
}

void solve(){
    int n; 
    cin >> n;
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> x_ranges;
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> y_ranges;
     
    for(int i =0; i < n; i++){ 
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x_ranges.push({x1,x2, i});
        y_ranges.push({y1,y2, i});
    }
    // cout << "got here" << endl;
    bool works = solve_axis(x_ranges, n, 0);
    works = works &&solve_axis(y_ranges, n, 1);
    if(works){
        for(int i =0; i < n; i++){ 
            cout << res[i][0] << " " << res[i][1] << endl;
        }
    }else{ 
        cout <<"NIE" << endl;
    }


}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
        
    solve();
    return 0;
}
