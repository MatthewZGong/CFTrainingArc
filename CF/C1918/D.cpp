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
int n; 
ll a[1'00'001];
ll dp[1'00'001];


bool solve(ll mid){ 
    deque<pair<ll,ll>> range;
    int back = 1; 
    ll total = 0;
    range.push_back({0,0});
    for(int i = 1; i <= n; i++ ){ 
        dp[i] = a[i]+range.begin()->first;
        while(range.size() && range.back().first >= dp[i]){ 
            range.pop_back();
        }
        range.push_back({dp[i], i});
        while(back < i && total+a[i] > mid){ 
            if(back-1 == range.begin()->second){ 
                range.pop_front();
            }
            total -= a[back];
            back ++;
        }
        total += a[i]; 
        if(total > mid){
            return false;
        }
    }
    bool res = false;
    total = 0;
    for(int i = n; i >= 1; i--){ 
        total += a[i];
        res = res || (dp[i] <= mid);

        if(total > mid){
            break;
        }
    }
    return res;
}
void solve(){
    cin >> n; 
    a[0] = 0; 
    dp[0] = 0;
    for(int i = 1; i <= n; i++){ 
        cin >> a[i];
    }
    ll left = 0;
    ll right = 1e14; 
    while(left < right){ 
        ll mid = (left+right)/2;
 
        if(solve(mid)){
            right = mid;
        }else{ 
            left = mid+1;
        }
    }
    cout << left << endl;
    
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
