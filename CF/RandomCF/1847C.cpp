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
int a[25];
int solve(){
    int n; 
    cin >> n;
    for(int i =1; i <= n; i++){ 
        cin >> a[i]; 
    }
    int* min_val = min_element(a+1, a+n+1); 
    int* max_val = max_element(a+1, a+n+1);
    int* largest = max_val;
    // int ind = (int)(largest-a);
    if(abs(*min_val) > *max_val) largest = min_val;
    int ind = (int)(largest-a);

    cout << (n-1)*2 << endl;
    //19
    for(int i =1; i <= n; i++){ 
        if(i != ind){
            a[i] += a[ind];
            cout << i << " " << ind << endl;
        }
    }
    if(a[ind] < 0){
        for(int i = n-1 ; i >= 1; i--){ 
            a[i] += a[i+1];
            cout << i << " " << i+1 << endl;
        } 
    }else{ 
        for(int i = 2 ; i <= n; i++){ 
            a[i] += a[i-1];
            cout << i << " " << i-1 << endl;
        }
    }
    // print1(a, n);
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
