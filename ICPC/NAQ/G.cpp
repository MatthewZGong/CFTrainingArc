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
#pragma endregion
int problems[55];
void solve(){
    int n, l; 
    cin >> n >> l; 
    for(int i =0; i < n; i++){
        cin >> problems[i];
    }
    int total = l*5;
    sort(problems, problems+n);
    int res = 0;
    for(int i =0; i < n; i++){
        total -= problems[i];
        if(total >= 0){ 
            res++;
        }
    }
    cout << res << '\n';
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();
}
