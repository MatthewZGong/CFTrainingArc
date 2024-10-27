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
#pragma endregion
int n; 
int q; 
pair<int,int> range[200'000]; 
// int x[200'000]; 

void solve(){
    cin >> n; 
    for(int i = 0; i < n; i++){ 
        int l, r, a, b; 
        cin >> l >> r >> a >> b; 
        range[i] = {l, b}; 
    }
    sort(range, range+n);
    vector<pair<int,int>> true_range;
    int start = range[0].first; 
    int end = range[0].second;
    for(int i = 1; i < n; i++){ 
        auto [l, r] = range[i]; 
        if(l <= end){
            end = max(end, r);
        }else{ 
            true_range.push_back({start, end});
            start = l; 
            end = r;
        }
    }
    true_range.push_back({start, end});
    cin >> q;
    for(int i = 0; i < q; i++){
        int x;
        cin >> x;
        auto it = lower_bound(true_range.begin(), true_range.end(), x, [](pair<int,int> a ,int  b){
            return a.first <= b;
        });
        if(it == true_range.begin()){ 
            cout << x << " ";
            continue;
        }
        it = it - 1;
        if((*it).second >= x){ 
            cout << (*it).second << " ";
        }else{ 
            cout << x << " ";
        }
        
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

}
