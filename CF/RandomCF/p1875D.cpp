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


int a[5000];
int dp[5001][5001];
int solve(int index, int mex){ 
    if(index == 0){ 
        return mex*(a[index]-1);
    }
    if(dp[index][mex] != -1){ 
        return dp[index][mex];
    }
    int cost = mex*(a[index]-1)+index+solve(index-1, index);
    int skip = solve(index-1, mex);
    // cout << index << " " << mex <<  " " << cost << endl;
    return dp[index][mex] = min(cost, skip);
    
}
int solve(){
    memset(a, 0, sizeof(a));
    // memset(dp,0,sizeof(dp));
    int n; 
    cin >> n;
    for(int i =0; i < n; i++){ 
        int val;
        cin >> val;
        if(val < 5000) a[val]++;
    }
    int mex = 0; 
    while(mex < 5000 && a[mex] != 0) mex++; 
    for(int i =0;i <= mex; i++){ 
        for(int j = 0; j <= mex; j++){ 
            dp[i][j] = -1;
        }
    }
    if(mex == 0){ 
        cout << 0 << endl;
        return 0; 
    }
    cout << solve(mex-1, mex) << endl;
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
