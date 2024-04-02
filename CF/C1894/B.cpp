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
int b[105];
int nums[105]; 



int solve(){
    int count = 2;
    int n; 
    memset(b,0,sizeof(b));
    memset(nums, 0, sizeof(nums));
    cin >> n; 
    for(int i =0; i <n; i++ ){ 
        int a;
        cin >> a; 
        nums[a] += 1; 
        if(count < 4 && nums[a] == 2){ 
            b[i] = count; 
            count++;
        }else{ 
            b[i] = 1;
        }
    }
    if(count != 4){ 
        cout << -1 << endl;
    }else{
        for(int i =0; i < n; i++){ 
            cout << b[i] << " ";
        }
        cout << endl; 
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
