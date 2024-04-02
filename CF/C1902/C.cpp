// #include<bits/stdc++.h>
// // g++-12 -o main [file].cpp;
// //./main < input.txt > output.txt
// using namespace std;

// #pragma region
// #define ll long long
// template<typename T>
// void print(T v[], int n){
//     for(int i =0 ; i < n; ++i){ 
//         cout << v[i] << " ";
//     }
//     cout << endl;
// }
// void print1(int v[], int n){
//     for(int i =1 ; i <= n; ++i){ 
//         cout << v[i] << " ";
//     }
//     cout << endl;
// }

// template<typename T>
// void print(vector<T> v){
//     for(int i =0 ; i < v.size(); ++i){ 
//         cout << v[i] << " ";
//     }
//     cout << endl;
// }
// #pragma endregion

// ll a[2'00'000];
// bool filled[2'00'002];
// int solve(){
//     ll n; 
//     cin >> n; 
//     for(int i =0;i < n; i++){ 
//         cin >> a[i];
//     }
//     if(n == 1){ 
//         cout << 1 << endl;
//         return 0;
//     }
//     ll m = *max_element(a,a+n);
//     vector<ll> diff;
//     ll largest = 0;
//     for(int i =0; i < n; i++){ 
//         diff.push_back(m-a[i]);
//         largest = max(diff[i], largest);
//     }
//     ll best = gcd(diff[0], diff[1]);
//     for(int i =2; i < n; i++){ 
//         best = gcd(best, diff[i]);
//     }
//     ll res = 0;
//     memset(filled, 0, n+1);
//     for(int i =0; i < n; i++){ 
//         ll count = diff[i]/best;
//         res += diff[i]/best;
//         if(count < n)
//             filled[count] = true;
//     }
//     // cout << "best: " << best << endl;
//     ll i = 1;
//     for(; i <= n; i++){ 
//         if(filled[i] == false){ 
//             res += i;
//             break;
//         }
//     }

//     cout << res << endl;
//     return 0;
    
// }

// int main(){
//     ios::sync_with_stdio(false); 
//     cin.tie(nullptr);
//     int t; 
//     cin >> t; 
//     while(t--){
        
//         solve();
//     }

// }
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

ll a[2'00'000];
bool filled[2'00'002];
int solve(){
    ll n; 
    cin >> n; 
    for(int i =0;i < n; i++){ 
        cin >> a[i];
    }
    if(n == 1){ 
        cout << 1 << endl;
        return 0;
    }
    ll m = *max_element(a,a+n);
    vector<ll> diff;
    ll largest = 0;
    for(int i =0; i < n; i++){ 
        diff.push_back(m-a[i]);
        largest = max(diff[i], largest);
    }
    ll best = 0;
    for(ll i = 1; i*i <= largest; i++){ 
        bool worked1 = true;
        bool worked2 = true;
        ll comp = largest/i;
        for(int j = 0; j < n; j++){ 
            if(diff[j]%i){
                worked1 = false;
            }  
            if(diff[j]%comp){
                worked2 = false;
            }

            if(worked1 == false && worked2 == false) break;
        }
        if(worked2) best = max(best, comp);
        if(worked1) best = max(best, i);
    }
    ll res = 0;
    memset(filled, 0, sizeof(filled));
    for(int i =0; i < n; i++){ 
        ll count = diff[i]/best;
        res += diff[i]/best;
        if(count < n)
            filled[count] = true;
    }
    // cout << "best: " << best << endl;
    ll i = 1;
    for(; i <= n; i++){ 
        if(filled[i] == false){ 
            res += i;
            break;
        }
    }

    cout << res << endl;
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
