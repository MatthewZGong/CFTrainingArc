#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
const double EPS = 1.0e-14;
#pragma endregion

pair<ll,ll> find_removed(string& s, ll pos){ 
    ll n = s.size();
    ll removed = 0;
    ll current = 0; 
    for(int i = n; i > 0 && current+i < pos ; i--){ 
        removed += 1; 
        current += i;
    }
    return make_pair(removed, pos-current);
}

char remove_n(string& s, int n, int rel_pos){
    vector<char> stack; 
    for(int i =0; i < s.size(); i++){ 
        while(stack.size() && n && stack[stack.size()-1] > s[i]){
            stack.pop_back(); 
            n -= 1;
        }
        stack.push_back(s[i]);
        
    }   
    while(n && stack.size()){
        stack.pop_back();
        n -= 1;
    }
    // for(char c : stack){ 
    //     cout << c;
    // }
    // cout << endl;
    // cout << rel_pos << endl;
    return stack[rel_pos-1];
}

int solve(){
    ll pos; 
    string s; 
    cin >> s >> pos;
    ll n = s.size();
    ll n_sum = n*(n+1)/2;
    ll back = n_sum-pos+1;
    pair<ll,ll> r = find_removed(s, pos);
    ll removed = r.first;
    ll rel_pos = r.second;
    // cout << s << " " << removed << " " << rel_pos << endl;
    cout << remove_n(s, removed, rel_pos);

}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t; 
    cin >> t; 
    while(t--){
        
        solve();
    }
    cout << endl;

}
