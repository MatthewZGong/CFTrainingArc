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
const ll INF = 1e18+1;
const ll NINF = -INF;
ll a[500];
vector<ll> sums; 
vector<ll> sums_at_index[500];

void solve(){
    int n; 
    cin >> n; 
    for(int i =0; i < n; i++){ 
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){ 
        ll cur_sum = 0; 
        for(int j = i; j < n; j++){ 
            cur_sum += a[j];
            sums.push_back(cur_sum);
            for(int k = i; k <= j; k++){ 
                sums_at_index[k].push_back(cur_sum);
            }
        }
    }
    sort(sums.begin(), sums.end());
    // print(sums);
    for(int i = 0; i < n; i++){ 
        sort(sums_at_index[i].begin(), sums_at_index[i].end());
        // print(sums_at_index[i]);
        vector<ll> excluded_sum; 
        ll res = INF;
        int ind = 0;
        int j = 0;
        ll prev = -1;
        while(j < sums.size()){
            while(ind <  sums_at_index[i].size() && sums_at_index[i][ind] == sums[j]) { 
                excluded_sum.push_back(sums[j]);
                ind++;
                j++;
                // excluded_sum.push_back(sums[j]);
            }
            // print(excluded_sum);
            while(excluded_sum.size()){ 
                if(j < sums.size())
                    res = min(res, abs(sums[j] - excluded_sum.back()));
                if(prev != -1)
                    res = min(res, abs(sums[prev]-excluded_sum.back()));
                excluded_sum.pop_back();
            }
            prev = j;
            j++;
        }
        cout << res << endl;
    }
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
        
        solve();

}
