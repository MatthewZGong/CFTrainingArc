#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
void print(ll v[], ll n){
    for(ll i =0 ; i < n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
void print1(ll v[], ll n){
    for(ll i =1 ; i <= n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}

template<typename T>
void print(vector<T> v){
    for(ll i =0 ; i < v.size(); ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
#pragma endregion

int dp[100005][3];
int a[105];
int n;
int k;

int solve(int k, int player){ 
    if(dp[k][player] != 0){ 
        return dp[k][player];
    }
    if(k == 0){ 
        if(player == 1){ 
            return dp[k][player] = 2;
        }else{ 
            return dp[k][player] = 1;
        }
    } 
    int res = player == 1 ? 2 : 1;
    for(int i =0; i < n && a[i] <= k; i++){ 
        if(solve(k-a[i], player == 1 ? 2 :1) == player){ 
            res = player;
        }
    }
    dp[k][player] = res;
    return res; 
}
void solve(){ 
    cin >> n >> k; 
    for(int i =0; i < n; i++){ 
        cin >> a[i]; 
    }
    int res = solve(k, 1);
    if(res == 1){ 
        cout << "First" << endl;
    }else{ 
        cout << "Second" << endl;
    }
    

}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();

}
