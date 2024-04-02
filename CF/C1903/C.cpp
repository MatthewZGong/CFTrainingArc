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
// int solve(){
//     int n; 
//     cin >> n; 
//     for(int i =0; i < n; i++){ 
//         cin >> a[i];
//     }
//     ll sum  = a[n-1]; 
//     vector<int> sizes; 
//     int length = 1;
//     for(int i = n-2; i >= 0; i--){
//         if(-sum < 0){ 
//             sizes.push_back(length);
//             length = 1;
//         }else{ 
//             length++;
//         }
//         sum += a[i];
//     }
//     sizes.push_back(length);
//     int i = 0; 
//     ll ans = 0;
//     int k = 1;
//     while(i < n){ 
//         int l = sizes[sizes.size()-1];
//         sizes.pop_back(); 
//         for(int j = 0; j < l; j++){ 
//             ans += k*a[i];
//             i++;
//         }
//         k++;
//     }
//     cout << ans << endl;
//     return 0;
// }
int solve(){
    int n; 
    cin >> n; 
    for(int i = 0; i < n; i++){ 
        cin >> a[i];
    }
    ll sum = 0; 
    ll ans = 0; 
    for(int i = n-1; i >= 0; i--){
        sum += a[i];
        if(i > 0 && sum > 0)
            ans += sum;
    }
    ans += sum;
    cout << ans << endl;
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
