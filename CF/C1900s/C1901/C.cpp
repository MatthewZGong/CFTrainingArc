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

int a[2'00'000];
bool is_almost_power_of_2(int n){
    while(n){ 
        if((n&1) == 0){
            return false;
        }
        n >>= 1; 
    }
    // cout << "what" << endl;
    return true;
}
int solve(){
    // cout << "------------" << endl;
    int n; 
    cin >> n; 
    for(int i =0; i < n; i++){ 
        cin >> a[i];
    }
    int max_a = *max_element(a, a+n);
    int min_a = *min_element(a, a+n);
    // cout << max_a << endl;
    if(max_a == min_a){
        cout << 0 << endl;
        return 0;
    }
    vector<int> res; 
    // print(a, n);
    while(max_a != min_a)
    {    
        if((max_a&1) == 0 && (min_a&1) == 0){
            res.push_back(0);
        }else if((max_a&1) == 0 && (min_a&1) == 1){
            max_a +=1; 
            min_a +=1;
            res.push_back(1);
        }else{ 
            res.push_back(0);
        }
        max_a >>= 1;
        min_a >>= 1;
    }
    cout << res.size() << endl;
    if(res.size() > n){ 
        return 0;
    }
    for(int i =0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
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
