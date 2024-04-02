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
int getSum(string& s){ 
    int sum = 0; 
    for(int i =0; i < s.size(); i++){ 
        sum += s[i]-'0'; 
    }
    return sum; 
}
string strs [2'00'005];
int solve(){
    map<pair<int,int>, int > tickets; 
    int n; 
    cin >> n; 
    for(int i =0;i < n; i++){
        cin >> strs[i]; 
        auto it = tickets.try_emplace({strs[i].size(), getSum(strs[i])}, 0); 
        it.first->second += 1;  
    }
    ll ans = 0; 
    for(int i = 0; i < n; i++){ 
        string& s = strs[i];
        int total1 = getSum(s);
        int total2 = getSum(s);
        int size = s.size();
        ans -= tickets[{size, total1}];
        for(int j = 0; size > 0; j++){
            ans += tickets[{size, total1}] + tickets[{size, total2}];
            size -= 2;
            total1 -= 2*(s[j]-'0');
            total2 -= 2*(s[s.size()-1-j]-'0');
        }
    }
    cout << ans << endl; 
    return 0;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    // int t; 
    // cin >> t; 
    // while(t--){
        
        solve();
    // }

}
