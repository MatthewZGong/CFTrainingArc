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


int solve(){
    int n; 
    cin >> n;
    string s;
    cin >> s; 
    vector<char> sub;
    vector<int> ind;
    for(int i = 0; i < n; i++){ 
        while(sub.size() && s[i] > sub.back()){
            sub.pop_back();
            ind.pop_back();
        }
        sub.push_back(s[i]);
        ind.push_back(i);
    }
    // print(sub);
    for(int i = 0; i < sub.size(); i++){ 
        int index = ind[i]; 
        char ch = sub[sub.size()-1-i];
        s[index] = ch;
    }
    for(int i = 1; i < n; i++){ 
        if(s[i] < s[i-1]){
            cout << -1 << endl;
            return 0;
        }
    }
    int count = 1; 
    for(int i = 1; i < sub.size(); i++){
        if(sub[i] == sub[i-1]){ 
            count++;
        }else{ 
            break;
        }
    }
    cout << sub.size()-count << endl;
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
