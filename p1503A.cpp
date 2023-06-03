#include<bits/stdc++.h>

using namespace std;


void solve(){
    int n;
    cin >> n; 
    string s(n, '?');
    int c = 0;
    for(int i = 0; i < n; ++i){
        cin >> s[i]; 
        if(s[i] == '1'){
            c++;
        }
    }
    if(c%2 == 1){
        cout << "NO" << endl; 
        return;
    }
    if(s[0] == '0' || s[n-1] == '0'){
        cout << "NO" << endl; 
        return;
    }
    string a(n, '?'); 
    string b(n, '?'); 
    int ones = 0;
    int zeros = 0;
    for(int i = 0 ; i < n; ++i){
        if(s[i] == '1'){
            if(ones < c/2){
                a[i] = '(';
                b[i] = '(';
            }else{
                a[i] = ')';
                b[i] = ')';
            }
            ones++;
        }else{
            // a[i] = '(';
            // b[i] = ')';
            if(zeros % 2 == 0){
                a[i] = '(';
                b[i] = ')';
            }
            else{
                a[i] = ')';
                b[i] = '(';
            }
            zeros++;
        }


    }
    cout << "YES" << endl;
    cout << a << endl; 
    cout << b << endl;
    return; 

}
void prnt(int v[], int n){
    for(int i =0 ; i < n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){ 
    int t; 
    cin >> t; 
    for(int i = 0; i < t; ++i){
        solve();
    }

}
