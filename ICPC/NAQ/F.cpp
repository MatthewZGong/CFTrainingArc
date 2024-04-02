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

int letters[26];
void solve(){
    char c; 
    while(cin >> c){ 
        letters[c - 'a'] += 1;
    }
    cout << letters['a'-'a']+letters['e'-'a']+letters['i'-'a']+letters['o'-'a']+letters['u'-'a'] << ' ';
    cout << letters['a'-'a']+letters['e'-'a']+letters['i'-'a']+letters['o'-'a']+letters['u'-'a']+letters['y'-'a'] << '\n';
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();
}
