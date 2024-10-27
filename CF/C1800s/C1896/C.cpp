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


pair<int,int> a[200000];
int b[200000];
int solve(){
    int n, x; 
    cin >> n>> x; 
    // cout << n << " " << x << endl;
    for(int i = 0; i < n; i++){ 
        cin >> a[i].first;
        a[i].second = i;
    }
    for(int i =0; i < n; i++){ 
        cin >> b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    vector<pair<int,int>> res; 
    for(int i =0; i < x; i++){ 
        if(a[n-x+i].first > b[i]){
            res.push_back({a[n-x+i].second, b[i]});
        }else{ 
            // cout << n-x-i << " " << a[n-x-i].first << " " << b[i] << endl;
            cout << "NO" << endl;
            return 0;
        }
    }
    for(int i =0; i < n-x; i++){ 
        if(a[i].first <= b[x+i]){ 
            res.push_back({a[i].second, b[x+i]});
        }else{
            cout << "NO" << endl;
            return 0;
        }
    }
    sort(res.begin(), res.end());
    cout << "YES" << endl;
    for(int i =0; i < res.size(); i++){ 
        cout<< res[i].second << " ";
    }
    cout << endl;
    return 0;
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
// 2 3 4 
// 4 1 2  
// 1 2 4