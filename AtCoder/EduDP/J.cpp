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
double dp[305][305][305];
int n;
double solve(int one, int two, int three){
    if(one == 0 && two == 0 && three == 0){
        return 0;
    }
    if(one < 0 || two < 0 || three < 0){
        return 0;
    }
    if(dp[one][two][three] > -0.5){
        return dp[one][two][three];
    }
    double i = one; 
    double j = two; 
    double k = three;
    double sum = one+two+three;
    dp[one][two][three] = (n + i*solve(one-1, two, three) + j*solve(one+1, two-1, three) + k*solve(one, two+1, three-1))/sum;
    // cout << dp[one][two][three] << endl;
    return dp[one][two][three];
}
void solve(){
    int one = 0; 
    int two = 0 ; 
    int three = 0; 
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for(int i =0; i < n; i++){ 
        int a;
        cin >> a; 
        if(a == 1){
            one++;
        }else if(a == 2){
            two++;
        }else{
            three++;
        }
    }
    int asdf = n;
    // for(int i =0; i <= asdf ; i++){ 
    //     for(int j =0; j <= asdf; j++){ 
    //         for(int k =0; k <= asdf; k++){ 
    //             cout << dp[i][j][k] << " ";
    //         }
    //     }
    // }
    // cout << one << " " << two << " " << three << endl;
    solve(one, two, three);
    cout << fixed << setprecision(10) << dp[one][two][three] << endl;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();

}
