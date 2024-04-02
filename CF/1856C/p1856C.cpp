//https://codeforces.com/contest/1856/problem/C
#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
void print(int v[], int n){
    for(int i =0 ; i < n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
#pragma endregion


int a[1005];
int n; 
int k;
// int dp[1005];
int res;

bool works(int target, int i){ 
    int ck = k;
    for(; i <= n; i++){ 
        if(a[i] >= target) return true;
        int cost = target-a[i]; 
        ck -= cost;
        if(ck < 0) return false;
        target -= 1;
    }
    return false;
};
bool possible(int target){ 
    for(int i =1; i <=n; i++){ 
        if(works(target, i)) return true;
    }
    return false;
}

int solve(){
    // cout << "-------------" << endl;
    cin >> n >> k; 
    int start = 0;
    for(int i =1; i <= n; i++){ 
        cin >> a[i];
        start = max(a[i], start);
    }
    int end = start+n; 
    while(start < end){ 
        int mid = (start+end+1)/2; 
        // cout << start << " " << end << " " << mid << endl; 
        if(possible(mid)){ 
            start = mid;
        }else{ 
            end = mid-1;
        }
    }
    cout << start << endl;
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
    return 0;
}
