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
ll rangs[300][300];
ll res[300];
void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){ 
        for(int j = i; j < n; j++){ 
            cin >> rangs[i][j-i];
        }
    }
    if(n == 1){ 
        cout << 0 << endl;
        return;
    }
    int i = 1;
    res[0] = 0;
    for(int i = 1; i < n; i++){ 
        // cout << rangs[i-1][i] << endl;
        if(rangs[i-1][1] == 0){ 
            res[i] = res[i-1];
        }else{ 
            int j = i-1; 
            while(j >= 0 && res[i-1] == res[j]){ 
                j--;
            }
            if(j == -1){ 
                res[i] = rangs[i-1][1];
            }else{ 
                ll diffs1 = rangs[i-1][1]; 
                ll diffs2 = rangs[j][i-j];
                
                ll option1 = res[i-1]+diffs1;
                ll option2 = res[i-1]-diffs1; 
                
                if(abs(option1-res[j]) > diffs2){ 
                    res[i] = option2;
                }else{
                    res[i] = option1;
                }
                
            }
        }
    }
    ll lowest = *min_element(res, res+n);
    for(int i = 0; i < n; i++){ 
        cout << res[i]-lowest << " ";
    }
    cout << endl;

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
