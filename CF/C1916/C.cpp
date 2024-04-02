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
ll a[1'00'000];
void solve(){
    int n;
    cin >> n; 
    for(int i =0; i < n; i++){
        cin >> a[i]; 
    }
    ll sum = a[0];
    ll odd = 0; 
    ll offset = 0;

    if((a[0]&1) == 1){
        odd += (a[0]&1);
        if(odd%3 == 2){ 
            offset --;
        }else{ 
            offset ++;
        }
    }
    cout << sum << " ";
    for(int i = 1; i < n; i++){ 
        if((a[i]&1) == 1){
            odd += (a[i]&1);
            if(odd%3 == 2){ 
                offset --;
            }else{ 
                offset ++;
            }
        }
        sum  += a[i];
        cout << sum - offset << " ";
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
