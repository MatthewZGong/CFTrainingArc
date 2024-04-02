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

int solve(int n, string& s, int x, int y){ 
    int aset = 0; 
    int bset = 0;
    int i = 0;
    while(aset < y && bset < y && i < s.size()){ 
        int awin = 0; 
        int bwin = 0; 
        while(awin < x && bwin < x && i < s.size()){ 
            awin += s[i] == 'A'; 
            bwin += s[i] == 'B';
            i++;
        }
        aset += (awin == x);
        bset += (bwin == x);
        if(awin != x && bwin != x) return 0;
    }
    // cout << i << endl;
    if(i < s.size()) return 0;
    if(aset != y && bset != y){ 
        return 0;
    }
    if(aset == y){ 
        return 1;
    }
    return 2;

}

int solve(){
    int n; 
    cin >> n; 
    string s; 
    cin >> s; 
    int res = 0;
    // cout << n << " " <<  s << endl;
    // cout << solve(n, s, 1, 3) << endl;
    for(int i =1; i <= n; i++){ 
        for(int j = 1; j <= n; j++){ 
            int current = solve(n, s, i,j);
            // cout << current << " " << i << " " << j << endl;
            if(res == 0){ 
                res = current; 
            }else if(current != 0 && res != current){ 
                cout << "?" << endl;
                return 0;
            }
        }
    }
    if(res == 0){ 
        cout << "?" << endl;
    }else if(res == 1){ 
        cout << "A" << endl;
    }else{ 
        cout << "B" << endl;
    }
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
