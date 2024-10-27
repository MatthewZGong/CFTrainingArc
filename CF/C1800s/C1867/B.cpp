#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
void print(int v[], int n){
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
// int[] val;
void solve(){
    int a, b, c; 
    cin >> a >> b >> c; 
    // cin >> val[0] >> val[1] >> 
    if(a == b && b == c){ 
        cout << "YES" << endl; 
        return;
    }
    if(c < b){ 
        swap(b,c);
    }
    if(b < a){ 
        swap(a, b);
    }
    if(c < b){ 
        swap(b,c);
    }
    int res = 0;
    if(b%a != 0){ 
        cout << "NO" << endl;
        return;  
    }
    res += (b/a-1); 
    if(c%a != 0){ 
        cout << "NO" << endl;
        return;
    }
    res += (c/a-1);
    if(res > 3){ 
        cout << "NO" << endl; 
    }else{ 
        cout << "YES" << endl;
    }
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
