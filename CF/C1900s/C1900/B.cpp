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
int solve(){
    int a, b, c;
    cin >> a >> b >> c; 
    int bc = abs(b-c);
    if(bc%2 == 0){ 
        cout << 1 << " ";
    }else{ 
        cout << 0 << " ";
    }
    int ac = abs(a-c);
    if(ac%2 == 0){
        cout << 1 << " ";   
    }else{
        cout << 0 << " ";
    }
    int ab = abs(a-b);
    if(ab%2 == 0){
        cout << 1 << endl;
    }else{
        cout << 0 << endl;
    }
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
