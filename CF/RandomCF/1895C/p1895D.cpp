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
bool nums[2'00'000];
int a[2'00'000];
int b[2'00'000];
int n;
bool solve_right(int i, int current){
    b[i] = current;
    if(i == n-1){ 
        return true;
    }
    int next = current^a[i];
    if(next < n && !nums[next]){
        nums[next] = true;
        return solve_right(i+1, next);
    }else{
        return false;
    }

}
bool solve_left(int i, int prev){ 
    if(i < 0){
        return true;
    }
    int current = prev^a[i];
    b[i] = current;
    if(current < n && !nums[current]){
        nums[current] = true;
        return solve_left(i-1, current);
    }else{
        return false;
    }
}
int solve(){
    cin >> n; 
    int start = 0;
    int set = 20; 
    for(int i =0; i < n-1; i++){ 
        cin >> a[i];
        int current_set = __builtin_popcount(a[i]);
        if(current_set < set){
            set = current_set;
            start = i;
        }
    }
    for(int i =0; i < n; i++){ 
        int next = i^a[start]; 
        if(next < n){ 
            memset(nums, 0, n);
            nums[i] = true; 
            nums[next] = true;
            b[start] = i;
            if(solve_right(start+1, next) && solve_left(start-1, i)){
                for(int i =0;i < n; i++){ 
                    cout << b[i] << " ";
                }
                cout << endl;
                return 0;
            }
        }
        
    }
    return 0;

}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    // int t; 
    // cin >> t; 
    // while(t--){
        
        solve();
    // }

}
