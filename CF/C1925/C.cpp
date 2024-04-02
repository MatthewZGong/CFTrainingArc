#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
// void Sieve(){
//     memset(vis, true, sizeof(vis));
    
//     vis[0] = vis[1] = false;
//     for(int i = 4 ; i < N ; i += 2)
//         vis[i] = false;
//     for(int i = 3 ; i < N / i ; i += 2){
//         if(!vis[i])continue;
//         for(int j = i * i ; j < N ; j += i + i)
//             vis[j] = false;
//     }
// }

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

bool seen[26];
void solve(){
    // cout << "test" << endl;
    int n, k, m; 
    string s; 
    cin >> n >> k >> m; 
    cin >> s; 
    int filled = 0;
    int count = 0; 
    memset(seen, 0, k);
    string res = "";
    for(int i = 0; i < m; i++){ 
        char c = s[i];
        int ind = c-'a';
        if(ind < k && !seen[ind]){ 
            count += 1; 
            seen[ind] = true; 
        }
        if(count == k){ 
            res += c;
            filled++;
            count = 0;
            memset(seen, 0, k);
        }
    }
    if(filled < n){ 
        cout << "NO" << endl;
        for(int i = 0; i < k; i++){ 
            if(!seen[i]){ 
                res += string(n - filled, 'a'+i);
                cout << res << endl;
                return;
            }
        }
    }else{
        cout << "YES" << endl;
    }
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
