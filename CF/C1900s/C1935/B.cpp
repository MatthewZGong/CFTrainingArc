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


int a[1'00'000];
bool mex[1'00'000];
void clear_mex(int n){ 
    memset(mex, false, n);
}
void solve(){
    int n;
    cin >> n;
    clear_mex(n);
    for(int i =0; i < n; i++){ 
        cin >> a[i];
        mex[a[i]] = true;
    }
    int target_mex = 0; 
    while(mex[target_mex]) target_mex++;
    vector<int> split1; 
    vector<int> split2; 
    int split1_mex = 0;
    int split2_mex = 0;
    clear_mex(n); 
    int i = 0;
    split1.push_back(a[i]);
    mex[a[i]] = true;
    i++;
    while(mex[split1_mex]){
        split1_mex++;
    }
    while(split1_mex != target_mex && i < n){ 
        mex[a[i]] = true;
        split1.push_back(a[i++]);
        while(mex[split1_mex]){
            split1_mex++;
        }
    }
    clear_mex(n);
    while(i < n){ 
        mex[a[i]] = true;
        split2.push_back(a[i++]);
        while(mex[split2_mex]){
            split2_mex++;
        }
    }
    if(split2_mex != target_mex){ 
        cout << -1 << endl;
        return;
    }
    cout << 2 << endl;
    cout << 1  << " " <<split1.size() << endl;
    cout << split1.size()+1 << " " << n << endl;

    



}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t; 
    cin >> t; 
    while(t--){
        
        solve();
    }
    return 0;
}
