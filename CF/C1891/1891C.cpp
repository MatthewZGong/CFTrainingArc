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

ll hordes[2'00'005];
int solve(){
    int n; 
    cin >> n;
    for(int i =0; i < n; i++){ 
       cin >> hordes[i];
    }
    sort(hordes,hordes+n); 
    int start = 0; 
    int end = n-1; 
    ll actions = 0; 
    ll x =0;
    while(start < end){ 
        if(x+hordes[start] < hordes[end]){ 
            x += hordes[start];
            actions += hordes[start];
            hordes[start] = 0; 
            start++;
        }else if(x+hordes[start] == hordes[end]){ 
            actions += hordes[start]+1;
            hordes[start] = 0; 
            hordes[end] = 0; 
            x = 0; 
            start++;
            end--;
        }else{ 
            hordes[start] -= (hordes[end]-x); 
            actions += (hordes[end]-x)+1;  
            x = 0; 
            hordes[end] = 0;
            end--;
        }

    }
    if(hordes[start] != 0 && hordes[start] != 1)
        actions += (hordes[start]-x+1)/2+1;
    else 
        actions += hordes[start];
    cout << actions << endl;
    return actions;
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
