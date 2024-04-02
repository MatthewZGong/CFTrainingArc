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

int v[30];
void get(size_t n){ 
    int need = 0;
    for(int i = 29; i >= 0; i--){ 
        if(n & (1 << i)){ 
            need += 1;
        }
        // cout << i << ": " << need << endl;
        need -= v[i]; 
        need = max(need, 0);
        need <<= 1; 
    }
    if(need == 0){ 
        cout << "YES" << endl;
    }else{ 
        cout << "NO" << endl;
    }
}
int solve(){
    int m; 
    cin >> m;
    for(int i =0; i < m; i++){ 
        size_t t, vi; 
        cin >> t >> vi;
        if(t == 1){ 
            v[vi]++;
        }else{ 
            get(vi);
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

        
        solve();
    
    return 0;
}
