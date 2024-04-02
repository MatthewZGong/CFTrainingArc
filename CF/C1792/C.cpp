#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
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
int p[200'000];
void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){ 
        cin >> p[i];
    }
    int ans = n/2; 
    int inOrder = 0;
    int left = -1, right = -1;
    int left_target, right_target;
    // cout << "start: " << n  << " " << n/2 << " " << n/2+1 << endl;
    // print(p, n);
    if(n%2 == 1){ 
        left = find(p, p+n, n/2+1) - p;
        right = left;
        left_target = n/2+1; 
        right_target = n/2+1;
        // cout << left << " " << right << endl;
    }else{
        left = find(p, p+n, n/2) - p;
        right = find(p, p+n, n/2+1) - p;
        if(left > right){
            cout << ans << endl;
            return;
        }
        inOrder = 1;
        left_target = n/2;
        right_target = n/2+1;
    }
    while(left >= 0 && right < n){ 
        while(left >= 0 && p[left] != left_target-1){ 
            left--;
        }
        left_target--; 
        while(right < n && p[right] != right_target+1){
            right++;
        }
        right_target++;
        if(left >= 0 && right < n){ 
            inOrder++;
        }
    }
    cout << ans-inOrder << endl;
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
