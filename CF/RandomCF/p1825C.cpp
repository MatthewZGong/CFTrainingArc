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

int prefix[100'005]; 

int solve(){
    memset(prefix, 0, sizeof(prefix)); 
    int n, m; 
    cin >> m >> n; 
    int left = 0; 
    int right = 0;
    for(int i = 0; i < m; i++){ 
        int x; 
        cin >> x; 
        if(x == -1){ 
            left++;
        }else if(x == -2){ 
            right++;
        }else{ 
            prefix[x] = 1; 
        }
    }
    for(int i =1; i <= n; i++){ 
        prefix[i] += prefix[i-1];
    }  
    int ans = max(left+prefix[n-1],right+prefix[n]-prefix[0]); 
    ans = min(ans, n); 
    for(int i =1; i <= n; i++){ 
        if(prefix[i] != prefix[i-1]){ 
            int c_left = prefix[i-1];
            int c_right = prefix[n]-prefix[i]; 
            c_left += left; 
            c_right += right;
            int current = min(i-1,c_left) + min(n-i, c_right) +1; 
            ans = max(current, ans);
        }
    }
    cout << ans << endl;
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
