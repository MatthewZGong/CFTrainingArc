#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
#pragma endregion

ll dp[1<<16];
ll score[1<<16];
int a[16][16]; 
int n;
ll get_score(int mask){
    ll s = 0;
    int i = 0;
    for(; (1 << i) < (1 << n) && !((1<<i)&mask); i++){}
    int comp = mask&( (1<<i) ^ mask); 
    s = score[comp];
    for(int j = i; (1 << j) < (1 << n); j ++){
        if((1 << j)& comp) s += a[i][j];
    }
    return score[mask] = s;
    
}
ll solve_mask(int mask){
    if(mask == 0){
        return dp[mask] = 0;
    }
    dp[mask] = get_score(mask);
    for(int submask = mask; submask; submask = (submask - 1) & mask) {
        int comp_submask = mask&(submask ^ mask); 
        dp[mask] = max(dp[submask]+dp[comp_submask], dp[mask]);
    }  
    return dp[mask];
}
void solve(){ 
    cin >> n;
    for(int i =0; i < n; i++){ 
        for(int j =0; j < n; j++){ 
            cin >> a[i][j];
        }
    }
    // for(int i =0; i < n; i++){ 
    //     for(int j =0; j < n; j++){ 
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for(int i =1; i < (1<<n); i++){ 
         solve_mask(i) ;
    }
    // for(int i =0; i < (1<<n); i++){ 
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    cout << dp[(1 << n)-1] << endl;

}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();

}
