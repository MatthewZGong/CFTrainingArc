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
int n;
int h[1'00'002]; 
bool works[1'00'001];
void solve(){
    cin >> n;

    for(int i = 0; i < n; i++){ 
        cin >> h[i];
        works[i+1] = false;
    }
    h[n] = 0; 
    h[n+1] = 0;
    for(int i = 0; i < n; i++){ 
        works[h[i]] = works[h[i]] || (h[i] == h[i+1] || h[i] == h[i+2]); 
    }
    int neg = true;
    for(int i = 1; i <= n; i++){ 
        if(works[i]){ 
            if(neg == false){ 
                cout << " ";
            }
            neg = false; 
            cout << i;
        }
    }
    if(neg){ 
        cout << "-1";
    }
    cout << endl;

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
