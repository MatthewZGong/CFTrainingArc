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

ll p [750][750];
ll cp [750][750];
int solve(){
    size_t n; 
    cin >> n; 
    for(int i =0; i < n; i++){ 
        string s;
        cin >> s;
        for(int j = i+1; j < n; j++ ){
            if(s[j-(i+1)] == '1'){ 
                p[i][j] = 1;
            }
        } 
    }
    ll res = 0;
    for(int i = n-1; i >= 0; i--){ 
        for(int j = i+1; j < n; j++ ){
            if( (cp[i][j] & 1) != p[i][j]){ 
                res++;
                cp[i][j] ++;
                for(int k = j+1; k < n; k++){ 
                    cp[i][k] += cp[j][k];
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
        
        solve();
    return 0;

}
