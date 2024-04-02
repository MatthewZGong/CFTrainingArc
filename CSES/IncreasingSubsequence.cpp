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
// int a[2'00'005];
int dp[2'00'005];
int search(int start, int end, int target){ 
    while(start < end){ 
        int mid = (start+end)/2; 
        if(dp[mid] < target){ 
            start = mid+1;
        }else{ 
            end = mid; 
        }
    }
    return start; 
}
int solve(){
    int n; 
    cin >> n;
    memset(dp, 63, sizeof(dp));
    dp[0] = 0; 
    int a;
    int ind;
    int res = 0;  
    for(int i =0; i < n; i++){ 
        cin >> a; 
        ind = search(0, n, a);
        if(dp[ind] > a){ 
            dp[ind] = a;
            res = max(ind, res); 
        }
    }
    return res; 
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
        
       cout << solve() << endl;

}
