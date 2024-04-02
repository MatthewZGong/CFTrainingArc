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
int t;
pair<int,int> n[100];
vector<string> res[100]; 
void solve(){
    int start = 5; 
    int i = 0;
    if(t == 0){ 
        return;
    }
    if(n[i].first == 1){ 
        res[n[i].second].push_back("1");
        i++;
    } 
    vector<string> current = { "196", "169", "961"};
    if(i < t && n[i].first == 3){ 
        for(int j = 0; j < current.size(); j++){
            res[n[i].second].push_back(current[j]);
        }
        i++;
    }
    while(start <= 99 && i < t){ 
        string s1; 
        string s2;
        string& old_s1 = (*(current.end()-2));
        string& old_s2 = (*(current.end()-1)); 
        for(int j = 0; j < old_s1.size(); j++ ){
            s1 += old_s1[j];
            s2 += old_s2[j];
            if(old_s1[j] != '0'){ 
                s1 += "0";
            }
            if(old_s2[j] != '0'){
                s2 += "0";
            }
        }
        s1.pop_back();
        s2.pop_back();
        current.push_back(s1);
        current.push_back(s2);
        for(int j =0; j < current.size()-2; j++){
            current[j] += "00";
        }
        if(start == n[i].first){ 
            for(int j = 0; j < current.size(); j++){
                res[n[i].second].push_back(current[j]);
            }
            i++;
        }
        start += 2; 
        // cout << start << endl;
    }

    for(int i =0; i < t; i++){
        for(int j =0; j < res[i].size(); j++){ 
            cout << res[i][j] << endl;
        }
    }

}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    cin >> t;
    // cout << t << endl;
    for(int i = 0; i < t; i++){ 
        cin >> n[i].first; 
        n[i].second = i;
        // cout << n[i].first << endl;
    }
    sort(n, n+t);
    solve();

}
