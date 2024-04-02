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
char start;
bool in_cycle = false;
int comp;


int dfs(unordered_map<char, char>& mp, char c, unordered_set<char>& visited,  unordered_map<char, int>& component){
    if(visited.count(c)){ 
        if(start == c){ 
            in_cycle = true;
        }
        if(component.find(c) != component.end()){
            comp = component[c];
        }
    
        return 0;
    }
    visited.insert(c);
    if(mp.find(c) != mp.end()){ 
        if(mp[c] == c){ 
            return 0;
        }
        int res = dfs(mp, mp[c], visited, component);
        component[c] = comp;
        return 1+res;
    }
    return 0;
}
int solve(){
    string source; 
    string target; 
    cin >> source >> target;
    unordered_map<char, char> mp;
    unordered_set<char> target_set;
    if(source == target){ 
        cout << "0" << endl;
        return 0;
    }
    for(int i =0 ; i < source.size(); ++i){
        char s = source[i];
        char t = target[i];
        // cout << s << " " << t << endl;
        target_set.insert(t);
        if(mp.find(s) == mp.end()){
            mp[s] = t;
        }else if(mp[s] != t){
            cout << "-1" << endl;
            return 0;
        }
    }
    if(target_set.size() == mp.size() && target_set.size() == 52){
        cout << "-1" << endl;
        return 0;
    }
    unordered_set<char> visited; 
    unordered_map<char, int> component;
    vector<bool> isLoop; 
    int res =0;
    for(char i = 'A'; i <= 'Z'; ++i){
        if(!visited.count(i) && mp.find(i) != mp.end()){
            start = i;
            in_cycle = false;
            comp = isLoop.size();
            res += dfs(mp, i, visited, component);    
            if(comp != isLoop.size()){
                isLoop[comp] = in_cycle;
            }else{  
                isLoop.push_back(in_cycle);
            }
        }
    }
    for(char i = 'a'; i <= 'z'; ++i){
        if(!visited.count(i) && mp.find(i) != mp.end()){
            start = i;
            in_cycle = false;
            comp = isLoop.size();
            res += dfs(mp, i, visited, component);
            if(comp != isLoop.size()){
                isLoop[comp] = in_cycle;
            }else{  
                isLoop.push_back(in_cycle);
            }
        }
    }

    for(bool l: isLoop){
        if(l) res++;
    }
    cout << res << endl;
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
