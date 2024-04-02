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

char s[101];
int prefix[101];
int solve(){
    // cout << "_______________" << endl;
    int n, k; 
    cin >> n >> k; 
    for(int i =1; i <= n; i++){ 
        cin >> s[i]; 
    }
    memset(prefix, 0, sizeof(prefix)); 
    prefix[1] = (s[1] == 'B');
    for(int i = 2; i <= n; i++){ 
        prefix[i] = prefix[i-1] + (s[i] == 'B');
    }
    if(prefix[n] == k){
        cout << 0 << endl; 
        return 0;
    }

    cout << 1 << endl;
    for(int i =1; i <= n; i++){ 
        int left = prefix[i]; 
        int right = prefix[n]-prefix[i]; 
        // cout << left << " " << right << endl;
        if(right == k){ 
            
            cout << i << ' ' << 'A' << endl; 
            return 0; 
        }
        if((i)+right == k){ 
            cout << i  << " " << 'B' << endl; 
            return 0;
        }
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
