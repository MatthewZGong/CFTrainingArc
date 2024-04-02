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
vector<vector<vector<int>>> dp;
tuple<int,int,int> friends[2000];
void solve(){
    int a, b;
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++){
        int p, c, x; 
        cin >> p >> c >> x; 
        friends[i] = {x, c, p};
    } 
    sort(friends, friends+n);

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
