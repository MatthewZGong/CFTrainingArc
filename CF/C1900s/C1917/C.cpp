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
int a[2001];
int v[100'000];
int solve(){
    ll n, k, d; 
    cin >> n >> k >> d;
    int b = 0;
    ll complete = 0;
    for(int i = 1; i <= n; i++){ 
        cin >> a[i];
        if(a[i] == i){ 
            complete++;
        }
    }
    for(int i = 0; i < k; i++){
        cin >> v[i];
    }
    ll best_score = 0; 
    // for(int i = 1; i <= d; i++){ 
    for(int i = 1; i <= min(2*n,d); i++){ 
        int vi = v[b];
        best_score = max(best_score, complete + (d-i)/2);
        for(int j = 1; j <= vi; j++){ 
            a[j]++;
            if(a[j] == j){ 
                complete++;
            }else if(a[j] == j+1){ 
                complete--;
            }
        }
        
        b++; 
        b %= k;
    }
    // if(n < d){
    //     best_score = max(best_score, complete + (d-(n+1))/2);
    // }
    cout << best_score << endl;
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
