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
ll inv_mod_prime(ll a, ll MOD) {
  return a <= 1 ? a : MOD - (MOD/a) * inv_mod_prime(MOD % a, MOD) % MOD;
}

#pragma endregion

int a[200'000];
int bucket[200'001];
// bool works(int mex){ 
//     vector<int> counts; 
//     for(int i = 0; i < mex; i++){ 
//         counts.push_back(bucket[i]);
//     }
//     sort(counts.begin(), counts.end()); 
//     for(int i = 0; i < mex; i++){ 
//         if(counts[i] < i+1){ 
//             return false;
//         }
//     }
//     return true;

// }

void solve(){
    int n; 
    cin >> n;
    for(int i = 0; i < n; i++){ 
        bucket[i] = 0;
    }
    for(int i = 0; i < n; i++){ 
        cin >> a[i];
        bucket[a[i]]++;
    }
    int res = 0;
    bool first = false;
    for(int i = 0; i < (n+1)/2; i++){ 
        if(bucket[i] == 0){ 
            break;
        }
        if(bucket[i] == 1){ 
            if(!first) first = true; 
            else break;
        }
        res++;

    }
    cout << res << endl;
    // int start = 0; 
    // int end = (n+1)/2; 
    // while(start < end){ 
    //     int mid = (start+end+1)/2; 
    //     if(works(mid)){ 
    //         start = mid;
    //     }else{ 
    //         end = mid-1;
    //     }
    // }
    // cout << start << endl;
    // for(int i = 0; i < n; i++){ 
    //     cout << bucket[i] << " ";
    // }
    // cout << endl;
    // int res = 0;
    // for(int i = 0 ; i < n; i++){ 
    //     if(bucket[i] >= i+1){ 
    //         res++;
    //     }else{ 
    //         break;
    //     }
    // }
    // cout << res << endl;


    



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
