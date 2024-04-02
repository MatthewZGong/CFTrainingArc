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

ll solve(){
    ll n, m, k;
    cin >> n >> m >> k;
    if(k > 3) return 0; 
    else if(k == 1) return 1;
    else{ 
        ll multiple = m/n;
        if(k == 2){ 
            return multiple+min(n-1, m);
        }else{ 
            return max((m-n+1 )-multiple, 0ll);
        }
    }
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t; 
    cin >> t; 
    while(t--){
        
        cout << solve() << endl;
    }

}
