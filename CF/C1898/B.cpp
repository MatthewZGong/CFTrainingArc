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
int a[2'00'001];
int solve(){
    int n; 
    cin >> n;
    ll res = 0;
    for(int i =0; i <= n-1; i++){ 
        cin >> a[i]; 
    }
    int last = a[n-1];
    for(int i =n-1; i >= 0; i--){
        if(a[i] <= last){ 
            last = a[i];
        }else{ 
            int steps = (a[i]+last-1)/last;
            // cout << a[i]<< " " << last << " " << steps << endl;
            res += steps-1;
            last = a[i]/steps;
        }
    }
    cout << res << endl;
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
