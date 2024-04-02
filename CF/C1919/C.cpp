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
const int INF = 1e9;
int n;
int a[2'00'000];
void solve(){
    cin >> n; 
    for(int i =0;i < n; i++){ 
        cin >> a[i];
    }
    int res = 0; 
    int current = INF; 
    int prev = INF; 
    for(int i = 0; i < n; i++){
        if(a[i] > current){ 
            res++; 
            prev = a[i];
        }else{ 
            if(a[i] > prev){ 
                current = a[i];
            }else{ 
                prev = a[i];
            }
        }
        if(current < prev){ 
            swap(prev, current);
        }

    }
    cout << res << endl;
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
