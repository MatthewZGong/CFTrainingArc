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



void solve(){
    int n; 
    string a1; 
    string a2; 
    cin >> n; 
    cin >> a1 >> a2;
    string path;
    int res = 1;
    int i = 0;
    for(; i < n; i++){ 
        path += a1[i];
        if(i == n-1 || a1[i+1] == '1' && a2[i] == '0'){
            break;
        }
    }

    for(int j = i; j < n; j++){ 
        path += a2[j];
    }
    for(i = i-1; i >= 0; i--){ 
        if(a1[i+1] == a2[i]) res++; 
        else break;
    }
    cout << path << endl;
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
    return 0;
}
