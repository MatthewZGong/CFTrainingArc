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
int a[5'00'001];
int b[5'00'001];
int solve(){
    //this is porbably wrong im confused by one of the test cases;
    int n,k; 
    cin >> n >> k;
    for(int i = 1; i <= k; i++){
        int ai;
        cin >> ai;
        a[ai] = i;
    }
    for(int i =1; i <= k; i++){ 
        int bi;
        cin >> bi;
        b[bi] = i;
    }
    unordered_map<int, int> offsets;
    for(int i =1; i <= n; i++){ 
        if(b[i] != 0 && a[i] != 0){
            int ai = a[i]-1; 
            int bi = b[i]-1;
            int offset = (ai-bi+k)%k;
            bi = k-1-bi;
            int offset2 = (ai-bi+k)%k;
            offsets[offset]++;
            offsets[-offset2]++;
        }
    }
    int ans = 0;
    for(auto it: offsets){
        ans = max(ans, it.second);
    }
    for(int i = 1; i <= n; i++){
        if(a[i] == b[i] && a[i] == 0){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    // cout << (1-7 + 8)%8 << endl;
    solve();
}
